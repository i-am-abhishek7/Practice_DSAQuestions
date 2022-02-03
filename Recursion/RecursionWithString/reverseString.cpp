#include<bits/stdc++.h>
using namespace std;

// Method 1 // Using swaping
void reverseString(string &str, int i, int j) {
  if(i > j) {
    return;
  }
  swap(str[i], str[j]);
  i++;
  j--;
  reverseString(str, i, j);
}


// Method 2 // Using recursion call stack
void reverString1(string str) {
  if(str.length() == 0) {
    return;
  }
  reverString1(str.substr(1));
  cout << str[0];
} 

int main() {
  string s;
  cout << "Enter a string: ";
  cin >> s;
  reverseString(s, 0, s.length() - 1);
  // reverString1(s);
  cout << s << endl;
  return 0;
}