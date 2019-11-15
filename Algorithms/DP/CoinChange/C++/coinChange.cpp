#include <bits/stdc++.h>
using namespace std;
int coins[] = {2, 3, 4}, counts[3], n, value;

void printCombinations(int startIndex, int totalAmount)
{
	if(startIndex >= n)
	{
		printf("%d =", value);
		for(int i = 0; i < n; i++)
		{
			if(i == n - 1)
				printf(" %d x %d\n", counts[i], coins[i]);
			else
				printf(" %d x %d,", counts[i], coins[i]);
		}
	}
	else if(startIndex == n - 1)
	{
		if(totalAmount % coins[startIndex] == 0)
		{
			counts[startIndex] = totalAmount / coins[startIndex];
			printCombinations(startIndex + 1, 0);
		}
	}
	else
	{
		for(int i = 0; i <= totalAmount / coins[startIndex]; i++)
		{
			counts[startIndex] = i;
			printCombinations(startIndex + 1, 
					totalAmount - coins[startIndex] * i);
		}
	}
}

int main()
{
	n = sizeof(coins) / sizeof(coins[0]);
	value = 20;
	printCombinations(0, value);
	return 0;
}
