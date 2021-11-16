import java.util.Scanner;

class Reverse {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numbers = scanner.nextInt();
		int[] items = new int[numbers];
		for (int i = 0; i < numbers; i++) {
			int item = scanner.nextInt();
			items[i] = item;
		}
		for (int i = numbers - 1; i >= 0; i--) {
			System.out.println(items[i]);
		}
	}
}
