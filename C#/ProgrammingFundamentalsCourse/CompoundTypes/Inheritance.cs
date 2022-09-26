using System;

namespace Inheritance {
    // inheritance
    // class inherits attibutes and methods from class above

    // abstract class
    // cannot be instantiated
    // can contain abstract methods, not required
    // can contain non-abstract methods

    public abstract class Character {
        public string name;
        public int speed;
        public int health;
        public int test = 2;

        public abstract void Print(); // must be modified in derived classes

        public int TestFunction() {
            test *= 2;
            return test;
        }

        // virtual class
        // can be changed in classes that derive from base, not necessary
        public virtual void Swing() {
            Console.WriteLine("SWING!");
        }
    }

    public class Swordsman: Character {
        public Swordsman() {
            name = "Eric";
            speed = 10;
            health = 100;
        }

        // implement abstract method using override
        public override void Print() {
            Console.WriteLine($"My name is {name},");
            Console.WriteLine($"I am {speed} units fast,");
            Console.WriteLine($"My health is {health}");
        }

        // virtual functions can be overriden as well
        public override void Swing() {
            Console.WriteLine("No Swing");
        }
    }

    public class Program {
        public static void Main(string[] args) {
            // Character MyChar = new Character(); // error, cannot create abstract object
            Swordsman eric = new Swordsman();
            eric.Print();
            Console.WriteLine(eric.test);
            eric.TestFunction();
            Console.WriteLine(eric.test);
            eric.Swing();
        }
    }
}
