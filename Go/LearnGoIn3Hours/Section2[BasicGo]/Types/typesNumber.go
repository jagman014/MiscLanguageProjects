package main

import "fmt"

func main() {
	var i int8 = 20
	var f float32 = 5.6

	// require explicit casts for all mismatched types
	fmt.Println(float32(i) + f)
	fmt.Println(i + int8(f))

	/* byte -> uint8
	 * int -> int32 or int64
	 * uint -> uint32 or int64
	 */
}
