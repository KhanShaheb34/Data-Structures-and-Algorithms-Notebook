package dsa;

import java.util.Arrays;

public class insertion_sort {
    public static void main(String[] args) {
        int[] arr={4,3,5,2,1};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void sort(int[] arr){
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j>=1;j--){
                if(arr[j]<arr[j-1]){
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
                else{
                    break;
                }
            }
        }
    }
}
