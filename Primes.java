import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Primes {
    public static void main(String[] args) {
        int n = 1000000000;
        boolean[] primes = new boolean[n];
        for (int i = 0; i < n; i++) {
            primes[i] = true;
        }
        primes[0] = false;
        primes[1] = false;

        int limit = (int) Math.sqrt(n);

        for (int i = 2; i < limit; i++) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("primes.txt"))) {
            for (int i = 2; i < n; i++) {
                if (primes[i]) {
                    System.out.println(i);
                    writer.write(i + "\n");
                }
            }
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}
