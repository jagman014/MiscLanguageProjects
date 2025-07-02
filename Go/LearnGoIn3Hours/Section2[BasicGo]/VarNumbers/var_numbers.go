package main

import "fmt"

func main() {
	// var <name> <type> = <val>
	// go has type inference as well
	// go can shorten with := to remove var keyword
	var i int // uninitialised variables are given their "0" equivilant
	fmt.Println(i)

	i = 20
	fmt.Println(i)

	// unused variables will result in a compilation error
}
