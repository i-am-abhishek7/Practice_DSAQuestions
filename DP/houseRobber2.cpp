// Similar logic of maximumNonAdjacentSum question


/* Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
*/
#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> nums) {
  int n = nums.size();
  int prev = nums[0];
  int prev2 = 0;
  for(int i = 1; i < nums.size(); i++) {
    int take = nums[0];
    if(i > 1) take += prev2;
    
    int notTake = 0 + prev;
    int curri = max(take, notTake);

    prev2 = prev;
    prev = curri;
  }
  return prev;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  
  vector<int> temp1, temp2;
  for(int i = 0; i < nums.size(); i++) {
    if(i != 0) temp1.push_back(nums[i]);
    if(i != n-1) temp2.push_back(nums[i]);
  }

  cout << "Ans: " << max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2)) << endl;

  return 0;
}