using System;

namespace Enums {
    // enums
    // value type used to declare a list of constant ints
    
    // example
    // days of week
    enum Day {
        Monday, // 0
        Tuesday, // 1
        // ...
    }

    enum Direction {
        Left,               // Left, -> as first assigned to 0
        Up,                 // Left = 1, Up = 2 -> value assignment
        Right,              // Left = 1 -> as first rest will follow
        Down
    }
    public class Program {
        public static void Main(string[] args) {
            Direction dir = new Direction();
            dir = Direction.Up;

            if (dir == Direction.Left) {
                Console.WriteLine("Go Left");
            }
            else if (dir == Direction.Up) {
                Console.WriteLine("Go Up");
            }
            else if (dir == Direction.Right) {
                Console.WriteLine("Go Right");
            }
            else if (dir == Direction.Down) {
                Console.WriteLine("Go Down");
            }
        }
    }
}
