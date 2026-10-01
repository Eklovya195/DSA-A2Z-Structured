/*
Problem: 424. Longest Repeating Character Replacement
Platform: Sliding Window And Two pointers / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/longest-repeating-character-replacement/description/?utm=codolio"
==================================================
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too
==================================================
*/

/*
Problem Statement: 
    You are given a string s consisting of uppercase English letters and an integer k.
    You are allowed to replace at most k characters in the string with any other uppercase letter.
    After performing at most k replacements, you need to find the length of the longest substring
    that contains only one repeating character.

*/

//Appraoch 1: Brute force 
/*
Algorithm:
    Try all possible substrings.
    For each substring:
        ○ Count frequency of characters.
        ○ Find the most frequent character.
        Calculate replacements needed = substring length - max frequency.
    If replacements ≤ k, update the answer.
    Return the maximum valid length found.
*/


/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            int hash[26] = {0};
            int maxfreq = 0;
            int changes = 0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxfreq = max(maxfreq,hash[s[j]-'A']);
                changes = (j-i+1)-maxfreq;
                if(changes<=k){
                    maxlen = max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

int main(){
    string s = "AABABBA";
    int k = 1;
    Solution obj;
    cout << obj.characterReplacement(s,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(n²)
Space Complexity: O(1)
    hash array is used of fixed size 26
==================================================
*/

//Better Approach (Sliding Window)
/*
Algorithm: 
    Use two pointers left and right to form a window.
    Maintain frequency of characters inside the window.
    Track the maximum frequency character in the window.
    If (window size - max frequency) > k, shrink window from left.
    Keep updating the maximum window size.
*/

/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l = 0,r = 0;
        int maxfreq = 0;
        int hash[26] = {0};
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            //while(changes>k)
            while(((r-l+1) - maxfreq)>k){
                hash[s[l]-'A']--;
                maxfreq = 0;
                for(int i=0;i<26;i++){
                    maxfreq = max(maxfreq,hash[i]-'A');
                }
                l++;
            }
            if(((r-l+1) - maxfreq)<=k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    string s = "AABABBA";
    int k = 1;
    Solution obj;
    cout << obj.characterReplacement(s,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*n)*26
Space Complexity: O(1)
    hash array is used of fixed size 26
==================================================
*/

//Optimal Approach
/*
Algorithm: 
     Use a fixed-size frequency array (26) instead of a map.
     Maintain maxCount = highest frequency in the window.
     Expand the window to the right.
     If replacements needed exceed k, move left pointer.
     We do not reduce maxCount while shrinking, because it does not affect correctness.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l = 0,r = 0;
        int maxfreq = 0;
        int hash[26] = {0};
        while(r<n){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            if(((r-l+1) - maxfreq)>k){
                hash[s[l]-'A']--;
                l++;
            }
            if(((r-l+1) - maxfreq)<=k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    string s = "AABABBA";
    int k = 1;
    Solution obj;
    cout << obj.characterReplacement(s,k);
    return 0;
}

/*
==================================================
Time Complexity: O(n)
Space Complexity: O(1)
    hash array is used of fixed size 26
==================================================
*/