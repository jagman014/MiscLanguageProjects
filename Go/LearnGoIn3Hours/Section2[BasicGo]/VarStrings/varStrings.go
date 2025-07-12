package main

import "fmt"

func main() {
	// string literal
	// uses standard escape characters
	s := "Hello, \nWorld!"
	fmt.Println(s)

	// raw string literal
	// can go over multiple lines
	s = `Hello, \nWorld!`
	fmt.Println(s)

	// strings are immutable sequences of bytes
	fmt.Println(s[0]+s[1], string(s[4]))

	// substrings similar to python
	// can omit starting and ending indicies
	fmt.Println(s[0:5])

	// len function to get lengths
	fmt.Println(len(s))

	// runes are numeric characters unit8
	var r rune = 127757
	fmt.Println(string(r))

	// run literal
	r1 := 'a'
	fmt.Println(r1)
}
