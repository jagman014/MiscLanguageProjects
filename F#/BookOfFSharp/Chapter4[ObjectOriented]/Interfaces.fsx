// all interface implementations are explicit
open System

type MyDisposable() =
    interface IDisposable with
        member x.Dispose() = printfn "Disposing"

// need to explicitly cast to call the interface
let d: MyDisposable = new MyDisposable()
(d :> IDisposable).Dispose()

// infer a type with just abstract members as an interface
// without a primary constructor
open System.Drawing
open System.IO

type IImageAdapter =
    abstract member PixelDimensions: SizeF with get
    abstract member VirticalResolution: int with get
    abstract member HorizontalResolution: int with get
    abstract member GetRawData: unit -> Stream

type IMarker = interface end

type ITransparentImageAdapter =
    inherit IImageAdapter
    abstract member TransparentColour: Color with get, set
