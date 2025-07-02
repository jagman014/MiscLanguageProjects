package main

import "fmt"

func addOne(a int) int {
	return a + 1
}

func addTwo(a int) int {
	return a + 2
}

// can have a function as a parameter
func printOperation(a int, f func(int) int) {
	fmt.Println(f(a))
}

// can return a function
func makeAdder(b int) func(int) int {
	return func(a int) int {
		return a + b
	}
}

func makeDoubler(f func(int) int) func(int) int {
	return func(a int) int {
		b := f(a)
		return b * 2
	}
}

func main() {
	// can assign a function to a variable
	myAddOne := addOne
	fmt.Println(addOne(1))
	fmt.Println(myAddOne(1))

	// can decalre a function inside other functions using lambdas
	addOne1 := func(a int) int {
		return a + 1
	}

	fmt.Println(addOne1(1))

	printOperation(1, addOne)
	printOperation(1, addTwo)

	// lambdas can modify variables
	b := 1

	addOne2 := func(a int) {
		b = a + b
	}

	addOne2(1)
	fmt.Println(b)

	addThree := makeAdder(3)
	fmt.Println(addThree(1))

	doubleAddOne := makeDoubler(addOne)
	fmt.Println(doubleAddOne(1))
}
