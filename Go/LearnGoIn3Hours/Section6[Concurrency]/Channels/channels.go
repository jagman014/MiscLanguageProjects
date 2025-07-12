package main

import "fmt"

// channels allow for transfering data between goroutines
// channel read and writes are synchronous
// zero for channels is nil

/* |		| unbuffered		| buffered				| nil	| closed								|
 * | read	| pause until write	| pause if empty		| hang	| return immediately with zero-value	|
 * | write	| pause until read	| pause only if full	| hang	| panic									|
 * | close	| works				| works					| panic	| panic									|
 */

func main() {
	in := make(chan string)
	out := make(chan string)

	go func() {
		name := <-in
		out <- fmt.Sprintf("Hello, " + name)
	}()

	in <- "Bob"
	// closing a channel prevents additional reads
	close(in)

	message := <-out
	fmt.Println(message)

	out1 := make(chan int, 10)
	for i := range 10 {
		go func(localI int) {
			out1 <- localI * 2
		}(i)
	}

	var result []int
	for i := 0; i < 10; i++ {
		val := <-out1
		result = append(result, val)
	}

	fmt.Println(result)

	in1 := make(chan int, 10)
	out2 := make(chan int)

	for i := range 10 {
		in1 <- i
	}
	// cannot write to or close a closed channel
	close(in1)

	go func() {
		for {
			i, ok := <-in1

			if !ok {
				close(out2)
				break
			}

			out2 <- i * 2
		}
	}()

	for v := range out2 {
		fmt.Println(v)
	}
}
