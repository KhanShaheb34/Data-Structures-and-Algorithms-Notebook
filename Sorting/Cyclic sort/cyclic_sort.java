import java.util.Arrays;

public class cyclic_sort {
    public static void main(String[] args) {
        int[] arr={4,3,5,2,1};
        cyclic(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void cyclic(int[] arr){
        int i=0;
        while(i<arr.length){
            if(arr[i]!=i+1){
                int temp=arr[arr[i]-1];
                arr[arr[i]-1]=arr[i];
                arr[i]=temp;
            }
            if(arr[i]==i+1){
                i++;
            }
        }
    }
}
