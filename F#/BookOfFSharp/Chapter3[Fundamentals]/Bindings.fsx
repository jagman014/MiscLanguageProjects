// typings hints added by intellisense

// let bindings, immutable
// associate names and values
let intValue: int = 1
let strValue: string = "Hello"

// can be used to identify function or expressions
let add (a: int) (b: int) = a + b
let sum: int = add 1 2

// literal bindings
// uses literal attribute decorator, makes read only consts
[<Literal>] // Attribute suffix is optional
let celciusBoilingPoint: int = 100

// mutable bindings
// can change value at will
let mutable name: string = "Dave"
name <- "Jim"

// reference cells
// mutable, can be captureed by functions
let cell: int ref = ref 0

// special syntax for chaning value and referencing it
// cell := val depricated use cell.Value <- val
cell.Value <- 100
// !cell depricated use cell.Value
printfn "%i" cell.Value

// use bindings
// similar to c# using

// example disposable object
open System;

let createDisposable (name: string) =
    printfn "creating: %s" name
    {
        new IDisposable with
        member x.Dispose() =
            printfn "disposing: %s" name
    }

// invokes disposable function inside and outside a for loop
let testDisposable() =
    use root: IDisposable = createDisposable "outer"
    for i: int in [1..2] do
        use nested: IDisposable = createDisposable (sprintf "inner %i" i)
        printfn "completing iteration %i" i
    printfn "leaving function"

testDisposable()

// another example with file IO
open System.IO;

let writeToFile (filename:string) (buffer: byte[]) =
    use fs: FileStream = new FileStream(filename, FileMode.Create, FileAccess.Write)
    fs.Write(buffer, 0, buffer.Length)

let buffer: byte[] = System.Text.Encoding.ASCII.GetBytes("Test\n")

writeToFile "TestText.txt" buffer

// using function
// more like c# using, does return and object
open System.Drawing

let (w: int), (h: int) = using (Image.FromFile(@"C:\Windows\Web\Screen\img100.jpg"))
                                (fun (img: Image) -> (img.Width, img.Height))
printfn "Dimensions: %i x %i" w h
