// null is sparsely used
// can have with option or Some, similar to c# <T>?
let MiddleName: string option = None
let MeddleName2: string option = Some("Alice")

// ? can also be used for optional
type Container() =
    member x.Fill (?stopAtPercent: float) =
        printfn "%s" <| match (defaultArg stopAtPercent 0.5) with
                        | 1.0 -> "Filled it up"
                        | (stopAt: float) -> sprintf "Filled to %s" (stopAt.ToString("P2"))

let bottle: Container = Container()
bottle.Fill()

// unit type
// similar to void
// can pipe unwanted return values into ignore
let add (a: int) (b: int) = a + b
add 1 2 |> ignore
