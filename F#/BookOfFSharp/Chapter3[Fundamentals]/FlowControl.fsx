// loops
// no mechenism for break or continue, need to be careful

// while loops
// while <condition> do
let echoUserInput (getInput: unit -> string) = 
    let mutable input: string = getInput()
    while not (input.ToUpper().Equals("QUIT")) do
        printfn "You entered %s" input
        input <- getInput()

// lambda function is annoying, 
// need the params to be exactly inline vertically with eachother
echoUserInput (
    fun () -> printfn "Type something and press enter (quit to exit)" 
              System.Console.ReadLine()
)

// for loops
// simple always us int and return unit
for i = 0 to 10 do
    printf "%i " i
printfn ""

for i = 10 downto 0 do
    printf "%i " i
printfn ""

// enumerable for loops, similar to c# foreach
for i: int in [0..10] do
    printf "%i " i
printfn ""

// union type
type BtfcRating =
| U
| PG
| TWELVE_A
| TWELVE
| FIFTEEN
| EIGHTEEN

// record type
type Movie = {Title: string; Year: int; Rating: BtfcRating option}

// list
let movies: Movie list = [
    {Title="The Last Witch Hunter"; Year=2014; Rating=None}
    {Title="Riddick"; Year=2013; Rating=Some(FIFTEEN)}
    {Title="Fast Five"; Year=2011; Rating=Some(TWELVE_A)}
    {Title="Babylon A.D."; Year=2008; Rating=Some(TWELVE_A)}
]

// for..in loop
for {Title=t: string; Year=y: int; Rating=Some(r: BtfcRating)} in movies do
    printfn "%s (%i) - %A" t y r


// branching
// if..then..else, chain with elif
// can be used like (?:) but when only if must return unit, 
// otherwise if and else must return the same type
let isEven (number: int) =
    if number = 0 then
        printfn "zero"
    elif number % 2 = 0 then
        printfn "%i is even" number
    else
        printfn "%i is odd" number
