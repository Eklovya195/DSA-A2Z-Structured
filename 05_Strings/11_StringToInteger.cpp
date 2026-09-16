/*
Problem: 8. String To Integer(atoi)
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/string-to-integer-atoi/description/"
==================================================
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
Step 2: "   -042" ('-' is read, so the result should be negative)
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
==================================================
*/

/*
==================================================
Algorithm:
    1. Initialize:
        ○ i = 0 (index)
        ○ sign = 1
        ○ result = 0 (use long to detect overflow)
    2. Skip leading spaces
    3. Check sign
        ○ '-' → sign = -1
        ○ '+' → sign = 1
    4. Read digits
        ○ result = result * 10 + digit
        ○ After each step, check:
            ■ if sign * result > INT_MAX → return INT_MAX
            ■ if sign * result < INT_MIN → return INT_MIN
    5. Return sign * result
==================================================

==================================================
Why Overflow Check Is Needed Early?
    If we wait until the end, the number may already overflow.
    So we check during construction, not after.
==================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long res = 0;
        //if whitespaces are present
        while(i<s.size() && s[i]==' ') i++;
        //if -ve sign is present
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-') sign = -1;
            i++; 
        } 
        //convert digits
        while(i<s.size() && isdigit(s[i])){
            res = res*10+(s[i]-'0');
            // if overflow
            if (sign * res > INT_MAX)
            return INT_MAX;
            if (sign * res < INT_MIN)
            return INT_MIN;
            i++; 
        }
        return sign*res;
    }
};

int main(){
    string s = " -042";
    Solution obj;
    cout << obj.myAtoi(s);
    return 0;
}

/*
==================================================
Time complexity: O(N)
Space Complexity:O(1)
==================================================
*/