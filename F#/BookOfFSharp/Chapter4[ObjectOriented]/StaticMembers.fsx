// require primary constructor for static initialisers
type ClassWithStaticConstructor() =
    static let mutable staticField: int = 0
    static do printfn "Invoking static initaliser"
              staticField <- 10
    do printfn $"Static Field value: {staticField}"

module Logger =
    let private log (logType: string) (category: string) (message: string) = printfn "%-5s [%s] %s" logType category message
    let LogInfo = log "INFO"
    let LogError = log "Error"

// static fields associate data with the class instead of an instance
type MyService() =
    static let logCategory: string = "MyService"
    member x.DoSomething() =
        Logger.LogInfo logCategory "Doing Something"
    member x.DoSomethingElse() =
        Logger.LogError logCategory "Doing Something Else"

let svc: MyService = MyService()
svc.DoSomething()
svc.DoSomethingElse()

// static processes assosiated with class
type Processor() =
    static let mutable itemsProcessed: int = 0
    static member ItemsProcessed = itemsProcessed
    member x.Process() =
        itemsProcessed <- itemsProcessed + 1
        printfn "Processing..."

while Processor.ItemsProcessed < 5 do (Processor()).Process()

// static methods, apply to a type. used for factory patterns
[<AbstractClass>]
type ImageReader() =
    abstract member Dimensions: int * int with get
    abstract member Resolution: int * int with get
    abstract member Content: byte array with get

type JpgImageReader(filename: string) =
    inherit ImageReader()
    //...

type GifImageReader(filename: string) =
    inherit ImageReader()
    //...

type PngImageReader(filename: string) =
    inherit ImageReader()
    //...

open System.IO

[<Sealed>]
type ImageReaderFactory private() =
    static member CreateReader(filename: string) =
        let fi: FileInfo = FileInfo(filename)

        match fi.Extension.ToUpper() with
        | ".JPG" -> JpgImageReader(filename) :> ImageReader
        | ".GIF" -> GifImageReader(filename) :> ImageReader
        | ".PNG" -> PngImageReader(filename) :> ImageReader
        | (ext: string) -> failwith (sprintf $"Unsupported extention: {ext}")
