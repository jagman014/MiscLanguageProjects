fn main() {
    let config_max = Some(3u8);

    // uses same pattern matching as `match`, but only one of the arms
    if let Some(max) = config_max {
        println!("The maximum is configured to be {max}");
    }

    let coin = Coin::Quarter(UsState::Alaska);
    let mut count = 0;

    if let Coin::Quarter(state) = coin {
        println!("State quarter from {state:?}");
    } else {
        count += 1;
    }
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
    // etc.
}
