#include <stdio.h>

int linearSearch(int *arr, int query, int siz){
	int i;
	for(i=0; i<siz; i++){
		if(arr[i]==query) return i;
	}
	return -1;
}

int main()
{
	int arr[] = {5,22,6,3,74,7,3,8,2334,6}, query=8;
	int pos = linearSearch(arr, query, 10);
	printf("%d\n", pos);
	return 0;
}