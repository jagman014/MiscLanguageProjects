use crate::garden::vegetables::Asparagus;

pub mod garden;
// searches in src/garden.rs, src/garden/mod.rs

fn main() {
    let plant = Asparagus {};

    println!("I'm growing {plant:?}!");
}
