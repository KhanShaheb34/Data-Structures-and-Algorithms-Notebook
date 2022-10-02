package dsa;

import java.util.Arrays;

public class bubble_sort {
    public static void main(String[] args) {
        int[] arr={-12,12,45,-67,-1,-99,-94,0,-3,99};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void sort(int[] arr){
//        boolean swap=false;
        int i=1;
        int a=arr.length;
        while(i<a){
            boolean swap=false;
            for(int j=0;j<a-i;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap=true;
                }
            }
            if(!swap){
                break;
            }
            i=i+1;
        }
    }
}
