/*
Problem:  Generate All Binary
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1"
==================================================
Given an integer n. You need to generate all the binary strings of n characters representing bits.

Input: n = 2
Output: [00, 01, 10, 11]
Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
==================================================
*/

/*
Approach:
    1.left side always add 0 
    2.right side always add 1
    3.do backtracking when size is equal to n
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
        s += '1';
        funGenerateBinary(s,ans,n);
        s.pop_back();
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
    All possible strings are generated and each is validated.
Space Complexity: O(n) recursion depth (excluding result storage).
==================================================
*/