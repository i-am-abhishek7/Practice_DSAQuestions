#include<bits/stdc++.h>
using namespace std;

int findSum(int arr[], int n) {
  if(n == 0) return 0;
  if(n == 1) return arr[0];
  return arr[0] + findSum(arr + 1, n -1);
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int result = findSum(arr, n);
  cout << "The sum of the array elements is: " << result << endl;
  return 0;
}