/*
Problem:  131. Palindrome Partitioning
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/palindrome-partitioning/description/?utm=codolio"
==================================================
Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
==================================================
*/

/*
Approach:
We use recursion + backtracking.
    At every index, we try to cut the string into substrings.
    For each substring:
        ● If it is a palindrome → choose it
        ● Recurse for the remaining string
        ● Backtrack to try other possibilities
    The recursion ends when the full string is consumed
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispalindrome(string st,int start,int end){
        while(start<end){
            if(st[start]!=st[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void funGenerate(int idx,string &s,vector<vector<string>> &ans,vector<string> &subset){
        if(idx == s.size()){
            ans.push_back(subset);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                subset.push_back(s.substr(idx,i-idx+1));
                funGenerate(i+1,s,ans,subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subset;
        funGenerate(0,s,ans,subset);
        return ans;
    }
};


int main(){
    string s = "a";
    Solution obj;
    vector<vector<string>> ans = obj.partition(s);
    for(auto row:ans){
        cout << "[";
        for(string st:row){
            cout << st << " ";
        }
        cout << "]\n";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^N * N)
    All possible partitions are explored, and palindrome checking costs O(N).
Space Complexity: O(2^N * N) + O(N)
    For storing all partitions and recursion stack
==================================================
*/