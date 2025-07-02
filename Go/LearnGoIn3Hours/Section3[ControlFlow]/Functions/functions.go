package main

import "fmt"

// create functions as expected
// can create functions after main as well
// no function overloading
// no named or default params
// func name(params) return types
func addNumbers(a int, b int) int {
	return a + b
}

func divAndRemainder(a int, b int) (int, int) {
	return a / b, a % b
}

// all functions are call by value
func doubleFail(a int, arr [2]int, s string) {
	a *= 2
	for i := range len(arr) {
		arr[i] *= 2
	}
	s += s

	fmt.Println("in doubleFail", a, arr, s)
}

func main() {
	a := addNumbers(2, 3)
	fmt.Println(a)

	b, c := divAndRemainder(2, 3)
	fmt.Println(b, c)

	d := 1
	arr := [2]int{2, 4}
	s := "hello"

	doubleFail(d, arr, s)
	fmt.Println("in main:", d, arr, s)
}
