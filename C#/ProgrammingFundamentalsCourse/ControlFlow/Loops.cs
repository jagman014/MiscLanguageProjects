using System;

namespace Loops {
    public class Program {
        public static void Main(string[] args) {
            // for loops
            int x = 0;

            // for index; condition; increment
            for (int i = 0; i < 10; i++) {
                x += i;
                Console.WriteLine(i);
                Console.WriteLine($"The sum is: {x}");

                if (i == 7) {
                    Console.WriteLine("Some string");
                }
            }

            // while loops
            int check = 0;

            while (check != 13) {
                Console.WriteLine("continue");
                check++;
            }

            // do while
            do {
                Console.WriteLine("ok");

                check--;
            } while (check != 0);
        }
    }
}
