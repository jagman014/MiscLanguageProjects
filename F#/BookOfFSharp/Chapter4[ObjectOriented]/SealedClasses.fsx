// sealed classes cannot be inherited, i.e. System.String
[<Sealed>]
type NotInheritable() = class end

// trying to inherit with raise an error
type InvalidClass() =
    inherit NotInheritable()
