#include<bits/stdc++.h>
using namespace std;

// Using Recursion
// Time Complexity: O(2^m*n)
// Space Complexity: O(m-1, n-1) path length
int f(int row, int col) {
  if(row == 0 && col == 0) return 1;
  if(row < 0 || col < 0) return 0;

  int up = f(row-1, col);
  int left =  f(row, col-1);
  return up + left;
}

int f1(int row, int col, vector<vector<int>>& dp) {
  if(row == 0 && col == 0) return 1;
  if(row < 0 || col < 0) return 0;

  if(dp[row][col] != -1) return dp[row][col];
  
  int up = f1(row-1, col, dp);
  int left = f1(row, col-1, dp);
  
  return dp[row][col] = up + left;
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

  // cout << "Ans: " << f(n-1, m-1) << endl;

  vector<vector<int>> dp(n, vector<int>(m, -1));
  cout << "Ans: " << f1(n-1, m-1, dp) << endl;
  return 0;
}