// using events to run code, using event handlers
open System
open System.Data
open System.Timers

let ticks: int ref = ref 0
// create timer class
let t: Timer = new Timer(500.0)
// subscribe to elapsed function using lambda as event handler
t.Elapsed.Add(fun (ea: ElapsedEventArgs) -> printfn "tick"; ticks.Value <- ticks.Value + 1)
t.Start()
while ticks.Value < 5 do ()
t.Dispose()

// setup DataTable
let dt: DataTable = new DataTable("person")
dt.Columns.AddRange
    [|new DataColumn("person_id", typedefof<int>)
      new DataColumn("first_name", typedefof<string>)
      new DataColumn("last_name", typedefof<string>)|]
dt.Constraints.Add("pk_person", dt.Columns.[0], true)

// partition function returns two events
let (h1: IEvent<DataRowChangeEventArgs>), (h2: IEvent<DataRowChangeEventArgs>) =
    dt.RowChanged
        // invoke partition function, and delegate with lambda function
        |> Event.partition
            (fun (ea: DataRowChangeEventArgs) ->
                        let ln: string = ea.Row.["last_name"] :?> string
                        ln.Equals("Pond", StringComparison.InvariantCultureIgnoreCase))

// subscribe both new events by calling add method
h1.Add (fun _ -> printfn "Come along, Pond")
h2.Add (fun _ -> printfn "Row changed")

// changing rows to check event listeners
dt.Rows.Add(1, "Rory", "Williams") |> ignore
dt.Rows.Add(2, "Amelia", "Pond") |> ignore

// custom events requires
// let binding for event object
// exposing Publish property
// trigger function
type Toggle() =
    let toggleChangedEvent: Event<_> = Event<_>()
    let mutable isOn: bool = false
    // CLIEvent makes this consumable from other .NET languages
    [<CLIEvent>]
    member x.ToggleChanged: IEvent<_> = toggleChangedEvent.Publish
    member x.Toggle() =
        isOn <- not isOn
        toggleChangedEvent.Trigger (x, isOn)

let myToggle: Toggle = Toggle()
// partition event handler for on and off
// map is used to throw away the first parameter
let (onHandler: IEvent<bool>), (offHandler: IEvent<bool>) =
    myToggle.ToggleChanged
        |> Event.map (fun (_, isOn: bool) -> isOn)
        |> Event.partition (fun (isOn: bool) -> isOn)

onHandler |> Event.add (fun _ -> printfn "Turned on")
offHandler |> Event.add (fun _ -> printfn "Turned off")

myToggle.Toggle()
myToggle.Toggle()
