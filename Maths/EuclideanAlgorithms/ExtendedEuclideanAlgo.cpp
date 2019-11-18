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

int main() {
  int a, b, x = 0, y = 0;
  cin >> a >> b;
  int gcd = calculateGCD(a, b, &x, &y);
  cout << gcd << endl;
  cout << x << endl;
  cout << y << endl;
  return 0;
}
