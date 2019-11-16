#include<bits/stdc++.h>
using namespace std;

void merge(int nums[], int left, int mid, int right){
	int first = mid - left + 1, last = right -mid;
	int leftArr[first], rightArr[last];
	
	for(int i=0; i<first; i++){
		leftArr[i] = nums[left+i];
	}
	for(int i=0; i<last; i++){
		rightArr[i] = nums[mid+i+1];
	}
	
	int i=0, j=0, k=left;
	while(i<first && j<last){
		if(leftArr[i]<=rightArr[j]){
			nums[k] = leftArr[i];
			i++;
		}
		else{
			nums[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while(i < first) {
		nums[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < last) {
		nums[k] = rightArr[j];
		j++;
		k++;
	}
}

void mergeSort(int nums[], int left, int right){
	if(left < right) {
		int mid = (left+right)/2;
		
		mergeSort(nums, left, mid);
		mergeSort(nums, mid+1, right);
		
		merge(nums, left, mid, right);
	}
}

int main(){
	int nums[5];
	for(int i=0; i<5; i++){
		scanf("%d", &nums[i]);
	}
	mergeSort(nums, 0, 4);
	for(int i=0; i<5; i++){
		printf("%d\t", nums[i]);
	}
}







