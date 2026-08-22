/*
Problem: 205. Isomorphic String
Problem Statement: Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/isomorphic-strings/description/"
==================================================
Input: s = "egg", t = "add"
Output: true
Explanation:
    The strings s and t can be made identical by:
    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.
==================================================
*/

#include<bits/stdc++.h>
using namespace std;

bool IsomporphicString(string s,string t){
    if(s.size()!=t.size()) return false;
    map<char,char> m1,m2;

    for(int i=0;i<s.size();i++){
        if(m1.find(s[i])!=m1.end()){
            if(m1[s[i]]!=t[i]) return false;
        }
        else if(m2.find(t[i])!=m2.end()){
            if(m2[t[i]]!=s[i]){
                return false;
            }
        }
        else{
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
    }
    return true;
}

int main(){
    string s = "egg";
    string t = "adb";
    bool ans = IsomporphicString(s,t);
    cout << boolalpha << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N)
    (single pass through both strings)
Space Complexity: O(1)
==================================================
*/