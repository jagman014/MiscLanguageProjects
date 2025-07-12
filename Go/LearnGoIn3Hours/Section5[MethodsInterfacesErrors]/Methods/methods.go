package main

import "fmt"

type Foo struct {
	A int
	B string
}

func (f Foo) fieldCount() int {
	return 2
}

func (f Foo) String() string {
	// struct method uses the (f Foo) as the equivilent of "this"
	return fmt.Sprintf("%d fields: A: %d and B: %s", f.fieldCount(), f.A, f.B)
}

func (f *Foo) Double() {
	f.A *= 2
}

type Bar struct {
	C bool
	Foo
}

func (b Bar) String() string {
	return fmt.Sprintf("%s and C: %v", b.Foo.String(), b.C)
}

func (b Bar) fieldCount() int {
	// no inheritence in go
	return 3
}

// can also decalre methods on own types
type myInt int

func (mi myInt) isEven() bool {
	return mi%2 == 0
}

func (mi *myInt) Double() {
	*mi *= 2
}

func main() {
	f := Foo{
		A: 10,
		B: "Hello",
	}

	fmt.Println(f.String())

	f.Double()
	fmt.Println(f.String())

	b := Bar{
		C:   true,
		Foo: f,
	}

	fmt.Println(b.String())

	b.Double()
	fmt.Println(b.String())

	m := myInt(10)
	fmt.Println(m)
	fmt.Println(m.isEven())

	m.Double()
	fmt.Println(m)
}
