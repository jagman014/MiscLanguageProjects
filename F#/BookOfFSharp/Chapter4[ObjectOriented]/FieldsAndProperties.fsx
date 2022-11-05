// fields define the data elements

// properties offer more control over data access / modification
// properties are public by default, require member keyword

// let bindings, must be initialised in the primary constructor
// always private to the class
type Person () =
    // used to define the backing store for the explicit Name property
    let mutable name: string = ""
    member x.Name
        with get() = name // can define getters and setters separately if needed
        and set(v: string) = name <- v 

// explicit fields using val, public by default, can be made private
// don't need to be initalised immediately
// classes with primary constructors need DefaultValue attribute to ensure initalisation
type Person1 () =
    [<DefaultValue>] val mutable n: string // inits to null
    member x.Name
        with get() = x.n
        and set(v: string) = x.n <- v

// creating a property without a setter will be read-only, 
// preferable to use inital argument, getters are made by default
type Person2 (name: string) =
    member x.Name = name

// implicit properties, compiler generated backing store and getters / setters
// must appear with primary constructor before other properties
// must have a default value, and defined without self-identifier
// accessability can only be changed at the property level not accessor level
type Person3 () =
    member val Name = "" with get, set

// indexed properties, useful for array like interface
// default name "Item" enables .[] access
type Sentence (initial: string) =
    let mutable words: string[] = initial.Split ' '
    let mutable text: string = initial
    member x.Item
        with get(i: int): string = words.[i]
        and set (i: int) (v: string) = 
            words.[i] <- v
            text <- System.String.Join(" ", words)
    member x.Item // indexed properties can be multidimensional
        with get (i: int, j: int) = words.[i].[j]
    member x.Chars // non-default name needs to be used like a method
        with get(i: int) = text.[i]

// arrays are zero indexed
let s: Sentence = Sentence "Don't forget to drink your Ovaltine"
printfn $"{s.[1]}"
printfn $"{s.[1, 0]}"
printfn $"{s.Chars(0)}"

// can set an initalisation using explicit param calls
// any properties initialised this way must be writable
let p: Person3 = Person3(Name = "Alice")
