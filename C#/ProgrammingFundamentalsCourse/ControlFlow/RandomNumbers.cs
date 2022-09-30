using System;

namespace RandomNumbers {
    public class Program {
        public static void Main(string[] args) {
            // Control Flow
            // how program flows
            // loops, statements, and functions alter the flow of the program

            // Random class
            // generate "random" numbers

            // declare
            Random RandInt = new Random();

            // init
            // use next keyword, 3 ways of doing so

            // default
            // generates non-negative 32 bit int
            int Test = RandInt.Next();

            // generate non-negative 32 bit int, from 0-max
            int Test2 = RandInt.Next(55);

            // generates from -100 to 100
            int Test3 = RandInt.Next(-100, 100);

            Console.WriteLine($"Test: {Test}, Test2: {Test2}, Test3: {Test3}");
        }
    }
}
