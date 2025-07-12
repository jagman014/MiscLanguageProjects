// package declaration
package main

// import from standard library
import (
	"fmt"
	"net/http"
)

// main func entrypoint
func main() {
	// using lambda function as second param
	http.HandleFunc("/hello", func(rw http.ResponseWriter, req *http.Request) {
		name := req.URL.Query().Get("name")
		rw.Write(fmt.Appendf([]byte(""), "Hello, %s", name))
	})

	http.ListenAndServe(":8080", nil)
}
