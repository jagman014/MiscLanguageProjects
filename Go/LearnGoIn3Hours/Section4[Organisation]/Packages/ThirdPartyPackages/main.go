package main

import (
	"ThirdPartyPackages/mapper"
	"fmt"
)

func main() {
	fmt.Println(mapper.Greet("Hi, what's new?"))
	fmt.Println(mapper.Greet("Comment allez vous?"))
	fmt.Println(mapper.Greet("Wie geht es Ihnen?"))
}
