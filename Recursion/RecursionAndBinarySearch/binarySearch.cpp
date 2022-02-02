#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int k) {
  if(high >= low) {
    int mid = (low + high) / 2;
    if(arr[mid] == k) {
      return mid;
    }
    if(arr[mid] > k) {
      return binarySearch(arr, low, mid - 1, k);
    }
    return binarySearch(arr, mid + 1, high, k);
  }
  return -1;
}

int main() {
  int n, k;
  cout << "Enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Enter the value to be search in array: " << endl;
  cin >> k;
  int result = binarySearch(arr, 0, n-1, k);
  if(result == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index: " << result << endl;
  }
}