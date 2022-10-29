#include <bits/stdc++.h>
using namespace std;

int search(int mat[4][4], int n, int x)
{
	if (n == 0)
		return -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (mat[i][j] == x) {
				cout << "Element found at (" << i << ", "
					<< j << ")\n";
				return 1;
			}
	}

	cout << "n Element not found";
	return 0;
}

int main()
{
	int mat[4][4] = { { 10, 20, 30, 40 },
					{ 15, 25, 35, 45 },
					{ 27, 29, 37, 48 },
					{ 32, 33, 39, 50 } };
	search(mat, 4, 29);
	return 0;
}
