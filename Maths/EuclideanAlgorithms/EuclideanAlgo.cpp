#include <bits/stdc++.h>
using namespace std;

int calculateGCD(int a, int b){
  if(b==0) return a;
  return calculateGCD(b, a%b);
}

int main() {
  int a, b;
  cin >> a >> b;
  int gcd = calculateGCD(a,b);
  cout << gcd << endl;
  return 0;
}
