package main

import (
	"fmt"
	"os"
)

func main() {
	word := os.Args[1]

	// default behaviour is to not fallthrough
	// need to use fallthrough explicitly to do so
	// can also declare variables for the switch scope
	// can also use boolean expression
	switch l := len(word); word {
	case "hi":
		fmt.Println("hi :D")
		fallthrough
	case "hello":
		fmt.Println("Hi")
	case "goodbye", "bye": // multiple matches in the same case
		fmt.Println("So long")
	case "greetings":
		fmt.Println("Salutations")
	default:
		fmt.Println("Thats", l, "chars long")
	}
}
