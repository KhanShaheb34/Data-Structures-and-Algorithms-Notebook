#include <bits/stdc++.h>
using namespace std;
#define MAX 11
#define var 2

int hashtable[var][MAX];
int pos[var];

void initTable()
{
	for(int j = 0; j < MAX; j++)
		for(int i = 0; i < var; i++)
			hashtable[i][j] = INT_MIN;
}

int hashx(int func, int key)
{
	if (func == 1)
		return key % MAX;

	return (key / MAX) % MAX;
}

void place(int key, int tableID, int cnt, int n)
{
	if(cnt == n)
	{
		cout << key << " unpositioned" << endl;
		cout << "Cycle present. REHASH.." << endl;
		return;
	}

	for(int i = 0; i < var; i++)
	{
		pos[i] = hashx(i + 1, key);
		if(hashtable[i][pos[i]] == key)
			return;
	}

	if(hashtable[tableID][pos[tableID]] != INT_MIN)
	{
		int dis = hashtable[tableID][pos[tableID]];
		hashtable[tableID][pos[tableID]] = key;
		place(dis, (tableID + 1) % var, cnt + 1, n);
	}
	else
		hashtable[tableID][pos[tableID]] = key;
}

void printTable()
{
	cout << "Final hash tables:" << endl;

	for(int i = 0; i < var; i++, cout << endl)
		for(int j = 0; j < MAX; j++)
			(hashtable[i][j] == INT_MIN) ? cout << "- " : cout << hashtable[i][j] << " ";

	cout << endl;
}

void cuckoo(int keys[], int n)
{
	initTable();

	for(int i = 0, cnt = 0; i < n; i++, cnt = 0)
		place(keys[i], 0, cnt, n);

	printTable();
}

int main()
{
	int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
	int n = sizeof(keys_1) / sizeof(int);

	cuckoo(keys_1, n);

	int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};
	int m = sizeof(keys_2) / sizeof(int);

	cuckoo(keys_2, m);

	return 0;
}
