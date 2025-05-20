fn main() {
    // Base Types
    // ----------
    // integer values i = signed, u = unsigned.
    // values from 8 - 128, size = architecuture dependent

    // Decimal 1_000, can use "_" for separator
    // Hex 0xff, Octal 0o77, Binary 0b1111_0000, Byte b'A'

    // floating points f32 (single) and f64 (double, default)
    let x = 2.0;
    let y: f32 = 3.0;

    // arithmetic
    // add +, sub -, mult *, div /, quotient //, remainder %

    // booleans
    let t = true;
    let f: bool = false;

    // char
    let c = 'c'; // single quotes
    let z: char = 'z';

    // Compound Types
    // --------------

    // Tuples
    // Fixed length lists
    let tup: (i32, f64, u8) = (500, 6.4, 1);

    // tuple unpacking
    let (x, y, z) = tup;

    // element assess
    let five_hundred = tup.0;
    let six_point_four = tup.1;
    let one = tup.2;

    // Arrays
    // all elements must have the same type, fixed length
    let months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ];
    let a: [i32; 5] = [1, 2, 3, 4, 5];

    // can initialise an array e.g. 5 elements of all 3
    let a = [3; 5];

    // access arrays with []
    let first = a[0];
    let second = a[1];
}
