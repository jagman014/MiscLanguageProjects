// Package leftpad contains functions to left-pad strings with either spaces
// or a given rune
package leftpad

import (
	"strings"
	"unicode/utf8"
)

// vars or functions beginning with a lower case letter are private
// those beginning with an upper case letter are public
var defaultChar = ' '

// Format takes in a string and an int, and returns the string
// left-padded with spaces to the length of the int. If the string
// is already longer than the specifed length, the original string
// is returned
func Format(s string, size int) string {
	return FormatRune(s, size, defaultChar)
}

// FormatRune takes in a string, an int, and a rune, and returns the string
// left-padded with the specifed rune to the length of the int. If the string
// is already longer than the specifed length, the orginal
// string is returned
func FormatRune(s string, size int, r rune) string {
	l := utf8.RuneCountInString(s)

	if l >= size {
		return s
	}

	out := strings.Repeat(string(r), size-l) + s
	return out
}
