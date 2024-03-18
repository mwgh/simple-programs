import java.util.Scanner;

public class WayTooLongWords {

	public static final int LENGTH_OF_TOO_LONG_WORD = 10;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < n; i++) {
			String word = scan.nextLine();
			if (word.length() > LENGTH_OF_TOO_LONG_WORD) {
				word = word.substring(0, 1)
						+ (word.length() - 2)
						+ word.substring(word.length() - 1);
			}
			System.out.println(word);
		}
	}
}
