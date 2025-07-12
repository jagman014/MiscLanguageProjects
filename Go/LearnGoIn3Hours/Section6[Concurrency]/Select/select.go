package main

import (
	"fmt"
	"sync"
	"time"
)

func multiples(i int) (chan int, chan struct{}) {
	out := make(chan int)
	done := make(chan struct{})
	curVal := 0

	go func() {
		for {
			// done channel pattern
			select {
			case out <- curVal * i:
				curVal++
			case <-done:
				fmt.Println("goroutine shutting down")
				return
			}
		}
	}()
	return out, done
}

func main() {
	in := make(chan int)
	out := make(chan int, 1)

	out <- 1

	// select statement can be used to avoid deadlocks
	// if multiple cases are vaild it chooses at random
	select {
	case in <- 2:
		fmt.Println("wrote 2 to in")
	case v := <-out:
		fmt.Println("read", v, "from out")
	}

	in1 := make(chan int, 1)
	out1 := make(chan int, 1)

	out1 <- 1

	select {
	case in1 <- 2:
		fmt.Println("wrote 2 to in")
	case v := <-out1:
		fmt.Println("read", v, "from out")
	}

	in2 := make(chan int)
	out2 := make(chan int)

	// select statement can be used to avoid deadlocks
	// if multiple cases are vaild it chooses at random
	select {
	case in2 <- 2:
		fmt.Println("wrote 2 to in")
	case v := <-out2:
		fmt.Println("read", v, "from out")
	default:
		fmt.Println("nothing else works")
	}

	twosCh, done := multiples(2)
	for v := range twosCh {
		if v > 20 {
			break
		}

		fmt.Println(v)
	}
	close(done)

	in3 := make(chan int)
	in4 := make(chan int)

	var wg sync.WaitGroup
	wg.Add(3)

	go func() {
		for i := range 10 {
			in3 <- i
		}

		close(in3)
		wg.Done()
	}()

	go func() {
		for i := 100; i < 110; i++ {
			in4 <- i
		}

		close(in4)
		wg.Done()
	}()

	go func() {
		count := 0
		for count < 2 {
			select {
			case i, ok := <-in3:
				if !ok {
					count++
					in3 = nil
					continue
				}
				fmt.Println("from in3, result is", i*2)
			case i, ok := <-in4:
				if !ok {
					count++
					in4 = nil
					continue
				}
				fmt.Println("from in4, result is", i*2)
			}
		}

		wg.Done()
	}()

	wg.Wait()

	// using a worker pool to create a channel backpressure to prevent
	// creating too many goroutines
	workers := 10000
	pool := make(chan func(int) int, workers)

	for i := 0; i < workers; i++ {
		pool <- func(in int) int {
			time.Sleep(1 * time.Second)
			result := 2 * in
			return result
		}
	}

	var wg2 sync.WaitGroup
	count := 0
	totalStart := time.Now()

	for i := range 100000 {
		start := time.Now()

		select {
		case f := <-pool:
			fmt.Println("processing", i)
			count++
			wg2.Add(1)

			go func(in int) {
				out := f(in)
				fmt.Println("got", out, "for", in, "after", time.Since(start))
				pool <- f
				wg2.Done()
			}(i)
		default:
			fmt.Println("rejecting request", i, "too busy")
		}
	}

	wg2.Wait()
	fmt.Println("total processed:", count)
	fmt.Println("total time:", time.Since(totalStart))
}
