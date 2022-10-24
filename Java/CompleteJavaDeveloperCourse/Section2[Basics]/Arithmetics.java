public class Arithmetics {
    public static void main(String[] args) {
        int a = 10;
        int b = 15;

        // standard arithmetics
        int sum = a + b; // addition
        int difference = a - b; // subtraction
        int product = a * b; // multiplication
        int quotient = b / a; // integer division
        int remainder = b % a; // modulo
        double ratio = (double)b / a; // division

        System.out.println(a + " + " + b + " = " + sum);
        System.out.println(a + " - " + b + " = " + difference);
        System.out.println(a + " * " + b + " = " + product);
        System.out.println(b + " // " + a + " = " + quotient);
        System.out.println(b + " % " + a + " = " + remainder);
        System.out.println(b + " / " + a + " = " + ratio);

        // compound assignments, available for all arithmetics ops
        sum += 20;
        product *= 2;

        System.out.println("sum += 20 -> " + sum);
        System.out.println("product *= 2 -> " + product);

        // increment
        sum++; // ++sum available

        System.out.println("sum++ -> " + sum);

        // decrement
        sum--; // --sum available

        System.out.println("sum-- -> " + sum);
    }
}
