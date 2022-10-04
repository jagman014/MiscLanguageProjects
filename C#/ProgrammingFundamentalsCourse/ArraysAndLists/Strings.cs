using System;
using System.Text;

namespace Strings {
    public class Program {
        public static void Main(string[] args) {
            // modifying strings

            // string replace and remove
            string TestString = "Hello, my name is Alice";
            Console.WriteLine(TestString);

            // replace, every instance is replaced
            string ResultsString = TestString.Replace("Alice", "Bob");
            Console.WriteLine(ResultsString);

            string ResultsString2 = TestString.Replace('e', 'i');
            Console.WriteLine(ResultsString2);

            // remove, list of chars from starting index is removed
            string RemoveString = TestString.Remove(17, 6);
            Console.WriteLine(RemoveString);

            // appending
            TestString += " and I am a name";
            Console.WriteLine(TestString);

            // problems
            // create new instance with each modification, uses more memory

            // solution
            // StringBuilder
            // need to include System.Text
            // can set capacity of StringBuilder
            StringBuilder MySB = new StringBuilder("Hello, World!", 20);
            Console.WriteLine(MySB);
            Console.WriteLine($"MySB capacity is: {MySB.Capacity}");

            // exceeding the capacity will double that allocated

            // methods:
            // append adds to end
            MySB.Append(" is our first program");
            Console.WriteLine(MySB);
            Console.WriteLine($"MySB capacity is: {MySB.Capacity}");

            // insert adds to location
            MySB.Insert(26, " small");
            Console.WriteLine(MySB);

            // remove list of chars from start index
            MySB.Remove(26, 6);
            Console.WriteLine(MySB);

            // replace list of chars
            MySB.Replace("our", "my");
            Console.WriteLine(MySB);

            MySB.Replace('o', 'z');
            Console.WriteLine(MySB);

            MySB.Replace("i", "Not");
            Console.WriteLine(MySB);
        }
    }
}
