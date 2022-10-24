public class Logicals {
    public static void main(String[] args) {
        // standard ops
        // && (and)
        // || (or)
        // ! (not)
        boolean isRaining = false;
        boolean isWarm = true;

        boolean combined = isRaining && isWarm;

        System.out.println("Is it raining and warm? " + combined);

        combined = isRaining || isWarm;

        System.out.println("Is it raining or warm? " + combined);

        combined = !isRaining;

        System.out.println("Is it not raining? " + combined);
    }
}
