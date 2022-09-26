using System;

namespace ArraysAndStrings {
    public class Program {
        public static void Main(string[] args) {
            // Array
            // container for multiple values
            // accessed through indexing

            // declaring array using [], 1D array
            int[] MyArray;

            // initiaiting
            // as we declare
            int[] MyNewArray = new int[10];

            // after declaring
            MyArray = new int[5];

            // zero indexed
            Console.WriteLine(MyArray[0]);
            
            MyArray[0] = 234;
            MyArray[1] = 5;
            MyArray[2] = 6;
            // MyArray[5] = 2; // index range error
            Console.WriteLine(MyArray[0]);

            // anytype can be strored in an array
            char[] MyCharArray = new char[5];
            MyCharArray[0] = 'h';
            MyCharArray[1] = 'e';
            MyCharArray[2] = 'l';
            MyCharArray[3] = 'l';
            MyCharArray[4] = 'o';

            for (int i = 0; i < 5; i++) {
                Console.Write(MyCharArray[i]);
            }

            Console.Write('\n');

            // Strings
            // array of char
            // can access through indexing, but cannot change them
            string MyString = "Hello";
            Console.WriteLine($"Last letter of string is: {MyString[4]}");

            // MyString[0] = 'y'; // error
        }
    }
}
