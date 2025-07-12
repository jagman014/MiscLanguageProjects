package main

import "fmt"

func main() {
	a := 10

	// values are not truthy, only bools are
	// can declare variables in the if statement that will be available for all branches
	if b := a / 2; b > 5 {
		fmt.Println("b is bigger than 5")
	} else {
		fmt.Println("b is less than or equal to 5")
	}
}
