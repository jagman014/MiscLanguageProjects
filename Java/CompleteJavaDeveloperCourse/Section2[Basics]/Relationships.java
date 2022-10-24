public class Relationships {
    public static void main(String[] args) {
        // Coditional operators
        // return boolean result
        // standard set:
            // >, <, >=, <=, ==, !=
        boolean bool1 = true;
        boolean bool2 = false;

        int int1 = 37;
        int int2 = 20;
        int int3 = 20;

        System.out.println("bool1 = " + bool1);
        System.out.println("bool2 = " + bool2);
        
        // relational operations
        boolean intComparison = int1 > int2;
        System.out.println(int1 + " > " + int2 + " -> " + intComparison);

        intComparison = int2 < int3;
        System.out.println(int2 + " < " + int3 + " -> " + intComparison);

        intComparison = int2 == int3;
        System.out.println(int2 + " == " + int3 + " -> " + intComparison);
    }
}
