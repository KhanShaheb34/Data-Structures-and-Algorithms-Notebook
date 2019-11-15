/*
 *	Time Complexity: O(mn)
 *	Auxilary Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

string lcs(string &x, string &y)
{
	int m = x.length(), n = y.length();
	int L[2][n + 1];
	string ls;
	bool bin;
	for(int i = 0; i <= m; i++)
	{
		bin = i & 1;
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
			{
				L[bin][j] = 0;
			}
			else if(x[i - 1] == y[j - 1])
			{
				L[bin][j] = L[1 - bin][j - 1] + 1;
			}
			else
			{
				L[bin][j] = max(L[1 - bin][j], L[bin][j - 1]);
			}
		}
	}
	int i = m, j = n, index = L[bin][n];
	while(i > 0 && j > 0)
	{
		if(x[i - 1] == y[j - 1])
		{
			ls.push_back(x[i - 1]);
			i--; j--;
		}
		else if(L[1 - bin][j] > L[bin][j - 1])
		{
			i--;
			bin = i & 1;
		}
		else	j--;
	}
	reverse(ls.begin(), ls.end());
	return ls;
}

int main()
{
	string a, b;
	cout << "Enter first string: ";
	getline(cin, a);
	cout << "Enter second string: ";
	getline(cin, b);
	a = lcs(a, b);
	cout << "The LCS is: " << a << endl;
	cout << "Length: " << a.length() << endl;
	return 0;
}
