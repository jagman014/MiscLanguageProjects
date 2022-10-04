using System;
using System.IO;

// System.IO allows for reading and writing files and data streams

namespace FileIO {
    public class Program {
        public static void Main(string[] args) {
            // use File class

            string path = Directory.GetCurrentDirectory().ToString();
            string file1 = path + @"\test_text.txt";
            string file2 = path + @"\test_text_2.txt";

            // check if file exists and delete
            if (File.Exists(file1)) {
                File.Delete(file1);
            }

            // File.WriteAllText
            // creates file, writes, then closes
            // if file exists it will replace
            File.WriteAllText(file1, "Hello, Text!\n");

            // File.WriteAllLines
            // can write multiple lines
            File.WriteAllLines(file2, new string[] {"Hello", "This", "Is", "Neat"});

            // editing / appending to files
            // opends file, appends, then closes
            File.AppendAllText(file1, "Some more text\n");

            // reading files
            string contents = File.ReadAllText(file2);
            Console.WriteLine($"Contents is: {contents}");

            Console.WriteLine(File.ReadAllText(file1));

            Console.ReadKey();
        }
    }
}
