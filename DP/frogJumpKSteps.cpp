#include<bits/stdc++.h>
using namespace std;

// Using Recursion
// Time Complexity: O(n) * O(k)
// Space Complexity: O(n) + O(n)
int f1(int idx, int heights[], int k) {
  if(idx == 0) return 0;
  int mmSteps = INT_MAX;
  for(int j = 1; j <= k; j++) {
    if(idx-j >= 0) {
      int jumps = f1(idx-j, heights, k) + abs(heights[idx] - heights[idx-j]);
      mmSteps = min(jumps, mmSteps);
    }
  }
  return mmSteps;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  cout << "Energy used by the frog is: " << f1(n-1, arr, 5) << endl;
  return 0;
}