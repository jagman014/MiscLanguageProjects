fn main() {
    let s1 = String::from("hello");

    let len = calculate_length(&s1);
    // pass by reference, s1 is not move, but the pointer is copied

    println!("The length of '{s1}' is {len}");

    let mut s = String::from("hello");

    change(&mut s); // passing mutable reference

    // can only have one mutable reference at a time
    // cannot have a mutable reference if an immutable one has already been called
    // can have as many immutable references as possible

    // references go out of scope once used
    // rust will error with a dangling reference
}

fn calculate_length(s: &String) -> usize {
    // reference, borrows object doesn't have owneship
    // references are immutable by default
    s.len()
}

fn change(some_string: &mut String) {
    // need to specify mutable reference
    some_string.push_str(", world!");
}
