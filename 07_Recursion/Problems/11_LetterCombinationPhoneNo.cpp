/*
Problem: 17. Letter Combinations of a Phone Number
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/letter-combinations-of-a-phone-number/?utm=codolio"
==================================================
Explanation
You are given a string digits containing characters from '2' to '9'.
Each digit maps to certain letters on a phone keypad (like old mobile phones).
Your task is to generate all possible strings by replacing each digit with one of its mapped
letters, keeping the order same.
If the input string has length n, then each position contributes multiple choices, and we generate
combinations by choosing one letter per digit

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
==================================================
*/

/*
==================================================
Idea:
This is a backtracking problem.
At each index, we:
    ● Look at the digit
    ● Try all characters mapped to that digit
    ● Move to the next index
When we reach the end of the digit string, the current built string is a valid combination.
==================================================
*/

/*
==================================================
Algorithm:
    1. Create a mapping from digits (2–9) to letters.
    2. Use a recursive function with:
        ○ current index
        ○ current string being formed
    3. If index equals length of digits, store the string.
    4. Otherwise:
        ○ For the current digit, loop through all mapped letters
        ○ Append one letter and recurse to next index
==================================================
*/

//Recursive Approach(Backtracking Approach):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(int idx,vector<string> &ans,string &digits,string &subset,string mp[]){
        if(idx == digits.size()){
            ans.push_back(subset);
            return;
        }

        int digit = digits[idx]-'0';
        for(char c:mp[digit]){
            subset += c;
            funGenerate(idx+1,ans,digits,subset,mp);
            subset.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;

        string mp[] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string subset = "";
        funGenerate(0,ans,digits,subset,mp);
        return ans;
    }
};

int main(){
    string digits = "23";
    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}



/*
==================================================
Complexity Analysis:
Time Complexity: O(4^n) 
    Each digit can contribute up to 4 letters.
    as 7 and 9 mapped to 4 letters
Space Complexity: O(n)
    Recursion stack depth and temporary string length
==================================================
*/