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

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> nums[i][j];
    }
  }

  cout << "Ans: " << f(n-1, m-1) << endl;
  return 0;
}