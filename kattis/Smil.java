import java.util.Scanner;

class Smil {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
        String[] smilies = {":)", ";)", ":-)", ";-)"};
        String s = scanner.next();
        for (String smilie : smilies) {
            String temp = s;
            int i;
            int from = 0;
            do {
                i = temp.indexOf(smilie, from);
                if (i != -1) {
                    System.out.println(i);
                    from += i + smilie.length();
                }
            } while (i != -1);
        }
	}
}
