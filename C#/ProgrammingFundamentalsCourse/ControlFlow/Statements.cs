using System;

namespace Statements {
    public class Program {
        public static void Main(string[] args) {
            int q = 10;
            int c = 11;

            // if statement, checks condition then executes codeblock
            if (q == 10) {
                Console.WriteLine("I'm 10");
            }
            else if (q == 11) { // else if statement, can have multiple
                Console.WriteLine("I'm 11");
            }
            else { // else statement, not required
                Console.WriteLine("I'm not 10");
            }

            // switch statement, replace multiple else if statements
            switch (c) {
                case 10:
                    Console.WriteLine("I'm 10");
                    break;
                case 11:
                    Console.WriteLine("I'm 11");
                    break;
                case 12:
                    Console.WriteLine("I'm 12");
                    break;
                default:
                    Console.WriteLine("I'm not 10");
                    break;
            }
        }
    }
}
