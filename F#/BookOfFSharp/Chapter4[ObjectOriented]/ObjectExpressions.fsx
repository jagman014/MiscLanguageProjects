// alternative to inheritance
// useful for one off types
type IWeapon =
    abstract Description: string with get
    abstract Power: int with get

type Character(name: string, maxHP: int) =
    member x.Name = name
    member val HP = maxHP with get, set
    member val Weapon: IWeapon option = None with get, set
    member x.Attack(o: Character) =
        let power: int = match x.Weapon with
                            | Some(w: IWeapon) -> w.Power
                            | None -> 1 // fists
        o.HP <- System.Math.Max(0, o.HP - power)
    override x.ToString() =
        sprintf $"{name}: {x.HP} / {maxHP}"

let witchKing: Character = Character("Witch-King", 100)
let frodo: Character = Character("Frodo", 50)

// object expression using new and defining the class members
// must define all abstract members
let forgeWeapon (desc: string) (power: int) = {
    new IWeapon with
        member x.Description with get() = desc
        member x.Power with get() = power
    // can implement multiple bases
    interface System.IDisposable with
        member x.Dispose() = printfn "Disposing"
}

let morgulBlade: IWeapon = forgeWeapon "Morgul-Blade" 25
let sting: IWeapon = forgeWeapon "Sting" 10

witchKing.Weapon <- Some(morgulBlade)
frodo.Weapon <- Some(sting)

witchKing.Attack frodo

let narsil: IWeapon = forgeWeapon "Narsil" 25

(narsil :?> System.IDisposable).Dispose()
