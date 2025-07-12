package main

import "fmt"

// interfaces declare a set of functions but no implementation
// like a c++ template

type tester interface {
	test(int) bool
}

func runTests(i int, tests []tester) bool {
	result := true

	for _, test := range tests {
		result = result && test.test(i)
	}

	return result
}

type rangeTest struct {
	min int
	max int
}

func (rt rangeTest) test(i int) bool {
	return rt.min <= i && i <= rt.max
}

type divTest int

func (dt divTest) test(i int) bool {
	return i%int(dt) == 0
}

type testerFunc func(int) bool

func (tf testerFunc) test(i int) bool {
	return tf(i)
}

func doStuff(i any) {
	switch i := i.(type) {
	case int:
		fmt.Println("Double i is:", i+i)
	case string:
		fmt.Println("i is", len(i), "characters long")
	default:
		fmt.Println("I don't know what to do")
	}
}

func main() {
	result := runTests(
		10,
		[]tester{
			rangeTest{min: 5, max: 20},
			divTest(5),
			testerFunc(func(i int) bool {
				return i%2 == 0
			}),
			testerFunc(func(i int) bool {
				return i < 20
			}),
		},
	)

	fmt.Println(result)

	// empty interfaces
	var i interface{}
	i = "Hello"
	j := i.(string)
	// type assertion, save version
	k, ok := i.(int)

	fmt.Println(j, k, ok)

	// invalid type assertion
	// m := i.(int)
	// fmt.Println(m)

	doStuff(10)
	doStuff("Hello")
	doStuff(true)
}
