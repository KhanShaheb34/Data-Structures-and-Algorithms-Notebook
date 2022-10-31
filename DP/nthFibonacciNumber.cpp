#include <bits/stdc++.h>
using namespace std;
int dp[10];

int fib(int n)
{
	if (n <= 1)
		return n;

	int first, second;

	if (dp[n - 1] != -1)
		first = dp[n - 1];
	else
		first = fib(n - 1);

	if (dp[n - 2] != -1)
		second = dp[n - 2];
	else
		second = fib(n - 2);

	return dp[n] = first + second;
}

int main()
{
	int n = 9;
	memset(dp, -1, sizeof(dp));
	cout << fib(n);
	getchar();
	return 0;	
}
