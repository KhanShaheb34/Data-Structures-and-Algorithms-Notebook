#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int part(int nums[], int start, int end){
	int pivot = nums[end];
	int i=start-1;
	for(int j=0; j<end; j++){
		if(nums[j]<pivot) {
			i++;
			swap(&nums[i], &nums[j]);
		}
	}
	swap(&nums[i+1], &nums[end]);
	return (i+1);
}

void quickSort(int nums[], int start, int end){
	if(start < end){
		int pos = part(nums, start, end);
		
		quickSort(nums, start, pos-1);
		quickSort(nums, pos+1, end);
	}
}

int main(){
	int nums[5];
	for (int i=0; i<5; i++){
		scanf("%d", &nums[i]);
	}
	quickSort(nums, 0, 4);
	for(int i=0; i<5; i++) cout<<nums[i]<<"\t";
}
