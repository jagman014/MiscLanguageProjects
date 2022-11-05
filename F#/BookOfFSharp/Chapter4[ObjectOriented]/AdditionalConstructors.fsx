// constructors defined beyond the primary constructor
type Person (name: string, age: int) =
    do printfn $"Creatring person: {name} (Age: {age})"
    // additional constructors, can execute code local to them using "then"
    new (name: string) = Person (name, 0)
                         then printfn "Creating person with default age"
    new () = Person ("")
             then printfn "Creating person with default name and age"
    member x.Name = name
    member x.Age = age

// defining without a primary constructor, need to define fields with val
// any additional constructors must initialise any non-default value fields
type Person1 =
    val _name: string
    val _age: int
    new (name: string, age: int) = {_name = name; _age = age}
    new (name: string) = Person1 (name, 0)
    new () = Person1 ("")
    member x.Name = x._name
    member x.Age = x._age
