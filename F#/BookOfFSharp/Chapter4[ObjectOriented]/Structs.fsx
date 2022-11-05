// Structs are value type instead of reference types like classes
// need to be decorated with [<Struct>]
[<Struct>]
type Circle(diameter: float) =
    member x.getRadius(): float = diameter / 2.0
    member x.Diameter: float = diameter
    member x.GetArea(): float = System.Math.PI * (x.getRadius() ** 2.0)

// value types always result in a new allocation with the data when accessed
// reference types are allocated once then accessed via a reference to memory
