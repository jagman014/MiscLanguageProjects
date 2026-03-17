fn main() {
    let some_number = Some(5);
    let some_char = Some('e');
    let absent_number: Option<i32> = None;

    let x: i32 = 5;
    let y: Option<i32> = Some(5);
    let sum = x + y; // compilation error, i32 doens't have a Add<Option<i32>> defined
}

// No nulls in rust, but the Option<T> type is available
// Implemented as:
//
// enum Option<T> {
//    None,
//    Some(T),
// }
