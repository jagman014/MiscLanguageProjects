type WorkItem(summary: string, desc: string) =
    member val Summary: string = summary
    member val Description: string = desc

type Defect(summary: string, desc: string, severity: int) =
    inherit WorkItem(summary, desc)
    member val Severity: int = severity

type Enhancement(summary: string, desc: string, requestedBy: string) =
    inherit WorkItem(summary, desc)
    member val RequestedBy: string = requestedBy


// upcasting, cast to objects higher in the inheritance chain
// static cast operator :>, resolves casts at compile time
let w: WorkItem = Defect("Incompatibility detected", "Delete", 1) :> WorkItem

// downcasting, cast to objects lower in inheritance chain
// dynamic cast operator :?>, resolves at run time
let d: Defect = w :?> Defect

// can result in InvalidCastException
// let e: Enhancement = w :?> Enhancement
