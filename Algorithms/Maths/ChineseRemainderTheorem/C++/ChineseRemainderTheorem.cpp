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

int ChineseRemainder(int num[], int rem[]) {
  int size = 3;
  int product = 1;
  for (int i = 0; i < size; i++)
    product *= num[i];

  int CR = 0;

  for (int i = 0; i < size; i++)
    CR += rem[i] * (product / num[i]) * MMI((product / num[i]), num[i]);

  CR %= product;
  return CR;
}

int main() {
  int num[] = {3, 4, 5};
  int rem[] = {2, 3, 1};
  int chineseRemainder = ChineseRemainder(num, rem);
  cout << chineseRemainder << endl;
  return 0;
}
