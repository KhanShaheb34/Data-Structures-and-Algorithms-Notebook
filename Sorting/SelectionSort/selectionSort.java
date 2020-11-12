import java.util.Scanner;
public class SelectionSort {
public static void main(String args[]) {

	Scanner scanner = new Scanner(System.in);
	int arrayLimit = scanner.nextInt();
	int[] intArray = new int[arrayLimit];

	for (int i = 0; i < arrayLimit; i++) {
		intArray[i] = scanner.nextInt();
	}
	for (int lastIndex = intArray.length - 1; lastIndex > 0; lastIndex--) {
		int large = 0;
		for (int i = 1; i <= lastIndex; i++) {
			if (intArray[i] > intArray[large]) {
				large = i;
			}
		}
		swap(intArray, large, lastIndex);
	}
	for (int i = 0; i < intArray.length; i++) {
		System.out.println(intArray[i]);
	}
}

public static void swap(int[] arr, int i, int j) {
	if (i == j) {
		return;
	}
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
}
