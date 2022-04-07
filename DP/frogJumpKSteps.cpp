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


// Using Meomization
// Time Complxity: O(n) * O(k)
// Space Complexity: O(n)
int f2(int idx, int heights[], int k, vector<int>& dp) {
  if(idx == 0) return 0;

  if(dp[idx] != -1) return dp[idx];
  int mmSteps = INT_MAX;
  for(int i = 1; i <= k; i++) {
    int jumps = f2(idx-i, heights, k, dp) + abs(heights[idx] - heights[idx-i]);
    mmSteps = min(jumps, mmSteps);
  }
  return dp[idx] = mmSteps;
}

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  // cout << "Energy used by the frog is: " << f1(n-1, arr, k) << endl;
  // vector<int> dp(n+1, -1);
  //   cout << "Energy used by the frog is: " << f2(n-1, arr, k, dp) << endl;

  // Using Tabulation Method
  vector<int> dp(n);
  dp[0] = 0;
  for(int i = 1; i < n; i++) {
    int mmSteps = INT_MAX;
    for(int j = 1; j <= k; j++) {
      if(i - j >= 0) {
        int jumps = dp[i-j] + abs(a[i] - a[i-j]);
        mmSteps = min(jumps, mmSteps);
      }
    }
    dp[i] = mmSteps;
  }
  cout << "Energy used by the frog is: " << dp[n-1] << endl;
  return 0;
}