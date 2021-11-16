import java.util.Scanner;

public class TheatreSquare {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextInt();
		long m = scan.nextInt();
		long a = scan.nextInt();
		
		TheatreSquare theatreSquare = new TheatreSquare();
		
		long lengthFlagstones = theatreSquare.getFlagstones(n, a);
		long widthFlagstones = theatreSquare.getFlagstones(m, a);
		System.out.println(lengthFlagstones * widthFlagstones);
	}
	
	private long getFlagstones(long size, long flagstoneSize) {
		return (long)Math.ceil(size / (double)flagstoneSize);
	}
}
