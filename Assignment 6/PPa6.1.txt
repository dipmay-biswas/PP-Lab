import java.util.Scanner;

public class Java {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of inputs : ");
        int n = scanner.nextInt();
        int[] roll = new int[n];
        String[] names = new String[n];
        System.out.println("Enter " + n + " names and roll no.s :");
        for (int i = 0; i < n; i++) {
            names[i] = scanner.next();
            roll[i] = scanner.nextInt();
        }
        System.out.println("Inputs :");
        for (int i = 0; i < n; i++) {
            System.out.println("Name : " + names[i] + " , Roll No : " + roll[i]);
        }
    }
}
