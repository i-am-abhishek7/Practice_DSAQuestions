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

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> nums[i][j];
    }
  }
  cout << "Ans: " << f(n-1, m-1, nums);
  return 0;
}