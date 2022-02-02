#include<bits/stdc++.h>
using namespace std;

bool linerSearch(int arr[], int n, int k) {
  if(n == 0) return false;
  if(arr[0] == k) return true;
  return linerSearch(arr+1, n-1, k);
}

int main() {
  int n, k;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> k;
  bool result = linerSearch(arr, n, k);
  cout << result << endl;
  return 0;
}