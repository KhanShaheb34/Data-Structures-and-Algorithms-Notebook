#include <bits/stdc++.h>
using namespace std;

int ChineseRemainder(int num[], int rem[]) {
  int size = 3;
  int x = 0;

  while (true) {
    int i;
    for (i = 0; i < size; i++)
      if (x%num[i]!=rem[i])
        break;

    if (i==size) return x;
    x++;
  }
  return x;
}

int main() {
  int num[] = {3, 4, 7};
  int rem[] = {2, 3, 3};
  int chineseRemainder = ChineseRemainder(num, rem);
  cout << chineseRemainder << endl;
  return 0;
}
