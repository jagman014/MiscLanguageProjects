using System;
// debugging requires dotnet project
// can add breakpoints, step into/over lines

namespace Debugging {
    public class Program {
        // Multiply two ints
        static int Multiply(int x, int y) {
            return (x * y);
        }

        // Divide two ints
        static int Divide(int x, int y) {
            return (int)(x / y);
        }

        public static void Main(string[] args) {
            int MyIntX = 10;
            int MyIntY = 30;

            // result = 10 * 30
            int result = Multiply(MyIntX, MyIntY);

            // NewResult = (300 * 30) / 10
            int NewResult = Divide(Multiply(result, MyIntY), MyIntX);

            // FinalResult = 900 * (300 * 900)
            int FinalResult = Multiply(NewResult, Multiply(result, NewResult));

            int TestInt = 3;

            while (FinalResult > 5) {
                Console.WriteLine($"The number {FinalResult} is quite big, lets make it smaller");
                FinalResult = Divide(FinalResult, TestInt);
            }

            Console.WriteLine($"Final Number is: {FinalResult}");

            Console.ReadKey();
        }
    }
}
