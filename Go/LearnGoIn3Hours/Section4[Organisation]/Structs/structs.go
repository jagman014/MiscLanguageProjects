package main

import (
	"encoding/json"
	"fmt"
)

type Foo struct {
	A int
	b string
}

type Bar struct {
	C string
	F Foo
}

type Baz struct {
	D string
	Foo
	// embedded struct inside Baz
}

type Person struct {
	Name string `json:"name"` // struct tags
	Age  int    `json:"age"`
}

func main() {
	f := Foo{}
	fmt.Println(f)

	g := Foo{10, "Hello"}
	fmt.Println(g)

	h := Foo{
		b: "Goodbye",
	}
	fmt.Println(h)

	h.A = 1000
	fmt.Println(h.A)

	f1 := Foo{
		A: 20,
	}

	f2 := f1
	f2.A = 100
	fmt.Println(f2.A)
	fmt.Println(f1.A)

	f3 := &f1
	f3.A = 200
	fmt.Println(f3.A)
	fmt.Println(f1.A)

	b1 := Bar{C: "Fred", F: g}
	fmt.Println(b1.F.A)

	// embedded struct allows for shared members
	b2 := Baz{D: "Nancy", Foo: g}
	fmt.Println(b2.A)

	bob := `{ "name": "Bob", "age": 30 }`
	var b Person

	json.Unmarshal([]byte(bob), &b)
	fmt.Println(b)

	bob2, _ := json.Marshal(b)
	fmt.Println(string(bob2))
}
