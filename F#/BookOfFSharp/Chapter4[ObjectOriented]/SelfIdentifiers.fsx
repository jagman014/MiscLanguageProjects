// cant reference class members by default, need to use "as" keyword
type Person (name: string, age: int) as this =
    do printfn $"Creating person: {this.Name} (Age: {this.Age})"
    member x.Name = name
    member x.Age = age

// identifier can have any name that follows the standard name rule
type Person1 (name: string, age: int) as ``A terrible identifier name`` =
    do
        printfn "Creating person: %s (Age: %i)"
                ``A terrible identifier name``.Name
                ``A terrible identifier name``.Age
    member x.Name = name
    member x.Age = age

// use of a self-idenitifer results in recursive referencing and performance loss
// best to only use for primary constructors, and only when necessary
