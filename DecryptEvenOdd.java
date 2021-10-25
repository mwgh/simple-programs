import java.util.Scanner;

public class DecryptEvenOdd {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String encrypted = scanner.next();
        String key = scanner.next();
        final int MAX_LENGTH = encrypted.length();

        char[] decrypted = new char[MAX_LENGTH];
        final char START = 'A';
        final char END = 'Z';

        int index = 0;
        for (char encryptedChar : encrypted.toCharArray()) {
            final char KEY_CHAR = key.charAt(index);
            char shift = (char) (KEY_CHAR - START);

            if (index % 2 == 0) {
                // even index decrypt: shift backward
                decrypted[index] = (char) (encryptedChar - shift);
                if (decrypted[index] < START) {
                    char difference = (char) (START - decrypted[index]);
                    decrypted[index] = (char) (END - difference + 1);
                }
            } else {
                // odd decrypt: shift forward
                decrypted[index] = (char) (encryptedChar + shift);
                if (decrypted[index] > END) {
                    char difference = (char) (decrypted[index] - END);
                    decrypted[index] = (char) (START + difference - 1);
                }
            }

            index++;
        }

        String decryptedResult = new String(decrypted);
        System.out.println(decryptedResult);
    }
}
