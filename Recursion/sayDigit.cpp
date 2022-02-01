#include<bits/stdtr1c++.h>
using namespace std;

void sayDigit(int n, string arr[]) {
  if(n == 0) return;
  int digit = n % 10;
  n = n / 10;
  sayDigit(n, arr);
   cout << arr[digit] << " ";
}

int main() {
  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  int number;
  cout << "Enter any number: " << endl;
  cin >> number;
  sayDigit(number, arr);
  return 0;
}