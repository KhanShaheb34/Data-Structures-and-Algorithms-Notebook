#include <bits/stdc++.h>
using namespace std;

int MMI(int a, int m) {
  a = a%m;
  for (int i = 1; i < m; i++)
    if((a*i)%m == 1)
      return i;

  return -1;
}

int main() {
  int a, m;
  cin >> a >> m;
  int mmi = MMI(a, m);
  cout << mmi << endl;
  return 0;
}
