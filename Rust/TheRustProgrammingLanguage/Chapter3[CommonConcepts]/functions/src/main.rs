fn main() {
    println!("Hello, World!");

    another_function(5);
    print_labeled_measurement(5, 'h');

    // expressions return a value, unlike statements which don't
    let y = {
        let x = 3;
        x + 1 // no ; for expression
    };

    println!("The value of y is: {y}");

    let x = five();
    println!("The value of x is: {x}");

    let x = plus_one(5);
    println!("The value of x is: {x}");
}

// fn <name>(<params>) {<body>}
// must declare the type of params
fn another_function(x: i32) {
    println!("The value of x is: {x}");
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {value}{unit_label}");
}

// need to define type of value returned
fn five() -> i32 {
    5 // implicit return value, final expression is an implicit return
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
