import java.util.Scanner;

public class Team {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int problemsToSolve = 0;

		for (int i = 0; i < n; i++) {
			int petya = scan.nextInt();
			int vasya = scan.nextInt();
			int tonya = scan.nextInt();

			if (petya == 1 && vasya == 1 ||
					vasya == 1 && tonya == 1 ||
					petya == 1 && tonya == 1) {
				problemsToSolve++;
			}
		}

		System.out.println(problemsToSolve);
	}
}
