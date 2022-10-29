#include <bits/stdc++.h>
using namespace std;
#define r 4
#define c 5

bool findmatch(char mat[r], string pat, int x, int y,
			int nrow, int ncol, int level)
{
	int l = pat.length();
	if (level == l)
		return true;

	if (x < 0 || y < 0 || x >= nrow || y >= ncol)
		return false;
	if (mat[x][y] == pat[level]) {
		char temp = mat[x][y];
		mat[x][y] = '#';
        bool res = findmatch(mat, pat, x - 1, y, nrow, ncol, level + 1) |
				findmatch(mat, pat, x + 1, y, nrow, ncol, level + 1) |
				findmatch(mat, pat, x, y - 1, nrow, ncol, level + 1) |
				findmatch(mat, pat, x, y + 1, nrow, ncol, level + 1);
        mat[x][y] = temp;
		return res;
	}
	else
		return false;
}

bool checkMatch(char mat[r], string pat, int nrow, int ncol)
{
	int l = pat.length();
	if (l > nrow * ncol)
		return false;
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			if (mat[i][j] == pat[0])
				if (findmatch(mat, pat, i, j, nrow, ncol, 0))
					return true;
		}
	}
	return false;
}

int main()
{
	char grid[r] = { "axmy",
						"bgdf",
						"xeet",
						"raks" };

	if (checkMatch(grid, "geeks", r, c))
		cout << "Yes";
	else
		cout << "No";
return 0;
}
