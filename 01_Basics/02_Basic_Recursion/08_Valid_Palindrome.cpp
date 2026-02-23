/*
Problem:Valid Palindrome
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:"https://leetcode.com/problems/valid-palindrome/description/"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1.Create a new string cleaned:
    Traverse each character of s.
    If character is alphanumeric:
        Convert it to lowercase.
        Append it to cleaned.
2.Initialize two pointers:
    left = 0
    right = length(cleaned) - 1
3.While left < right:
    If characters at left and right are not equal → return Not Valid Palindrome
    Otherwise increment left and decrement right
4.If loop completes without mismatch → return Valid Palindrome

==================================================

*/

#include <bits/stdc++.h>
using namespace std;

// Clean the string first
string cleanString(string &s){
    string cleaned;
    for(char c : s){
        if(isalnum(c)){// check the char is alphanumeric
            cleaned += tolower(c); //add lowercase to string 
        }
    }
    return cleaned;
}

int main(){
    string s;
    getline(cin, s);   // better than cin >> s for full sentence

    string cleaned = cleanString(s);
    int left = 0, right = cleaned.size() - 1;

    while(left < right){
        if(cleaned[left] != cleaned[right]){
            cout << "Not Valid Palindrome";
            return 0;   // stop immediately
        }
        left++;
        right--;
    }

    cout << "Valid Palindrome";
    return 0;
}