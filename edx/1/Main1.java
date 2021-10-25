import java.io.*;
import java.util.*;

public class Main1 {
    public static void main(String[] args) throws IOException {
        try (Scanner in = new Scanner(new File("input.txt"));
            PrintWriter out = new PrintWriter("output.txt")) {
                out.println(in.nextInt() + in.nextInt());
            }
    }
}
