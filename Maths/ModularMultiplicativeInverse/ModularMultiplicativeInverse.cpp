#include <bits/stdc++.h>
using namespace std;

int calculateGCD(int a, int b, int *x, int *y){
  if(b==0){
    *x = 1;
    *y = 0;
    return a;
  }
  int tempX, tempY;
  int gcd = calculateGCD(b, a%b, &tempX, &tempY);
  *x = tempY;
  *y = tempX - (a/b) * tempY;
  return gcd;
}

int MMI(int a, int m) {
  int x, y;
  int gcd = calculateGCD(a, m, &x, &y);

  if(gcd != 1) {
    cout << "Not Possible" << endl;
    return -1;
  } else {
    x = (x%m + m) % m;
    return x;
  }
}

int main() {
  int a, m;
  cin >> a >> m;
  int mmi = MMI(a, m);
  cout << mmi << endl;
  return 0;
}
