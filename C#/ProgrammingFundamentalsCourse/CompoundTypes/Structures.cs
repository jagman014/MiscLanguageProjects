using System;

namespace Structures {
    // structures
    // similar to classes, like structs from C++
    // unlike classes, don't support inheritance or polymorphism
    // classes are reference type, structs are value type

    public struct Monster {
        public string name;
        public int scare;
        public int size;

        // can also hold constructors
        public Monster(string name, int scare, int size) {
            this.name = name;
            this.scare = scare;
            this.size = size;
        }

        public void Print() {
            Console.WriteLine(name);
            Console.WriteLine(size);
            Console.WriteLine(scare);
        }
    }

    public class Program {
        public static void Main(string[] args) {
            Monster mike = new Monster("Mike", 10, 15);
            Console.WriteLine(mike.name);
            mike.Print();

            Monster jack = new Monster();
            jack.Print();
        }
    }
}
