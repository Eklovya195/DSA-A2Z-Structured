/*
Problem: 1903. Largest Odd No in a String
Problem Statement: You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/largest-odd-number-in-string/description/"
==================================================
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
==================================================
*/

#include<bits/stdc++.h>
using namespace std;

string LargestOddNo(string num,int n){
    for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2 != 0) return num.substr(0,i+1);
        }
    return "";
}

int main(){
    string num = "22";
    int n = num.size();
    string ans = LargestOddNo(num,n);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N)
    (single pass from right + single pass from left)
Space Complexity: O(1)
    (only indices used, output excluded)
==================================================
*/