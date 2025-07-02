package main

import "fmt"

// can create call by refrerence functions
func setTo10(a *int) {
	*a = 10
}

func main() {
	a := 10
	b := &a // pointer to a
	c := a

	// *b is the dereferenced pointer of b
	fmt.Println(a, b, *b, c)

	a = 20
	fmt.Println(a, b, *b, c)

	*b = 30
	fmt.Println(a, b, *b, c)

	c = 40
	fmt.Println(a, b, *b, c)

	// zero value for pointer is nil, cannot read or write value of nil pointer
	var d *int
	fmt.Println(d)

	e := 20
	fmt.Println(e)

	setTo10(&e)
	fmt.Println(e)
}
