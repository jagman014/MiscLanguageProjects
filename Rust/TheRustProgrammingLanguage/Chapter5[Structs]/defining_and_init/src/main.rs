fn main() {
    let mut user1 = User {
        active: true,
        username: String::from("someusername123"),
        email: String::from("someone@example.com"),
        sign_in_count: 1,
    };

    user1.email = String::from("anotheremail@exmaple.com");

    let user2 = User {
        email: String::from("another@example.com"),
        ..user1 // `..` syntax sets all other values to that of the other object
    }; // user1 is no longer valid as the String values are moved not copied like bool or u64

    let black: Colour = Colour(0, 0, 0);
    let origin: Point = Point(0, 0, 0);
    // use `.i` index notation to access elements of tuple struct

    let subject = AlwaysEqual;
}

struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

fn build_user(email: String, username: String) -> User {
    User {
        active: true,
        username, // can short hand as the value and key are the same name
        email,    // don't need to write `email: email`
        sign_in_count: 1,
    }
}

// Tuple Structs, struct without named fields
// useful for making named tuple types
struct Colour(i32, i32, i32);
struct Point(i32, i32, i32);

// unit-like structs, has the unit type ()
struct AlwaysEqual;
