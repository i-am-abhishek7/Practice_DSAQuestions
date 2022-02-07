// You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

// Return the rearranged number with minimal value.

// Note that the sign of the number does not change after rearranging the digits.

 

// Example 1:

// Input: num = 310
// Output: 103
// Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
// The arrangement with the smallest value that does not contain any leading zeros is 103.

class Solution {
public:
    long long smallestNumber(long long num) {
        string number = to_string(abs(num));
        if(num >= 0) sort(number.begin(), number.end());
        else sort(number.begin(), number.end(), greater<char>());
        
        if(num > 0) {
            int index = number.find_first_not_of('0');
            swap(number[0], number[index]);
        }
        
        long long ans = stoll(number);
        if(num < 0) {
            ans *= -1;
        }
        return ans;
    }
};