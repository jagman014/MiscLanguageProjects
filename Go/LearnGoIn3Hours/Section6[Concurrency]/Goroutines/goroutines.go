package main

import (
	"fmt"
	"sync"
)

func runMe(name string) {
	fmt.Println("Hello to", name, "from a goroutine")
}

// goroutines are similar to async
// allowing for concurrency

func main() {
	// call function with go to use goroutines
	var wg sync.WaitGroup
	wg.Add(1) // added n goroutines to the WaitGroup

	go func(name string) {
		runMe(name)
		wg.Done()
	}("Bob")

	wg.Wait()

	var wg1 sync.WaitGroup
	for i := range 10 {
		wg1.Add(1)
		go func(localI int) {
			fmt.Println(i)
			wg1.Done()
		}(i)
	}

	wg1.Wait()
}
