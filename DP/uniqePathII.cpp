#include<bits/stdc++.h>
using namespace std;

// Using Recursion
int f(int i, int j, vector<vector<int>>& mat) {
  if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;

  int up = f(i-1, j, mat);
  int left = f(i, j-1, mat);
  return up + left;
}

// Using Memoization
int f1(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
  if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int up = f1(i-1, j, mat, dp);
  int left = f1(i, j-1, mat, dp);
  return dp[i][j] = up + left;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> nums[i][j];
    }
  }
  // cout << "Ans: " << f(n-1, m-1, nums);
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // cout << "Ans: " << f1(n-1, m-1, nums, dp);

  // Using Tabulation
  int dp[n][m];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(nums[i][j] == -1) dp[i][j] = 0;
      else if(i == 0 && j == 0) dp[i][j] = 1;
      else {
        int up = 0;
        int left = 0;
        if(i > 0) up = dp[i-1][j];
        if(j > 0) left = dp[i][j-1];
        dp[i][j] = up + left;
      }
    }
  }
  cout << "Ans: " << dp[n-1][m-1] << endl;
  return 0;
}