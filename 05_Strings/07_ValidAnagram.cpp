/*
Problem: 242. Valid Anagram
Problem Statement:Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/valid-anagram/description/"
==================================================
Input: s = "anagram", t = "nagaram"
Output: true
==================================================
*/


//Brute Force Approach(using sorting approach)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case
        if(s.size()!=t.size()) return false;
        //sort both string
        sort(s.begin(),s.end());  //O(nlogn)
        sort(t.begin(),t.end());  //O(nlogn)

        for(int i=0;i<s.size();i++){  //O(n)
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution obj;
    bool ans = obj.isAnagram(s,goal);
    cout << boolalpha << ans;
}
*/

/*
==================================================
Time Complexity:O(nlogn)
Space Complexity:O(logn) //auxilary stack space
==================================================
*/

//Better Approach(Using Hashmap)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        //storing freq of each char in map
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }

        //comparing freq of each char
        for(char ch='a';ch<='z';ch++){
            if(mp1[ch]!=mp2[ch]) return false;
        }
        return true;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution obj;
    bool ans = obj.isAnagram(s,goal);
    cout << boolalpha << ans;
}
*/

/*
==================================================
Time Complexity:O(n)
Space Complexity:O(1)
    if the input could contain an arbitrary character set rather than just 'a'–'z', 
    the maps could contain up to n distinct characters, making space O(n).
==================================================
*/

//Optimal Approach
/*
Approach:
    increment freq for string s char
    decrement freq for string t char
    finally if anytime freq of any char is not 0 that means some char is different in other string
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //edge case
        if(s.size()!=t.size()) return false;
        int freq[26] = {0};
        //storing freq of each char in map
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        //if freq of any char is not 0 
        //then return false
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution obj;
    bool ans = obj.isAnagram(s,goal);
    cout << boolalpha << ans;
}

/*
==================================================
Time Complexity:O(n)
Space Complexity:O(1)
==================================================
*/