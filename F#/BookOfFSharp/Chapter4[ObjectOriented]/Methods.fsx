open System
open System.Drawing

type Circle(diameter: float) =
    // define methods as function members, can also define accessability
    member private x.GetRadius(): float = diameter / 2.0
    member x.Diameter = diameter
    member x.GetArea(): float =
        Math.PI * (x.GetRadius() ** 2.0)

let c: Circle = Circle 5.0
printfn $"Circle(5.0) Area = {c.GetArea()}"

type ColorDistance() =
    // standard way of doing named arguments
    member x.GetEuclideanDistance(c1: Color, c2: Color): float =
        let getPointDistance (p1: byte) (p2: byte) = (float p1 - float p2) ** 2.0
        [getPointDistance c1.R c2.R
         getPointDistance c1.G c2.G
         getPointDistance c1.B c2.B] |> List.sum |> Math.Sqrt

let d: ColorDistance = ColorDistance()
printfn $"White to Black = {d.GetEuclideanDistance(Color.White, Color.Black)}"
printfn $"White to Snow = {d.GetEuclideanDistance(Color.White, Color.Snow)}"

// can overload methods as long as they have different argument names
type Repository() =
    member x.Commit(files: string list, desc: string, branch: string) =
        printfn $"Commited {List.length files} files ({desc}) to \"{branch}\""
    member x.Commit(files: string list, desc: string) =
        x.Commit(files, desc, "default")

// optional arguments defined with "?" do need to define defaultArg
type Repository1() =
    member x.Commit(files: string list, desc: string, ?branch: string) =
        let targetBranch: string = defaultArg branch "default"
        printfn $"Commited {List.length files} files ({desc}) to \"{targetBranch}\""

// slice expressions need to implement the GetSlice method
// boundary params are optional in slice expressions
type Sentence(initial: string) =
    let words: string[] = initial.Split " "
    let text: string = initial
    member x.GetSlice(lower: int option, upper: int option) =
        match defaultArg lower 0 with
        | (l: int) when l >= words.Length -> Array.empty<string>
        | (l: int) -> match defaultArg upper (words.Length - 1) with
                        | (u: int) when u >= words.Length -> words.[l..]
                        | (u: int) -> words.[l..u]
    // can overload for multidimensional arrays
    member x.GetSlice(lower1: int option, upper1: int option, lower2: int option, upper2: int option) =
        x.GetSlice(lower1, upper1)
        |> Array.map
            (fun (w: string) -> match defaultArg lower2 0 with
                                | (l: int) when l >= w.Length -> ""
                                | (l: int) -> match defaultArg upper2 (w.Length - 1) with
                                                | (u: int) when u >= w.Length -> w.[l..]
                                                | (u: int) -> w.[l..u])

let s: Sentence = Sentence "Don't forget to drink your Ovaltine"

for w: string in s.[1..3] do
    printf $"{w} "

printfn ""

for w: string in s.[..3] do
    printf $"{w} "

printfn ""

for w: string in s.[3..] do
    printf $"{w} "

printfn ""

for w: string in s.[1..4, ..1] do
    printf $"{w} "

printfn ""
