#include <bits/stdc++.h>
using namespace std;

int ceilIndex(vector<int> &v, int l, int r, int key)
{
	while(r - l > 1)
	{
		int m = l + (r - l) / 2;
		if(v[m] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}

int lis(vector<int> &v)
{
	if(!v.size()) return 0;
	vector <int> tail(v.size(), 0);
	int len = 1;
	tail[0] = v[0];
	
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i] < tail[0])
			tail[0] = v[i];
		else if(v[i] > tail[len - 1])
			tail[len++] = v[i];
		else
			tail[ceilIndex(tail, -1, len - 1, v[i])] = v[i];
	}
	return len;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cout << lis(v) << endl;
}
