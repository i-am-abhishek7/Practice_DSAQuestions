#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int>& arr1, vector<int>& arr2) {
  vector<int> ans;
  for (int i = 0; i < arr1.size(); i++) {
    int element = arr1[i];
    for (int j = 0; j < arr2.size(); j++) {
      if(element < arr2[j]) break;
      if(element == arr2[j]) {
        ans.push_back(element);
        arr2[j] = INT_MIN;
        break;
      }
    }
  }
  return ans;
}

void printArray(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }  
}

int main() {
  int n1, n2;
  cin >> n1 >> n2;
  vector<int> arr1(n1);
  vector<int> arr2(n2);
  for (int i = 0; i < n1; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> arr2[i];
  }

  vector<int> ans = findIntersection(arr1, arr2);
  printArray(ans);
  return 0;
}