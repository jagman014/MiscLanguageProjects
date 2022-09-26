using System;

namespace Classes {
    public class Monster {
        // can contain data members or methods

        // public can be accessed anywhere in project
        public string name;
        public int size;
        public const int legs = 2;

        // private can only be accessed from within the class
        private int scare;

        // static apply to entire class rather than an instance
        public static int NumMonsters;

        // default constructor
        public Monster() {
            name = "default";
            size = 20;
            scare = 10;
            NumMonsters++; // increment number of mosters
        }

        public Monster(string name, int size, int scare) {
            this.name = name;
            this.size = size;
            this.scare = scare;
            NumMonsters++;
        }

        // methods
        public void Print() {
            Console.WriteLine($"Monster's name: {name}");
            Console.WriteLine($"Monster's size: {size}");
            Console.WriteLine($"Monster's scare: {scare}");
        }
    }

    public class Program {
        public static void Main(string[] args) {
            Monster dinosaur = new Monster();
            // public members
            Console.WriteLine(dinosaur.name);

            // can be changed
            dinosaur.name = "Rex";
            Console.WriteLine(dinosaur.name);

            Console.WriteLine(Monster.NumMonsters);

            // changing const memeber will error
            // Dinosaur.legs = 3;

            // private member
            // Console.WriteLine(Dinosaur.scare); // error, not available outside class

            // non default constructor
            Monster dragon = new Monster("Drako", 30, 25);
            Console.WriteLine(dragon.name);

            // static check
            Console.WriteLine(Monster.NumMonsters);

            Monster zombie = new Monster("Zombie", 6, 8);
            zombie.Print();
            dragon.Print();
            dinosaur.Print();

            Console.WriteLine(Monster.NumMonsters);
        }
    }
}
