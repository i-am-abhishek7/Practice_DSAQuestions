#include<bits/stdc++.h>
using namespace std;

int aPowerb(int a, int b) {
  if(b == 0) return 1;
  if(b == 1) return a;
  if(b % 2 == 0) {
    return aPowerb(a, b/2) * aPowerb(a, b/2);
  } else {
    return a * (aPowerb(a, b/2) * aPowerb(a, b/2));
  }
} 

int main() {
  int a, b;
  cout << "Enter the value of a and b: " <<endl;
  cin >> a >> b;
  int result = aPowerb(a, b);
  cout << result << endl;
  return 0;
}