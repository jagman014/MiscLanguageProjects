package main

import "fmt"

func main() {
	// arrays are a fixed size of a single type
	// size is part of the arrays size
	var vals [3]int
	vals[0] = 2
	vals[1] = 4
	vals[2] = 6

	fmt.Println(vals, vals[0], vals[1], vals[2])
}
