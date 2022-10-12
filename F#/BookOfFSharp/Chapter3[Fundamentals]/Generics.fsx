// generics allow for multiple types
// usually defined with '
// automatically generated by compiler
// can explicitly define them as well
let toTriple a b c = (a, b, c)
// val toTriple: a: 'a -> b: 'b -> c: 'c -> 'a * 'b * 'c

// constraints
// using when
// some are only for inline functions using ^ instead of '

// subtype constraints
// limit the accepted types
let myFunc (stream: 'T when 'T :> System.IO.Stream) = ()

// nullness
// limits to types where null is valid
let inline myFunc2 (a: ^T when ^T : null) = ()

// member
// specfic member signiture
// instance member
let inline myFunc3 (a: ^T when ^T: (member ReadLine: unit -> string)) = ()

// static member
let inline myFunc4 (a: ^T when ^T: (static member Parse: string -> ^T)) = ()

// default constructor
// ensure supplied type has a default constructor
let myFunc5 (stream: 'T when 'T: (new: unit -> 'T)) = ()

// value type
// limits to any .NET value type execpt System.Nullable<_>
let myFunc6 (stream: 'T when 'T: struct) = ()

// reference type
// ensure only .NET reference types
let myFunc7 (stream: 'T when 'T: not struct) = ()

// enum
// limits type to enums with specific underlying type
let myFunc8 (stream: 'T when 'T: enum<int32>) = ()

// delegate
// restricts to delegate types with specific args and return
open System

let myFunc9 (stream: 'T when 'T: delegate<obj * EventArgs, unit>) = ()

// unmanaged
// restrict to unmanaged types (i.e. primitive, enums)
let myFunc10 (stream: 'T when 'T: unmanaged) = ()

// equality
// restrict to types that support equality
let myFunc11 (stream: 'T when 'T: equality) = ()

// comparison
// requires implementation of System.IComparable, arrays, nativeint, and unativeint, and equality support
let myFunc12 (stream: 'T when 'T: comparison) = ()


// flexible types
// shortcut for subtype constraints
let myFunc13 (stream: #System.IO.Stream) = ()

// wildcard pattern
// _ generic type, but have compiler infer type
let printList (l: List<_>) = l |> List.iter (fun i -> (printfn "%O" i))

// statically resolved params
// force compile time resolution instead of runtime
let inline (!**) x = x ** 2.0
// val inline (!**): x: ^a -> ^a when ^a: (static member Pow: ^a * float -> ^a)