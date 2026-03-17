fn main() {
    let width1 = 30;
    let height1 = 50;

    println!(
        "[Width x Height] The area of the rectangle is {} square pixels.",
        area(width1, height1)
    );

    let rect1 = (30, 50);

    println!(
        "[Tuple] The area of the rectangle is {} square pixels.",
        area_tuple(rect1)
    );

    let rect2 = Rectangle {
        width: 30,
        height: 50,
    };

    println!(
        "[Struct] The area of the rectangle is {} square pixels.",
        area_struct(&rect2)
    );

    // print with :? to use debug, or :#? to pretty print debug
    println!("rect2 is {:?}", rect2);
    println!("rect2 is {:#?}", rect2);

    // use dbg! to print to stderr debuginfo
    let scale = 2;
    let rect3 = Rectangle {
        width: dbg!(30 * scale),
        height: 50,
    };

    dbg!(&rect3);
}

// derive traits for struct
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn area(width: u32, height: u32) -> u32 {
    width * height
}

fn area_tuple(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}

fn area_struct(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
