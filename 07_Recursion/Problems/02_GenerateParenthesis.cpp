/*
Problem:  22. Generate Parentheses
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/generate-parentheses/description/?utm=codolio"
==================================================
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
==================================================
*/

//Brute force Approach:
/*
Approach:
    1. Generate all sequences of length 2n.
    2. For each sequence:
        ○ Traverse the string.
        ○ Increase balance for '(', decrease for ')'.
        ○ If balance becomes negative at any point → invalid.
        ○ At the end, balance must be 0.
    3. Store only valid sequences
*/
/*
#include <bits/stdc++.h>
using namespace std;

// Function to check if parentheses string is valid
bool isValid(string s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}
void generateAll(string curr, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        if (isValid(curr)) res.push_back(curr);
        return;
    }
    generateAll(curr + '(', n, res);
    generateAll(curr + ')', n, res);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generateAll("", n, res);
    return res;
}

int main(){
    int n = 2;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout << "[" << ans[i] << "]\n";
    }
    return 0;
}
*/


/*
Algorithm:
    1.Start with an "(" string.
    2. Maintain counts of open and close.
    3. If open < n, add '(' and recurse.
    4. If close < open, add ')' and recurse.
    5. When opencnt = closecnt = n return.
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^(2n) × n)
    All possible strings are generated and each is validated.
Space Complexity: O(n) recursion depth (excluding result storage).
==================================================
*/

//Recursive Approach(Bactracking):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void funGenerate(string &s,vector<string> &ans,int opencnt,int closecnt,int n){
        //base case
        if(opencnt == n && closecnt == n){
            ans.push_back(s);
            return;
        }
        //for adding open parenthesis
        if(opencnt<n){
            s = s + '(';
            funGenerate(s,ans,opencnt+1,closecnt,n);
            s.pop_back();
        }
        //for adding close parenthesis
        if(closecnt<opencnt){
            s = s + ')';
            funGenerate(s,ans,opencnt,closecnt+1,n);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        string s = "(";
        vector<string> ans;
        int opencnt = 1;
        int closecnt = 0;
        funGenerate(s,ans,opencnt,closecnt,n);
        return ans;
    }
};

int main(){
    int n = 2;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout << "[" << ans[i] << "]\n";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(C(n) × n)
    where C(n) is the nth Catalan number (number of valid sequences).
    catalan no C(n) = 1/(n+1)*2nCn
Space Complexity: O(n) recursion depth plus space to store all valid combinations.
==================================================
*/