package main

import (
	"fmt"
)

func main() {
	// create a slice with the make() func
	// array type, size
	s := make([]string, 0)
	fmt.Println("length of s:", len(s))

	s = append(s, "hello")
	fmt.Println("length of s:", len(s))
	fmt.Println("contents of s[0]:", s[0])

	s[0] = "goodbye"
	fmt.Println("contents of s[0]:", s[0])

	s2 := make([]string, 2)
	fmt.Println("contents of s2[0]:", s2[0])

	s2 = append(s2, "hello")
	fmt.Println("contents of s2[0]:", s2[0])
	fmt.Println("contents of s2[2]:", s2[2])
	fmt.Println("length of s2:", len(s2))

	s3 := []string{"a", "b", "c"}

	// index, value
	for k, v := range s3 {
		fmt.Println(k, v)
	}

	// copy reference not value
	// "slice of a slice"
	s4 := s3[0:2]
	fmt.Println("s4:", s4)

	// modifying base modifies copy
	s3[0] = "d"
	fmt.Println("s4:", s4)

	// modifying the copy modifies the base
	s5 := s3
	s5[1] = "camel"
	fmt.Println("s3:", s3)

	modSlice(s3)
	fmt.Println("s3[0]", s3[0])

	uniHello := "👋 🌍"
	// these are copies of values not references
	bytes := []byte(uniHello)
	fmt.Println(bytes)

	runes := []rune(uniHello)
	fmt.Println(runes)

	runes[1] = 'a'
	fmt.Println(runes)
	fmt.Println(uniHello)

	// Maps similar to hashmaps
	// keys must be a hashable type
	m := make(map[string]int)
	m["hello"] = 300
	h := m["hello"]
	fmt.Println("hello in m:", h)
	// all non-defined keys give 0 value
	fmt.Println("a in m:", m["a"])

	// check if key is in map
	if v, ok := m["hello"]; ok {
		fmt.Println("hello in m:", v)
	}

	m["hello"] = 20
	fmt.Println("hello in m:", m["hello"])

	m2 := map[string]int{
		"a": 1,
		"b": 2,
		"c": 50,
	}

	// key, value
	// values in map are not always in the same order
	for k, v := range m2 {
		fmt.Println(k, v)
	}

	fmt.Println("b in m2:", m2["b"])
	delete(m2, "b")
	fmt.Println("b in m2:", m2["b"])

	m3 := map[string]int{
		"a": 1,
		"b": 2,
	}
	var m4 map[string]int

	fmt.Println("goodbye in m3:", m3["goodbye"])

	m4 = m3
	m4["goodbye"] = 400
	fmt.Println("goodbye in m4:", m4["goodbye"])
	fmt.Println("goodbye in m3:", m3["goodbye"])

	modMap(m3)
	fmt.Println("cheese in m3:", m3["cheese"])

	// cannot write to a nil map
}

// functions with slices are pass by reference
func modSlice(s []string) {
	s[0] = "hello"
}

// maps are also reference types like slices
func modMap(m map[string]int) {
	m["cheese"] = 20
}
