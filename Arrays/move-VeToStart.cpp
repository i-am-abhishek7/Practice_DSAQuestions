#include<bits/stdc++.h>
using namespace std;

void moveElements(int arr[], int low, int high) {
  while(low <= high) {
    if(arr[low] < 0 && arr[high] < 0) {
      low++;
    } else if(arr[low] > 0 && arr[high] < 0) {
      swap(arr[low], arr[high]);
      low++;
      high--;
    } else if(arr[low] > 0 && arr[high] > 0) {
      high--;
    } else {
      low++;
      high--;
    }
  }
}


void printArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  moveElements(arr, 0, n-1);
  printArray(arr, n);
  return 0;
}