module ColourExtensions =
    open System
    open System.Drawing
    open System.Text.RegularExpressions

    // parse ARGB from hex string with RegEx
    let private hexPattern: Regex =
        Regex("^#(?<colour>[\\dA-F]{8})$", RegexOptions.IgnoreCase ||| RegexOptions.Compiled )

    // type extension
    type Color with
        // static extension method
        static member FromHex(hex: string) =
            match hexPattern.Match hex with
            | (matches: Match) when matches.Success ->
                Color.FromArgb <| Convert.ToInt32(matches.Groups.["colour"].Value, 16)
            | _ -> Color.Empty
        member x.ToHex() = sprintf "#%02x%02x%02x%02x" x.A x.R x.G x.B

    let c: Color = Color.FromHex("#ff4A6167")
    printfn $"{c}"
