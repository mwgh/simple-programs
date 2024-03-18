import java.util.Scanner;

public class Watermelon {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int w = scan.nextInt();

		if (w == 2 || w % 2 != 0) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}
