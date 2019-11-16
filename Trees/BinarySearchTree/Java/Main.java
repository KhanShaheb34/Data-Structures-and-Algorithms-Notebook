import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Tree tree = new Tree();

        int N = scanner.nextInt();
        for (int i = 0; i < N; i++){
            float val = scanner.nextFloat();
            tree.addNode(val);
        }
        tree.prefix();

        float q = scanner.nextFloat();
        boolean found = tree.search(q);

        if(found) System.out.println("Found");
        else System.out.println("Not Found");

    }
}
