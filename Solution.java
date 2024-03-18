import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("testinput.txt");
        
        int numCases = 0, numMarbles, conseqMarbles, startingMarble; // T, N, K, X
        double total, subtract;
        int diff; // remaining weight
        
        try (Scanner in = new Scanner(file)) {
            if (in.hasNextInt()) {
                numCases = in.nextInt();
            }
            
            // numCases (T) < 100
            for (int i = 0; i < numCases; i++) {
                numMarbles = in.nextInt();
                conseqMarbles = in.nextInt();
                startingMarble = in.nextInt();
                
                total = (numMarbles/2.0) * (numMarbles + 1);
                subtract = (conseqMarbles/2.0) * ((2 * startingMarble) + conseqMarbles - 1);
                diff = (int) (total - subtract);
                
                System.out.println("Case " + (i + 1) + ": " + diff);
            }
        } catch (FileNotFoundException e) {
        }
    }
}
