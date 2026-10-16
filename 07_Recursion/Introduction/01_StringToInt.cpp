/*
Problem:  8. String to Integer (atoi)
Platform: Recursion / Striver A2Z
Difficulty: Easy
Problem Link: "https://leetcode.com/problems/string-to-integer-atoi/description/?utm=codolio"
==================================================

==================================================
*/

/*
Algorithm:
We convert the string to an integer using recursion while following these steps:
    1. Skip leading whitespaces.
    2. Detect sign (+ or -).
    3. Recursively read digit characters and build the number.
    4. Stop when a non-digit character is found.
    5. Clamp the result within 32-bit signed integer limits
*/

#include <bits/stdc++.h>
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
    string s = "  -42 ";
    Solution obj;
    int ans = obj.myAtoi(s);
    cout << ans;
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(n) — each character is processed once
Space Complexity: O(n) — recursion stack in the worst case
==================================================
*/