open System
open System.Collections.Generic // for Dictionary

// abstract classes cannot be directly instantiated
// typically define a common interface and optional implementation
[<AbstractClass>]
type Node(name: string, ?content: Node list) =
    member x.Name = name
    member x.Contnet = content

// abstract members are only allowed in abstract classes
// must be implemented in derived classes
[<AbstractClass>]
type AbstractBaseClass() =
    abstract member SomeData: string with get, set

type BindingBackedClass() =
    inherit AbstractBaseClass()
    let mutable someData: string = ""
    override x.SomeData
        with get() = someData
        and set(v: string) = someData <- v

type DictionaryBackedClass() =
    inherit AbstractBaseClass()
    let dict: Dictionary<string,string> = Dictionary<string, string>()
    [<Literal>]
    let SomeDataKey: string = "SomeData"
    override x.SomeData
        with get() =
            match dict.TryGetValue(SomeDataKey) with
            | true, (v: string) -> v
            | _, _ -> ""
        and set(v: string) =
            match System.String.IsNullOrEmpty(v) with
            | true when dict.ContainsKey(SomeDataKey) -> dict.Remove(SomeDataKey) |> ignore
            | _ -> dict.[SomeDataKey] <- v

// abstract methods share the same properties as abstract properties / members
[<AbstractClass>]
type Shape() =
    abstract member GetArea: unit -> float

type Circle(r: float) =
    inherit Shape()
    member val Radius: float = r
    override x.GetArea(): float =
        Math.Pow(Math.PI * r, 2.0)

type Rectangle(w: float, h: float) =
    inherit Shape()
    member val Width: float = w
    member val Height: float = h
    override x.GetArea(): float = w * h
