// inline comments
(*
    Block Comments
*)
/// XML documnetation Comments, can be seen in intellisense hover
let exampleFunction() = ()

open System

/// <summary>
/// Given a radius, calculate the diameter, area, and circumference
/// of a circle
/// </summary>
/// <param name="radius">The circle's radius</param>
/// <returns>
/// a triple containing the diameter, area, and circumference
/// </returns>
let measureCircle (radius: float) =
    let diameter: float = radius * 2.0
    let area: float = Math.PI * (radius ** 2.0)
    let circumference: float = 2.0 * Math.PI * radius
    (diameter, area, circumference)

let (diameter: float), (area: float), (circumference: float) = measureCircle 10.0
