package Project2_1;

import java.util.Scanner;

public class AverageOfThree {
    public static void main(String[] args) {
        Scanner keyboardInput = new Scanner(System.in);
        double inputDouble1;
        double inputDouble2;
        double inputDouble3;
        double average;

        System.out.println("Type in three real numbers.");
        inputDouble1 = keyboardInput.nextDouble();
        inputDouble2 = keyboardInput.nextDouble();
        inputDouble3 = keyboardInput.nextDouble();

        average = (inputDouble1 + inputDouble2 + inputDouble3) / 3.0;

        System.out.println("The average of: " + inputDouble1 + ", " + inputDouble2 + ", " + inputDouble3 + ", is " + average);
        keyboardInput.close();
    }
}
