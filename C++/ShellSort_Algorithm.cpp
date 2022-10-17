#include <iostream> 
#include <bits/stdc++.h>
// Using C++ STL, it makes the code more robust, reusable and solid
using namespace std; 

// shellsort implementation
// replaces const arr to pass by reference and hence the space utilized will be less
int shellSort(vector<int> &arr, int N) 
{ 
    for (int gap = N/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < N; i += 1) 
        { 
            //sort sub lists created by applying gap 
            int temp = arr[i]; 
            int j; 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int main() 
{ 
    vector<int> arr;
    // Vectors are the same as dynamic arrays with the ability to resize itself automatically 
    // when an element is inserted or deleted, with their storage being handled automatically by the container
    // int arr[] = {45,23,53,43,18,24,8,95,101}, i; 
    arr.push_back(45);
    arr.push_back(23);
    arr.push_back(53);
    arr.push_back(43);
    arr.push_back(18);
    arr.push_back(24);
    arr.push_back(8);
    arr.push_back(95);
    arr.push_back(101);
    // We can also use arr.emplace_back() to enter the elements in the vector

    //Calculate size of array 
    // int N = sizeof(arr)/sizeof(arr[0]); 
    int N = arr.size();
    // Using size function for vectors

    cout << "Array to be sorted: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 

    shellSort(arr, N); 

    cout << "\nArray after shell sort: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 

    return 0; 
}
