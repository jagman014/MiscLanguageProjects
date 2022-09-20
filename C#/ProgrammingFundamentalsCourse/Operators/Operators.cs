using System;

namespace Operators {
    public class Opperator {
        public static void Main(string[] args) {
            // operators allows for certain actions to take place

            // equals =:
            // assignment
            int my_int = 10;

            // comparing values ==
            if (my_int == 10) {
                Console.WriteLine("I'm 10");
            }

            // not equals !=
            if (my_int != 8) {
                Console.WriteLine("I'm not 8");
            }
            
            // arrithmetics
            // +
            my_int = my_int + 2;
            Console.WriteLine(my_int);

            // -
            my_int = my_int - 2;
            Console.WriteLine(my_int);

            // *
            my_int = my_int * 2;
            Console.WriteLine(my_int);

            // /
            my_int = my_int / 2;
            Console.WriteLine(my_int);

            // pre-incrementation, before operation (++, --)
            int i = 0;
            Console.WriteLine(++i); // print 1

            // post-incrementation, after operation
            Console.WriteLine(i++); // prints 1
            Console.WriteLine(i); // prints 2

            // > gt, < lt
            int a = 10;
            int b = 15;

            if (a > b) {
                Console.WriteLine("a is bigger");
            }
            else {
                Console.WriteLine("b is bigger");
            }

            // >= gte, <= lte
            b = 5;

            if (a >= b) {
                Console.WriteLine("a is bigger or equal");
            }
            else {
                Console.WriteLine("b is bigger");
            }

            // +=, -=, *=, /=, operation and assignment
            int c = 10;
            Console.WriteLine(c);

            c += 2;
            Console.WriteLine(c);

            c -= 2;
            Console.WriteLine(c);

            c *= 2;
            Console.WriteLine(c);

            c /= 2;
            Console.WriteLine(c);

            // modulo %
            int d = 24;
            int e = d % 5;
            Console.WriteLine(e);

            // conditional (?:)
            int new_int = (e > 3) ? 5 : 2;
            Console.WriteLine(new_int);

            // logical operators allow for testing truthiness
            // AND &&, OR ||, NOT !

            bool f = true;
            bool g = false;

            if (f && g) {
                Console.WriteLine("Yay");
            }
            else {
                Console.WriteLine("Oh no");
            }

            if (f || g) {
                Console.WriteLine("Yay");
            }
            else {
                Console.WriteLine("Oh no");
            }

            if (f && !g) {
                Console.WriteLine("Yay");
            }
            else {
                Console.WriteLine("Oh no");
            }
        }
    }
}

