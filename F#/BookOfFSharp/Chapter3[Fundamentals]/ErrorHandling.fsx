// try..with or try..finally block
// used for error handling

// try..with if an exception in the try block, the with block will be ran
open System
open System.IO

try
    use file: StreamReader = File.OpenText "somefile.txt"
    file.ReadToEnd() |> printfn "%s"
with
    | :? FileNotFoundException as ex -> printfn "%s not found" ex.FileName // type test pattern
    | :? PathTooLongException // pattern match fall through to || errors
    | :? ArgumentNullException
    | :? ArgumentException -> printfn "Invalid filename"
    | _ -> printfn "Error loading file" // wildcard pattern
           reraise() // raise exception and keep stack trace

// all exceptions must have the same return type as the try block
// common practice is to return Some<_> with exceptions returning None
let fileContents: string option =
    try
        use file: StreamReader = File.OpenText "somefile.txt"
        Some <| file.ReadToEnd()
    with
        | :? FileNotFoundException as ex -> printfn "%s not found" ex.FileName
                                            None
        | _ -> printfn "Error loading file"
               reraise()

// try..finally
// run code regardless of exception
try
    use file: StreamReader = File.OpenText "somefile.txt"
    Some <| file.ReadToEnd()
finally
    printfn "cleaning up"

// rasining exceptions
let filename: string = "x"

if not (File.Exists filename) then
    raise <| FileNotFoundException("filename was null or empty")

// failwith
if not (File.Exists filename) then
    failwith "File not found"

// failwithf
if not (File.Exists filename) then
    failwithf "%s could not be found" filename

// invalidArg to raise System.ArgumentException
if not (String.IsNullOrEmpty filename) then
    invalidArg "filename" (sprintf "%s is not a valid file name" filename)

// custom exceptions
// extend System.Extension
type MyException(message: string, category: string) =
    inherit exn(message)
    member x.Category = category
    override x.ToString() = sprintf "[%s] %s" category message

try
    raise <| MyException("blah", "Debug")
with
    | :? MyException as ex -> printfn "My exception: %s" <| ex.ToString()
    | _ as ex -> printfn "General Exception: %s" <| ex.ToString() 

// alternate lightweight
exception RetryAttemptFailed of string * int
exception RetryCountExceeded of string

let retry (maxTries: int) action =
    let rec retryInternal (attempt: int) =
        try
            if not (action()) then
                raise <| if attempt > maxTries then
                            RetryCountExceeded("Maxium attempts exceeded")
                         else
                            RetryAttemptFailed(sprintf "Attempt %i failed" attempt, attempt)
        with
        | RetryAttemptFailed(msg: string, count: int) as ex -> Console.WriteLine(msg)
                                                               retryInternal (count + 1)
        | RetryCountExceeded(msg: string) -> Console.WriteLine(msg)
                                             reraise()
    retryInternal 1

retry 5 (fun () -> false)
