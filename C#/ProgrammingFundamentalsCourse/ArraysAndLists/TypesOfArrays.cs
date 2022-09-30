using System;

// looks at CompoundTypes/ArraysAndStrings.cs
namespace TypesOfArrays {
    public class Program {
        public static void Main(string[] args) {
            // declare using <type>[]

            // multidimensional arrays use [,]

            // declaring 2D array, need to specify dims
            int[,] A2DArray = new int[2, 2];

            // declare and init, don't need to specify dims when init
            int[,] My2DArray = new int[,] {
                {1, 2},
                {3, 4}
            };

            // indexing
            Console.WriteLine($"My2DArray[0, 1]: {My2DArray[0, 1]}");

            // 3D array
            int[,,] My3DArray = new int[,,] {
                {
                    {1, 2, 3},
                    {4, 5, 6}
                },
                {
                    {7, 8, 9},
                    {10, 11, 12}
                }
            };

            Console.WriteLine($"My3DArray[1, 0, 2]: {My3DArray[1, 0, 2]}");

            // jagged arrays
            // arrays that hold other arrays of different sizes
            int[][] MyJagArray = new int[3][];
            MyJagArray[0] = new int[3] {1, 2, 3};
            MyJagArray[1] = new int[7] {4, 5, 6, 7, 8, 9, 10};
            MyJagArray[2] = new int[1] {11};

            // accessing a jagged array
            Console.WriteLine($"MyJagArray[1][6]: {MyJagArray[1][6]}");

            // alternate init of jagged array
            char[][] MyCharJagArray = new char[][] {
                new char[] {'h', 'e', 'l', 'l', 'o'},
                new char[] {'c', 'o', 'o', 'l'},
                new char[] {'b', 'y', 'e'}
            };

            Console.WriteLine($"MyCharJagArray[2][1]: {MyCharJagArray[2][1]}");
        }
    }
}
