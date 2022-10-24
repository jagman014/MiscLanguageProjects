package Project2_2;

import java.util.Scanner;

public class MadLibsClone {
    public static void main(String[] args) {
        Scanner keyboadInput = new Scanner(System.in);
        String contents = "There once was a ";

        System.out.print("Enter an adjective:\t");
        contents += keyboadInput.nextLine();
        contents += " girl named ";

        System.out.print("Enter a girl's name:\t");
        contents += keyboadInput.nextLine();
        contents += ",\nwho was a ";

        System.out.print("Enter another adjective:\t");
        contents += keyboadInput.nextLine();
        contents += " ";

        System.out.print("Enter an occupation:\t");
        contents += keyboadInput.nextLine();
        contents += " in the kingdom of ";

        System.out.print("Enter a place name:\t");
        contents += keyboadInput.nextLine();
        contents += ".\nShe loved to wear ";

        System.out.print("Enter an item of clothing:\t");
        contents += keyboadInput.nextLine();
        contents += " and ";

        System.out.print("Enter the name of a hobby:\t");
        contents += keyboadInput.nextLine();
        contents += ".\nShe wanted to marry the ";

        System.out.print("Enter another adjective:\t");
        contents += keyboadInput.nextLine();
        contents += " ";

        System.out.print("Enter another occupation:\t");
        contents += keyboadInput.nextLine();
        contents += " named ";

        System.out.print("Enter a boy's name:\t");
        contents += keyboadInput.nextLine();
        contents += " but her father,\nKing ";

        System.out.print("Enter a man's name:\t");
        contents += keyboadInput.nextLine();
        contents += " forbid her from seeing him.";

        System.out.println("The story you created:\n");
        System.out.println(contents);

        keyboadInput.close();
    }
}
