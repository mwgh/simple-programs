import java.util.Scanner;

class Pot {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			int P = scanner.nextInt();
			int power = P % 10;
			int number = P / 10;
			int value = (int)Math.pow(number, power);
			sum += value;
		}
		
		System.out.println(sum);
	}
}
