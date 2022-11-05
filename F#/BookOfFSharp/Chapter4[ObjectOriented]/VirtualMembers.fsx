// create virtual member by defining an abstract member with a default implementation
open System
open System.Collections.Generic
open System.Collections.ObjectModel

type Node(name: string) =
    let children: List<Node> = List<Node>()
    member x.Children with get(): ReadOnlyCollection<Node> = children.AsReadOnly()
    abstract member AddChild: Node -> unit
    abstract member RemoveChild: Node -> unit
    default x.AddChild(n: Node) = children.Add n
    default x.RemoveChild(n: Node) = children.Remove n |> ignore

// can overrride virtual functions
type TerminalNode(name: string) =
    inherit Node(name)
    [<Literal>]
    let notSupportedMsg: string = "Cannot add or remove children"
    override x.AddChild(n: Node): unit =
        raise (NotSupportedException(notSupportedMsg))
    override x.RemoveChild(n: Node): unit =
        raise (NotSupportedException(notSupportedMsg))
