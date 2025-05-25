fn main() {
    let s = "hello"; // variable is only available in the current scope

    // string literals are immutable
    // String type is manged on the heap, can store data that is unknown at compile time
    // objects allocated to the heap are actually pointer objects
    println!("Hello, world!");
    let mut s = String::from("hello");
    s.push_str(", world!"); // push_str appends a literal to a string
    println!("{s}");

    // Rust follows the Resource Allocation Is Initialisation (RAII) pattern
    // copying a pointer invalidated the original pointer
    let s1 = s; // s in now invalid, won't cause a double free error.

    // println!("{s}"); // but cannot be used again, as the pointer has moved

    // rust moves by default and doesn't deep copy
    // to deep copy use clone method
    let s2 = s1.clone();

    println!("s1: {s1}, s2: {s2}");
}
