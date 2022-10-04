using System;

namespace ProceduralProgramming {
    public class Program {
        static int add(int x, int y) {
            // adds two integers
            return (x + y);
        }

        static void PrintInt(int x) {
            // prints integer to console
            Console.WriteLine(x);
        }

        static void PrintIntro() {
            // prints out welcome
            Console.WriteLine("Welcome");
        }

        public static void Main(string[] args) {
            // procedural programming
            // based on making calls to functions / routines
            PrintIntro();

            int res = add(5, 15);
            PrintInt(res);

            // can keep reusing these functions
            int NewRes = add(res, -12);
            PrintInt(NewRes);
        }
    }
}
