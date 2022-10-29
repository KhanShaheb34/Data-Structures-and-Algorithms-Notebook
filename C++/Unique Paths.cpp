#include<bits/stdc++.h>
using namespace std;

int UniquePathHelper(int i, int j, int r, int c, vector<vector<int>>& A){
	 if(i == r || j == c){
	 return 0 ;
}

	if(A[i][j] == 1){
	 return 0 ;
	}
	
	if(i == r-1 && j == c-1){
	 return 1 ;
	}

	return UniquePathHelper(i+1, j, r, c, A) +
			UniquePathHelper(i, j+1, r, c, A) ;
}


int uniquePathsWithObstacles(vector<vector<int>>& A)
{
	int r = A.size(), c = A[0].size();	
	return UniquePathHelper(0, 0, r, c, A) ;
}

int main()
{
 vector<vector<int>> A = { { 0, 0, 0 },
							{ 0, 1, 0 },
							{ 0, 0, 0 } };
							
 cout << uniquePathsWithObstacles(A) << " \n";											
}
