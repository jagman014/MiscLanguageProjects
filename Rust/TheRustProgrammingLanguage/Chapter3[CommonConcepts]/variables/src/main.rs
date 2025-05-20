fn main() {
    let x = 5; // variables are immutable by default, need to add "mut" to make it mutable
    let x = x + 1; // reassignment of an immutable variable requires the let keyword

    {
        let x = x * 2; // rust allows for variable shadowing, via scope or type
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");

    // can change type with reassignment
    // cannot change type with mut only
    let spaces = "   ";
    let spaces = spaces.len();

    const THREE_HOURS_IN_MINUTES: u32 = 60 * 60 * 3; // const variables must always be annotated
    println!("Three hours is {THREE_HOURS_IN_MINUTES} in minutes");
}
