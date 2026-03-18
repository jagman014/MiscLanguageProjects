// all modules are private by default
// parents can't see into children, but children can see out to parents
mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
        fn seat_at_table() {}
    }

    mod serving {
        fn take_order() {}
        fn serve_order() {}
        fn take_payment() {}
    }
}

// creates a module tree of:
// crate
// |-- front_of_house
//      |-- hosting
//      |   |-- add_to_waitlist
//      |   |-- seat_at_table
//      |-- serving
//          |-- take_order
//          |-- serve_order
//          |-- take_payment

// use statement to shorten paths
// similar to c# using
// only valid for the scope it occurs in
// can reexport this with `pub use`
use crate::front_of_house::hosting;

pub fn eat_at_restaurant() {
    // Absolute path, prefered
    crate::front_of_house::hosting::add_to_waitlist();

    // Relative path
    front_of_house::hosting::add_to_waitlist();

    // shortened path
    hosting::add_to_waitlist();
}

fn deliver_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        // super to navigate up the module tree
        super::deliver_order();
    }

    fn cook_order() {}

    // making a stuct public, need to make fields public as well
    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String,
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    // making an enum public, makes all varients public
    pub enum Appetiser {
        Soup,
        Salad,
    }
}

pub fn eat_at_restaurant() {
    // Order a breakfast in the summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");

    // Change our mind about what bread we'd like
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // The next line won't complie if uncommented
    // cannot modify the seasonal_fruit as it's not public
    // meal.seasonal_fruit = String::from("blueberries");

    let order1 = back_of_house::Appetiser::Soup;
    let order2 = back_of_house::Appetiser::Salad;
}

use std::collections::*; // import all public submodules
use std::fmt::Result;
use std::io::Result as IoResult; // as to alias import
use std::io::{self, Write}; // imports io and io::Write
use std::{cmp::Ordering, io}; // multiple imports
