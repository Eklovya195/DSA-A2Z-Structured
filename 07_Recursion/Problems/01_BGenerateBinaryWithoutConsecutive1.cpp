/*
Problem:  Generate All Binary without Consecutive 1's
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://takeuforward.org/practice/dsa/generate-binary-strings-without-consecutive-1s?utm=codolio&tab=code"
==================================================
Given an integer n. You need to generate all the binary strings of n characters representing bits.

Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.
==================================================
*/

/*
Approach:
    1. Use a recursive function with:
        ○ current string s being built
        ○ ans container
    2. If the current string s length becomes n, store it.
    3. Always try adding '0'.
    4. Add '1' only if the last character is not '1'
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void funGenerateBinary(string &s,vector<string> &ans,int n){
        //base case 
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        //left side add 0
        s += '0';
        funGenerateBinary(s,ans,n);
        //backtracking
        s.pop_back();

        //right side add 1
        //changes are made here only everything is similar
        if(s.empty() || s.back()!='1'){
            s += '1';
            funGenerateBinary(s,ans,n);
            s.pop_back();
        }
    }
    
    vector<string> binstr(int n) {
        string s;
        vector<string> ans;
        funGenerateBinary(s,ans,n);
        return ans;
    }
};


int main(){
    int n = 2;
    Solution obj;
    vector<string> ans = obj.binstr(n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^n)
    In the worst case, each position branches into two recursive calls.
Space Complexity: O(n)
    Due to recursion depth (call stack).
==================================================
*/