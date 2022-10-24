import java.util.Scanner;

public class UserInput {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        String name;
        String city;
        int age;
        double inputDouble;

        System.out.println("What is your name?");
        name = keyboard.nextLine();

        System.out.println("What is your age?");
        age = keyboard.nextInt();
        keyboard.nextLine(); // remove \n left behind from nextInt

        System.out.println("Enter a real number:");
        inputDouble = keyboard.nextDouble();
        keyboard.nextLine();

        System.out.println("What city do you live in?");
        city = keyboard.nextLine();

        System.out.println("Hello, " + name);
        System.out.println("Age is " + age);
        System.out.println("City is " + city);
        System.out.println("That number doubled is: " + (inputDouble * 2));

        keyboard.close();
    }
}
