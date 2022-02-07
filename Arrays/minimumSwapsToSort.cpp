#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int>& arr) {
  int n = arr.size();
  int count = 0;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    v[i] = {arr[i], i};
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if(v[i].second == i) continue;
    else {
      count++;
      swap(v[i], v[v[i].second]);
      i--;
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "The minimum swaps required to sort array is: " << minSwap(arr) << endl;
  return 0;
}