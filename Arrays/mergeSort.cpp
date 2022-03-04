#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int low, int mid, int high) {
  int n1 = mid-low+1;
  int n2 = high-mid;

  int a[n1];
  int b[n2];

  for(int i = 0; i < n1; i++) {
    a[i] = arr[low+i];
  }

  for(int i = 0; i < n2; i++) {
    b[i] = arr[mid+1+i];
  }

  int i = 0;
  int j = 0;
  int k = low;

  while(i < n1 && j < n2) {
    if(a[i] < b[j]) {
      arr[k] = a[i];
      k++;
      i++;
    } else {
      arr[k] = b[j];
      j++;
      k++;
    }
  }

  while(i < n1) {
    arr[k] = a[i];
    k++; i++;
  }

  while(j < n2) {
    arr[k] = b[j];
    k++; j++;
  }
}

void mergeSort(int *arr, int low, int high) {
  if(low < high) {
    int mid = (low+high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  mergeSort(arr, 0, n-1);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  } cout << endl;
  return 0;
}