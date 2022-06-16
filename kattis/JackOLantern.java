import java.util.Scanner;

class JackOLantern {
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int t = scan.nextInt();
        int m = scan.nextInt();
        System.out.println(n * t * m);
    }
}
