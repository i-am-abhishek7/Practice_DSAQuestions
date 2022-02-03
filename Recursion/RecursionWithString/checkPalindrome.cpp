#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string str, int i) {
  if(i > (str.length() - 1)) return true;
  if(str[i] != str[str.length() - i - 1]) return false;
  return checkPalindrome(str, i+1);
}

int main() {
  string str;
  cout << "Enter a string: " << endl;
  cin >> str;
  bool result = checkPalindrome(str, 0);
  if(result) {
    cout << "It is a palindrome." << endl;
  }  else {
    cout << "It is not a palindrome." << endl;
  }
  return 0;
}