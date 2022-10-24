public class DataTypes {
    void PrimitiveTypes() {
        // 8 primitive types
        // integer types
        byte aByte = 0;         // 8 bit
        short aShort = 1;       // 16 bit
        int anInt = 2;          // 32 bit
        long aLong = 3;         // 64 bit

        // floating point numbers
        float aFloat = 4.0f;    // 32 bit
        double aDouble = 5.0;   // 64 bit

        // character
        char aChar = 'a';

        // boolean
        boolean aBool = true;
    }

    public static void main(String[] args) {
        // implicit conversions
        float myFloat = 3.14f; // narrowing / lossy conversion
        double myDouble = myFloat; // widening / lossless conversion
    }
}
