/*Kadane's Algorithm is an algorithm used to find the largest sum of the contiguous sub-array from the given array*/
//This is an approach to find the largest sum of the sub-array in O(n) time complexity.
#include<bits/stdc++.h>
using namespace std;
//This is the function for Kadane's Algorithm
int kadaneAlgo(int *arr,int n){
	int sum = INT_MIN, curr_sum = 0;
	for(int i=0;i<n;i++){
		curr_sum += arr[i];
		if(curr_sum > sum)	sum = curr_sum;
		if(curr_sum < 0)	curr_sum = 0;
	}
	return sum;
}
int main(){
	//This is the code for input-output operations through files
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int arr[n];			//Array of size n-elements
	cout<<"Enter the elements of the array :"<<endl;
	for(int i=0;i<n;i++)	cin>>arr[i];
	int sum = kadaneAlgo(arr,n);		//Function Calling
	cout<<"The largest sum of the subarray is : "<<sum;
	return 0;
}
