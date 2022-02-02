#include<bits/stdc++.h>
using namespace std;

bool isSortedArray(int arr[], int n) {
  if(n == 0 || n == 1) return true;
  if(arr[0] > arr[1]) return false;
  return isSortedArray(arr + 1, n - 1);
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bool result = isSortedArray(arr, n);
  cout << result << endl;
  return 0;
}