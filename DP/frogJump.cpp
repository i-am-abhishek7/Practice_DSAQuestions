#include<bits/stdc++.h>
using namespace std;

int f(int idx, int heights[]) {
  if(idx == 0) return 0;

  int left = f(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
  int right = INT_MAX;
  if(idx > 1) right = f(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
  return min(left, right);
}

// Using Memoization
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n)
int f1(int idx, int heights[], vector<int>& dp) {
  if(idx == 0) return 0;

  if(dp[idx]!= -1) return dp[idx];
  int left = f1(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]);
  int right = INT_MAX;
  if(idx > 1) right = f1(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]);
  return dp[idx] = min(left, right);
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  vector<int> dp(n+1, -1);
  cout << f1(n-1, arr, dp);
  return 0;
}