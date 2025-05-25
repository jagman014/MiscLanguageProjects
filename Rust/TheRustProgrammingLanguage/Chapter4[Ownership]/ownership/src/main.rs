fn main() {
    let s = String::from("hello"); // s comes into scope

    takes_ownership(s); // s moves into the function, no longer valid after

    let x = 5; // x comes into scope, 
    // simple scalars are stored on the stack and can be copied easily

    makes_copy(x); // x is copied into the function
    // can still use x after this

    let s1 = gives_ownership(); // gives_ownership moves its return value

    let s2 = String::from("hello"); // s2 comes into scope

    let s3 = takes_and_gives_back(s2); // s2 moved into function, which moves its return into s3
} // vars go out of scope

fn takes_ownership(some_string: String) {
    // some_string comes into scope
    println!("{some_string}");
} // some_string is out of scope and memory is freed

fn makes_copy(some_integer: i32) {
    // some_integer comes into scope
    println!("{some_integer}");
} // some_integer goes out of scope

fn gives_ownership() -> String {
    // moves return value into where func is called
    let some_string = String::from("yours");

    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    // a_string comes into scope
    a_string // a_string is returned and moved out into where the func is called
}
