type WorkItem(summary: string, desc: string) =
    member val Summary: string = summary
    member val Description: string = desc

// System.Object contains the ToString method, good debugging tool
// defaults to printing class type name
let w: WorkItem = WorkItem("Take out the trash", "It's overflowing")
printfn $"{w.ToString()}"

// can override using the "override" keyword
type WorkItem1(summary: string, desc: string) =
    // need to explicitly inherit to use base keyword
    inherit System.Object()
    member val Summary: string = summary
    member val Description: string = desc
    override x.ToString(): string = sprintf $"[{base.ToString()}] {x.Summary}"

let w1: WorkItem1 = WorkItem1("Take out the trash", "It's overflowing")
printfn $"{w1.ToString()}"

// can only override a given function once per type,
// but can override again later down the inheritance chain
type Defect(summary: string, desc: string, severity: int) =
    inherit WorkItem1(summary, desc)
    member val Severity: int = severity
    // base self identifier to relate back to base class
    override x.ToString(): string = sprintf $"{base.ToString()} ({x.Severity})"

let d: Defect = Defect("Wibbly", "Wobbly", 2)
printfn $"{d.ToString()}"
