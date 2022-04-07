#include<bits/stdc++.h>
using namespace std;


// Using Recursion
// Time Complexity: O(2^n)
// Space Compexity: O(n)
int f(vector<int> nums, int index) {
  if(index == 0) return nums[index];
  if(index < 0) return 0;

  int pick = nums[index] + f(nums, index-2);
  int notPick = f(nums, index-1);

  return max(pick, notPick);
}

// Using Memoization
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n)
int f1(vector<int> nums, int index, vector<int>& dp) {
  if(index == 0) return nums[index];
  if(index < 0) return 0;

  if(dp[index] != -1) return dp[index];

  int pick = nums[index] + f1(nums, index-2, dp);
  int notPick = f1(nums, index-1, dp);
  
  return dp[index] = max(pick, notPick);
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < nums.size(); i++) cin >> nums[i];
  // cout << "The maximum sum of non adjacent elements is: " << f(nums, nums.size()-1);
  vector<int> dp(n, -1);
  // cout << "The maximum sum of non adjacent elements is: " << f1(nums, nums.size()-1, dp);

  // Using Tabulation Method
  // Time Complexity: O(n)
  // Space Complexity: O(n)
  dp[0] = nums[0];
  for(int i = 1; i < n; i++) {
    int pick = nums[i];
    if(i > 1) pick += dp[i-2];
    int notPick = 0 + dp[i-1];
    dp[i] = max(pick, notPick);
  }
  cout << "The maximum sum of non adjacent elements is: " << dp[n-1];
  return 0;
}