import java.util.Arrays;

public class selection_sort {
    public static void main(String[] args) {
        int[] arr={-12,12,45,-67,-1,-99,-94,0,-3,99};
        selection(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void selection(int[] arr){
        int temp=0;
        for(int i=1;i<arr.length;i++){
            int a=max(arr,i);
            temp=arr[a];
            arr[a]=arr[arr.length-i];
            arr[arr.length-i]=temp;
        }
    }
    static int max(int[] arr,int b){
        int maximum=0;
        for(int i=0;i<=arr.length-b;i++){
            if(arr[i]>arr[maximum]){
                maximum=i;
            }
        }return maximum;
    }
}
