/*
Problem: 3. Longest Substring Without Repeating Characters
Platform: Sliding Window And Two pointers / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/longest-substring-without-repeating-characters/description/"
==================================================
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
==================================================
*/

/*
Problem Statement: 
    You are given a string S.
    Your task is to find the length of the longest substring that contains no repeating characters.
    A substring must be continuous, and all characters inside it must be distinct.
*/

/*
Algorithm:
    Consider every possible starting index of a substring.
    For each starting index, extend the substring character by character.
    Use a seen array to track whether a character has already appeared.
    If a repeated character is found, stop extending the substring.
    Keep updating the maximum length found.
    Return the maximum length at the end.
*/

//Brute force Appraoch
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            // A lightweight boolean tracker for characters seen in the current substring.
            // Size 128 covers all standard ASCII characters. Takes almost 0 space.
            vector<bool> seen(256, false); 
            int len = 0;
            int j = i;
            // Fast O(1) array lookup
            while(j<n && !seen[s[j]]){
                seen[s[j]] = true;
                len++;
                j++;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};

int main(){
    string s = "abcabcbb";
    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}
*/


/*
==================================================
Time Complexity: O(n²)
    Nested loops check all possible substrings.
Space Complexity: O(256) == O(1)
    Fixed-size seen boolean array of 256 characters
==================================================
*/

//Sliding Window Approach (Optimal Solution)
/*
Algorithm:
        Use two pointers l (left) and r (right) to maintain a window of unique characters.
        Maintain a hash array storing the last index of each character.
        Move the right pointer forward.
        If a character is repeated, move the left pointer just after its last occurrence.
        Update the maximum window length.
        Continue until the end of the string
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[256];
        for(int i=0;i<256;i++) hash[i] = -1;
        int maxlen = 0,l = 0,r = 0;
        while(r<n){
            if(s[r]!=-1){
                l = max(l,hash[s[r]]+1);
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};

int main(){
    string s = "abcabcbb";
    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(n)
    Each character is processed once using two pointers.
Space Complexity: O(256) == O(1)
    Fixed-size seen boolean array of 256 characters
==================================================
*/