fn main() {
    let s = String::from("Hello world");

    let hello = &s[0..5]; // string slice 
    let world = &s[6..11];
    // can remove leading 0 and trailing number to get first and last indicies

    let word = first_word(&s);

    // can also slice arrays
    let a = [1, 2, 3, 4, 5];

    let slice = &a[1..3];
    assert_eq!(slice, &[2, 3]);
}

// returned slice object for valiable return lengths
// slices are immutable string literals
// &str as param allows coersion of &String
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
