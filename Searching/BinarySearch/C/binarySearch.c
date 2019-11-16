#include<bits/stdc++.h>
using namespace std;

int binarySearch(int nums[], int start, int end, int query){
	if(end>1){
		int mid = (start + end) / 2;
		if(nums[mid]==query) return mid;
		else if(nums[mid]>query) binarySearch(nums, start, mid-1, query);
		else binarySearch(nums, mid+1, end, query);
	}
	else return -1;
}

int main(){
	int nums[5], query;
	for(int i=0; i<5; i++) cin>>nums[i];
	cin>>query;
	int pos = binarySearch(nums, 0, 4, query);
	if(pos!=-1) cout<<pos<<endl;
	else cout<<"Not found";
}
