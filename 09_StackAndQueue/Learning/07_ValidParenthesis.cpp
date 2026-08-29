/*
Problem:  20. Valid Parenthesis 
Platform: Stack & Queue / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/valid-parentheses/description/"
==================================================
Input: s = "()[]{}"
Output: true
==================================================
*/

//Approach:
/*
Algorithm:
    We need to track the most recent opening bracket and match it with the current closing bracket.
    A stack follows Last-In-First-Out behavior, which perfectly fits this requirement.
    Traverse the string character by character.
    If the character is an opening bracket (, {, or [, push it onto the stack.
    If the character is a closing bracket:
        ● If the stack is empty, there is no matching opening bracket, so return false.
        ● Otherwise, check the top of the stack. If it is not the matching opening bracket, return false.
        ● If it matches, pop the opening bracket and continue.
    After processing the entire string, the stack must be empty.
    If it is empty, all brackets were matched correctly, so return true. Otherwise, return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(char c:s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((c==')' && ch=='(')||
               (c==']' && ch=='[')||
               (c=='}' && ch=='{')){
                continue;
            }
            else return false;
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin >> s;
    cout << boolalpha << isValid(s);
    return 0;
}

/*
==================================================================
Time Complexity: O(N), where N is the length of the string, as each character is processed once.
Space Complexity: O(N), due to the stack storing opening brackets in the worst case.
==================================================================
*/