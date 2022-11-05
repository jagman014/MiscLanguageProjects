open System
open System.Drawing

type RgbColour(r: int, g: int, b: int) =
    member x.Red = r
    member x.Green = g
    member x.Blue = b
    override x.ToString() = sprintf $"({r}, {g}, {b})"

    // prefix operators must begin with "~"
    // negative of colour
    static member (~-) (r: RgbColour) =
        RgbColour(
            r.Red ^^^ 0xFF,
            r.Blue ^^^ 0xFF,
            r.Green ^^^ 0xFF
        )
    
    // infix operators are the same as prefix without the ~
    // add two colours
    static member (+) (l: RgbColour, r: RgbColour) =
        RgbColour(
            Math.Min(255, l.Red + r.Red),
            Math.Min(255, l.Green + r.Green),
            Math.Min(255, l.Blue + r.Blue)
        )
    
    // substract two colours
    static member (-) (l: RgbColour, r: RgbColour) =
        RgbColour(
            Math.Max(0, l.Red - r.Red),
            Math.Max(0, l.Green - r.Green),
            Math.Max(0, l.Blue - r.Blue)
        )
    
    // can create custom ops using any combination of !, %, &, *, +, -, ., /, <, =, >, ?, @, ^, |, ~
    // can reduce readibility
    // blend two colours
    static member (+=) (l: RgbColour, r: RgbColour) =
        RgbColour(
            (l.Red + r.Red) / 2,
            (l.Green + r.Green) / 2,
            (l.Blue + r.Blue) / 2
        )

let yellow: RgbColour = RgbColour(255, 255, 0)
let blue: RgbColour = -yellow

printfn $"yellow: {yellow}"
printfn $"blue: {blue}"

let red: RgbColour = RgbColour(255, 0, 0)
let green: RgbColour = RgbColour(0, 255, 0)
let yellow1: RgbColour = red + green

printfn $"red: {red}"
printfn $"green: {green}"
printfn $"red + green: {yellow1}"

let magenta: RgbColour = RgbColour(255, 0, 255)
let blue1: RgbColour = magenta - red

printfn $"magenta: {magenta}"
printfn $"magenta - red: {blue1}"

let grey: RgbColour = yellow += blue
printfn $"grey: {grey}"

// can also define global operators
// global ops take priority over inbuilt
let (+) (l: Color, r: Color) =
    Color.FromArgb(
        255, // alpha
        Math.Min(255, int <| l.R + r.R),
        Math.Min(255, int <| l.G + r.G),
        Math.Min(255, int <| l.B + r.B)
    )
