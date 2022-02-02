#include<bits/stdc++.h>
using namespace std;

int nStairs(int n) {
  if(n < 0) return 0;
  if(n == 0) return 1;
  return nStairs(n-1) + nStairs(n-2);
}

int main() {
  int n;
  cout << "Enter the value of n: " << endl;
  cin >> n;
  int result = nStairs(n);
  cout << result << endl;
  return 0;
}