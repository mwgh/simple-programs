import java.io.*;
import java.util.*;


public class Main2 {
    public static void main(String[] args) throws IOException {
        try (Scanner in = new Scanner(new File("input.txt"));
            PrintWriter out = new PrintWriter("output.txt")) {
                long a = in.nextLong();
                long b = in.nextLong();
                long b2 = b * b;
                System.out.println(a + b2);
                out.println(a + b2);
            }
    }
}
