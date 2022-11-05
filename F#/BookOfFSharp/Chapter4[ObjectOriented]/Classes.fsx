open System // for Guid, DateTime

// declared using the type keyword
// define primary constructor with arguments
type Person (id: Guid, name: string, dob: DateTime) =
    // can embed members within the class definition
    let age: float = (System.DateTime.Now - dob).TotalDays / 365.245
    do printfn $"Creating person: {name} (Age: {age})"
    // define read-only members
    member x.Id = id
    member x.Name = name
    member x.Age = age

// classes do not need a constructor
// but F# doesn't generator a default one, cannot instantiate without members
type ConstructorlessClass = class end

// can instantiate a class like most objects
let me: Person = Person (Guid.NewGuid(), "Jag", DateTime(1998, 6, 22))

// can add access modifier, useful for singleton classes
type Greeter private () =
    static let _instance: Lazy<Greeter> = lazy (Greeter())
    static member Instance with get() = _instance.Force()
    member x.SayHello() = printfn "Hello"

Greeter.Instance.SayHello()
