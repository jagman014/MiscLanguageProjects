using System;

namespace PrimitiveTypes {
    public class Primitives {
        public static void Main(string[] args) {            
            // varaibales are declared once, can be changed later
            int my_int = 1;

            // constants declared once, canot be changed
            const int A_CONST_INT = 100;

            // integer, default signed 32 bit, -2,147,483,648 -> 2,147,483,647
            int an_int = 1;
            const int CONST_INT = 2;

            //-----------------------------------------------------------------
            // bit versions of int

            // byte, 8 bit, default unsigned, 0 -> 255
            byte a_byte = 120;
            const byte CONST_BYTE = 255;

            // short, 16 bit, -32,768 -> 32,767
            short a_short = 32000;
            const short CONST_SHORT = -32000;

            // long, 64 bit, -9.2x10^18 -> 9.2x10^18
            long a_long = 323424324324;
            const long CONST_LONG = 324132113213;
            //-----------------------------------------------------------------
            // unsigned versions of int

            // uint, ulong, ushort
            uint a_uint = 11232;
            ushort a_ushort = 22345;
            ulong a_ulong = 1324563;

            //-----------------------------------------------------------------
            // signed version of byte

            // sbyte, -128 -> 127
            sbyte an_sbyte = -120;

            //-----------------------------------------------------------------

            // floats, default 32bits, -3.4x10^38 -> 3.4x10^38, 
            // end with f otherwise double, accurate to 7 dp
            float a_float = 2.5634523f;
            const float CONST_FLOAT = 2.1425f;

            // double, default 64 bit, accurate to 15-16 dp
            double a_double = 2.234234;
            const double CONST_DOUBLE = 12.23424;

            // char, hold one value at a time, letters or symbols
            char a_char = 'a';
            const char CONST_CHAR = '-';

            // boolean, true or false
            bool a_bool = true;
            const bool CONST_BOOL = false;

            // scoping of variables also applies
        }
    }
}
