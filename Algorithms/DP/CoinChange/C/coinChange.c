#include <stdio.h>
#include <string.h>

int count(int s[], int m, int n)
{
	int table[n + 1], i, j;
	memset(table, 0, sizeof(table));
	table[0] = 1;

	for(i = 0; i < m; i++)
	{
		for(j = s[i]; j <= n; j++)
		{
			table[j] += table[j - s[i]];
		}
	}
	return table[n];
}

int main()
{
	int arr[] = {2, 3, 4};
	int m = sizeof(arr) / sizeof(arr[0]);
	int n = 5;
	printf("%d\n", count(arr, m, n));
	return 0;
}
