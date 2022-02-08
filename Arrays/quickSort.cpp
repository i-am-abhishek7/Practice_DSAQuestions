#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e) {
  // take the pivot element
  int pivotElement = arr[s];
  
  // count all element that is greater than pivotElement
  int count = 0;
  for (int i = s+1; i <= e; i++) {
    if(arr[i] <= pivotElement) count++;
  }
  
  // place pivotElement to it's right position
  int pivotIndex = s + count;
  swap(arr[pivotIndex], arr[s]);

  // condition for < a | a | > a
  int i = s, j = e;
  while (i < pivotIndex && j > pivotIndex){
    while(arr[i] <= pivotElement) i++;
    while(arr[j] > pivotElement) j--;

    if(i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
  // base case
  if(s >= e) return;

  // partition 
  int p = partition(arr, s, e);

  // sort left part & right part
  quickSort(arr, s, p-1);
  quickSort(arr, p+1, e);
}

int main() {
  int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
  int n = 10;
  quickSort(arr, 0, n-1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}