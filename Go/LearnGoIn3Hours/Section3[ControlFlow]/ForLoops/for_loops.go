package main

import "fmt"

func main() {
	a := 3
	// for var; expr; inc/dec (e.g. i := start; i < end; i++)
	// or use of a range
	for i := range 10 {
		if i > 7 {
			// can use break to exit loop early
			break
		}

		if i == a {
			// can use continue to skip rest of the loop code
			continue
		}

		fmt.Println(i)
	}

	s := "Hello, world!"
	// for offset, value
	for k, v := range s {
		fmt.Println(k, v, string(v))
	}
}
