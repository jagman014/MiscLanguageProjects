using System;

namespace TypeConversions {
    public class Conversions {
        public static void Main(string[] args) {
            // implicit conversions
            // not specific syntax, no data loss

            float float_a = 2.3f;
            double double_a = float_a;

            sbyte sbyte_a = 12;
            int int_a = sbyte_a;
            
            // explicit conversions
            // possible loss of data, require syntax
            short short_a = (short)int_a; // C style casting

            double double_b = 2.44324324;
            float float_b = (float)double_b;

            Console.WriteLine($"double {double_b}; float {float_b}");

            // conversion between non-compatible types

            // ASCII table for char and int
            char char_a = 'a';
            int int_b = char_a;

            Console.WriteLine($"char {char_a}; int {int_b}");

            // reverse needs to be cast
            char char_b = (char)int_b;
            Console.WriteLine($"char {char_b};");

            // using Convert class
            // string is an array of chars
            string my_string = "12000";
            my_string = my_string + 50; // concats

            Console.WriteLine(my_string);

            int new_int = Convert.ToInt32(my_string);
            new_int = new_int + 50;

            Console.WriteLine(new_int);
        }
    }
}
