/*
Problem:  131. Palindrome Partitioning
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/palindrome-partitioning/description/?utm=codolio"
==================================================
Explanation
You are given a string s. Your task is to split (partition) the string into substrings such that every
substring is a palindrome.
A palindrome reads the same from left to right and right to left.
You must return all possible such partitions.


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
    The recursion ends when the full string is consumed.
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
        //outer for loop is cutting slice
        //cutting size 1 slice -> size 2 slice -> size 3 slice
        for(int i=idx;i<s.size();i++){
            if(ispalindrome(s,idx,i)){
                subset.push_back(s.substr(idx,i-idx+1));
                //this function goes deep of each slice and check for further remaining string letters
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
    string s = "aab";
    Solution obj;
    vector<vector<string>> ans = obj.partition(s);
    for(const auto& row:ans){
        cout << "[";
        for(string ans:row){
            cout << ans << ",";
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