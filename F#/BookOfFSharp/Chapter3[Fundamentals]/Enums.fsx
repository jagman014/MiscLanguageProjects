// assign ints to named values
// unlike c++ or c# need to fill all values
type GiornoDellaSettimana =
| Lunedi = 0y
| Martedi = 1y
| Mercoledi = 2y
| Giovedi = 3y
| Venerdi = 4y
| Sabato = 5y
| Domenica = 6y

// use of [<Flags>] decoration as a bit mask
open System

[<FlagsAttribute>]
type DayOfWeek =
| None = 0          // 00000000
| Sunday = 1        // 00000001
| Monday = 2        // 00000010
| Tuesday = 4       // 00000100
| Wednesday = 8     // 00001000
| Thursday = 16     // 00010000
| Friday = 32       // 00100000
| Saturday = 64     // 01000000
| WeekDays = 62     // 00111110 add commonly added values
| WeekendDays = 65  // 01000001

// can then combine values using bitwise logic
let weekend: DayOfWeek = DayOfWeek.Sunday ||| DayOfWeek.Saturday

// can reconstruct using enum keyword
let day: DayOfWeek = enum<DayOfWeek> 16

// if underlying type is not int32 use EnumOfValue
open Microsoft.FSharp.Core.LanguagePrimitives

let giorno: GiornoDellaSettimana = EnumOfValue<sbyte, GiornoDellaSettimana> 0y
