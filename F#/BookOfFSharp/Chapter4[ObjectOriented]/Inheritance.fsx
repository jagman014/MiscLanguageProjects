type BaseType() =
    member x.SayHello (name: string): unit = printfn $"Hello, {name}"

// inherit classes using the inherit keyword
// inheritance requires a primary constructor
type DerivedType() =
    // inherit line must be the first line before anything else
    inherit BaseType()

// base inherits from System.Object
type WorkItem(summary: string, desc: string) =
    member val Summary: string = summary
    member val Description: string = desc

type Defect(summary: string, desc: string, severity: int) =
    inherit WorkItem(summary, desc)
    member val Severity: int = severity

type Enhancement(summary: string, desc: string, requestedBy: string) =
    inherit WorkItem(summary, desc)
    member val RequestedBy: string = requestedBy
