#include <stdio.h>

void swap(int *a, int *b){
	int t=(*a);
	(*a)=(*b);
	(*b)=t;
}

void bublleSort(int *arr, int siz){
	int i, j;
	for(i=0; i<siz; i++){
		for (j = 0; j < siz-i; ++j)
		{
			if(arr[j]>arr[j+1]) swap(&arr[j], &arr[j+1]);
		}
	}
}

int main()
{
	int arr[] = {5,22,6,3,74,7,3,8,2334,6}, i;
	bublleSort(arr, 10);
	for(i=0; i<10; i++) printf("%d\t", arr[i]);
	return 0;
}