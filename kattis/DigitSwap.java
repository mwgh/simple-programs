import java.util.Scanner;

class DigitSwap {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        String s = Integer.toString(scanner.nextInt());
        int swapped = Integer.parseInt("" + s.charAt(1) + s.charAt(0));
		System.out.println(swapped);
	}
}
