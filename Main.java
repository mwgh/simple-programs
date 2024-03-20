// 12751 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4604

import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		int numCases = 0, numMarbles, conseqMarbles, startingMarble; // T, N, K, X
		double total, subtract;
		int diff; // remaining weight

		Scanner in = new Scanner(System.in);
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
	}
}
