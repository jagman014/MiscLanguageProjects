using System;
using System.Collections.Generic; // Lists contained here

namespace Lists {
    public class Program {
        public static void Main(string[] args) {
            // Lists
            // used to store multiple values
            // dynamic sizing unlike fixed arrays

            // declaing
            List<int> MyList = new List<int>();

            // add items use Add
            MyList.Add(1);
            MyList.Add(2);
            MyList.Add(3);

            // indexing
            Console.WriteLine($"MyList[0]: {MyList[0]}");
            Console.WriteLine($"Num of elements: {MyList.Count}");

            // can also add arrays to list using AddRange
            int[] MyArray = new int[] {234, 5, 6, 8, 15};

            MyList.AddRange(MyArray);

            Console.WriteLine($"Num of elements: {MyList.Count}");
            Console.WriteLine($"MyList[3]: {MyList[3]}");

            // removing items
            // Remove or RemoveAt
            List<string> Bosses = new List<string>();
            Bosses.Add("Dragon");
            Bosses.Add("Dinosaur");
            Bosses.Add("Gorrilla");
            Bosses.Add("Rat");
            Console.WriteLine($"Num of Bosses: {Bosses.Count}");

            // Remove, remove specific item
            Bosses.Remove("Rat");
            Console.WriteLine($"Num of Bosses: {Bosses.Count}");

            // RemoveAt, remove specific index
            Bosses.RemoveAt(1);
            Console.WriteLine($"Num of Bosses: {Bosses.Count}");

            // can combine lists of same type
            List<string> Monsters = new List<string>();
            Monsters.Add("Megalodon");
            Monsters.Add("Aliens");
            Monsters.Add("Giant");
            Console.WriteLine($"Num of Monsters: {Monsters.Count}");

            // use AddRange
            Monsters.AddRange(Bosses);
            Console.WriteLine($"Num of Monsters: {Monsters.Count}");

            // foreach loop, var like c++ auto
            foreach (var Monster in Monsters) {
                Console.WriteLine(Monster);
            }
        }
    }
}
