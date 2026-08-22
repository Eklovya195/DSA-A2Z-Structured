/*
Problem: 14. Longest Common Prefix
Problem Statement: Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string ""
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/longest-common-prefix/description/"
==================================================
Input: strs = ["flower","flow","flight"]
Output: "fl"
==================================================
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> strs = {"flower","flow","flight"};
    //sort lexicographically
        sort(strs.begin(),strs.end());
        //take first and last string
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";
        int minLen = min(first.size(),last.size());
        for(int i=0;i<minLen;i++){
            if(first[i]!=last[i]){
                break;
            }
            ans += first[i];
        }
        cout << ans;
        return 0;
}

/*
==================================================
Time Complexity:O(N log N + M)
○ Sorting → O(N log N)
○ Prefix comparison → O(M)
(N = number of strings, M = min string length)
Space Complexity:O(M) for storing the prefix
==================================================
*/