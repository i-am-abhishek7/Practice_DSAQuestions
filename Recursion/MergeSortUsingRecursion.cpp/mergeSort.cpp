#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end) {
  // calculate the mid of array
  int mid = (start + end) / 2;

  // calculate the length of two array
  int len1 = mid - start + 1;
  int len2 = end - mid;

  // creating array
  int *firstArray = new int[len1];
  int *secondArray = new int[len2];

  int mainArrayIndex = start;
  for (int i = 0; i < len1; i++) {
    firstArray[i] = arr[mainArrayIndex++];
  }
  mainArrayIndex = mid + 1;
  for (int i = 0; i < len2; i++) {
    secondArray[i] = arr[mainArrayIndex++];
  }
  
  // merge both arrays
  int index1 = 0;
  int index2 = 0;
  mainArrayIndex = start;

  while(index1 < len1 && index2 < len2) {
    if(firstArray[index1++] < secondArray[index2++]) {
      arr[mainArrayIndex++] = firstArray[index1++]; 
    } else {
      arr[mainArrayIndex++] = secondArray[index2++];
    }
  }

  while(index1 < len1) {
    arr[mainArrayIndex++] = firstArray[index1++]; 
  }

  while(index2 < len2) {
    arr[mainArrayIndex++] = secondArray[index2++];
  }
}

void mergeSort(int *arr, int start, int end) {
  if(start >= end) return;

  // calculate the mid 
  int mid = (start + end) / 2;

  // call recursion for left side
  mergeSort(arr, start, mid);

  // call recursion for right side
  mergeSort(arr, mid+1, end);

  // merge both arrays
  merge(arr, start, end);
}

int main() {
  int n;
  cout << "Enter the size of array: " << endl;
  cin >> n;
  int arr[n];
  cout << "Enter the element in array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  mergeSort(arr, 0,  n-1);
  cout << "Array after merge sort: " << endl;
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}