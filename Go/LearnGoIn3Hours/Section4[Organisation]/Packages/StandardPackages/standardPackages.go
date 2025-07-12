package main

// imports import all functions from a package
// standard library packages found at https://golang.org/pkg
import (
	"fmt"
	"math"
	"math/rand"
	"strings"
	"unicode/utf8"
)

func rot13(in rune) rune {
	if in >= 'A' && in <= 'Z' {
		return ((((in - 'A') + 13) % 26) + 'A')
	}
	if in >= 'a' && in <= 'z' {
		return ((((in - 'a') + 13) % 26) + 'a')
	}
	return in
}

func main() {
	// string library
	s := "This is a test 123 😃"
	s2 := strings.Map(rot13, s)
	fmt.Println(s2)
	s3 := strings.Map(rot13, s2)
	fmt.Println(s3)

	// unicode/utf8 library
	s4 := "👋 🌍"
	fmt.Println(s4)
	fmt.Println(len(s4))                    // len gets the number of bytes in a string
	fmt.Println(utf8.RuneCountInString(s4)) // need to use encoding package to get count of characters (runes)

	// math, math/rand libraries
	a := rand.Int31n(10)
	b := rand.Int31n(10)
	c := int(math.Max(float64(a), float64(b)))
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c, "is bigger")
}
