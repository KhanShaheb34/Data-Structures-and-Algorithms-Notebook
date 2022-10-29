#include <bits/stdc++.h>
using namespace std;

int pageFaults(int n, int c, int pages[]) {
	int count = 0;
	vector<int> v;
	int i;
	for (i = 0; i <= n - 1; i++) {
		auto it = find(v.begin(), v.end(), pages[i]);
		if (it == v.end()) {
			if (v.size() == c) {
				v.erase(v.begin());
			}
			v.push_back(pages[i]);
			count++;
		}
		else {
			v.erase(it);
			v.push_back(pages[i]);
		}
	}

	return count;
}

int main() {
	int pages[] = { 1, 2, 1, 4, 2, 3, 5 };
	int n = 7, c = 3;

	cout << "Page Faults = " << pageFaults(n, c, pages);
	return 0;
}
