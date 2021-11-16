import java.util.Scanner;

class Planina {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[] y = new int[N + 1];
		int[] x = new int[N + 1];
		
		y[0] = 2;
		x[0] = (int)Math.pow(y[0], 2);
		
		for (int i = 1; i <= N; i++) {
			y[i] = 2 * y[i - 1] - 1;
			x[i] = (int)Math.pow(y[i], 2);
		}
		
		System.out.println(x[N]);
	}
}
