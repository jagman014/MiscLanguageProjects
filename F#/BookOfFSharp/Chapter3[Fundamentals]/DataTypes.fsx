// core data types

// bools
// includes not, ||, &&
let t: bool = true
let f: bool = false

// numerics
(*
    int(16, 32, 64), 
    uint(16, 32, 64), 
    float, 
    double, 
    bigint
*)
let i16: int16 = 1s
let ui16: uint16 = 2us
let i: int = 3
let u: uint = 4u
let i64: int64 = 5L
let ui64: uint64 = 6UL
let f32: float32 = 7.0f
let d: double = 8.0
let bi: bigint = 9I

// standard operators
(*
    + add / positive,
    - subtract / negative,
    * multiply,
    / divide,
    % modulo,
    ** exponent
*)

// comparitors
(*
    = equality,
    > greater than,
    < less than,
    >= greater than or equal,
    <= less than or equal,
    <> not equal
*)

// best to use thresholds for float comparisons
open System;

let approximatelyEqual (x: float) (y: float) (threshold: float) =
    Math.Abs(x - y) <= Math.Abs(threshold)

approximatelyEqual 0.33333 (1.0 / 3.0) 0.0001

// bitwise operators, only work with int types
(*
    &&& AND,
    ||| OR,
    ^^^ XOR,
    ~~~ NOT,
    <<< left shift,
    >>> right shift
*)

// type conversions
// use data type name
let highTemps: list<float> = [
    33.0; 30.0; 33.0; 38.0; 36.0; 31.0; 35.0;
    42.0; 53.0; 65.0; 59.0; 42.0; 31.0; 41.0;
    49.0; 45.0; 37.0; 42.0; 40.0; 32.0; 33.0;
    42.0; 48.0; 36.0; 34.0; 38.0; 41.0; 46.0;
    54.0; 57.0; 59.0
]

let totalHighTemps: float = List.sum highTemps
let average: float = totalHighTemps / float highTemps.Length

// Chars and Strings
// chars in ''
// strings in "", can be multiline
// raw strings @"" ignores escapes
// triplequote """""" same as raw also ignores ""
let c: char = 'a'
let s: string = "hello"
let rs: string = @"\ ""quote""" // -> \ "quote"
let tq: string = """<something "special">"""

// string concat
let stringConcat1: string = System.String.Concat("abc", "def")
let stringConcat2: string = "abc" + "def" // can use ^ but is for ML compatibility
