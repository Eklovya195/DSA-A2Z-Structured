/*
Problem: 796. Rotate String
Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
    A shift on s consists of moving the leftmost character of s to the rightmost position.
    For example, if s = "abcde", then it will be "bcdea" after one shift.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/rotate-string/description/"
==================================================
Input: s = "abcde", goal = "cdeab"
Output: true
==================================================
*/


//Brute Force Approach
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.size();
        int n2 = goal.size();
        if(n1!=n2) return false;

        string newS = s;
        while(newS!=goal){
            char last = newS[n1-1];
            for(int i=n1-1;i>0;i--){
                newS[i] = newS[i-1];
                
            }
            newS[0] = last;
            if(newS==s){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution obj;
    bool ans = obj.rotateString(s,goal);
    cout << boolalpha << ans;
}
*/

/*
==================================================
Time Complexity:O(n^2)
Space Complexity:O(n) //to store newStirng as newS
==================================================
*/

//Optimal Approach (using npos)
/*
std::string::npos is a special constant in C++ that indicates a search failure or an "out-of-bounds" condition.
When you use functions like str.find(), 
C++ needs a way to tell you, "Hey, I looked everywhere, but I couldn't find what you were looking for." That signpost is npos (which stands for number position).
npos is basically -1 and string indeces using unsigned integer
    if s is not found till npos that means it is not present in goal
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        //add same string at the end of string s
        string doubled_str = s+s;

        return doubled_str.find(goal)!=string::npos;
    }
};

int main(){
    string s = "abcde";
    string goal = "cdeab";
    Solution obj;
    bool ans = obj.rotateString(s,goal);
    cout << boolalpha << ans;
}

/*
==================================================
Time Complexity:O(n)
Space Complexity:O(n) //to store newStirng as newS
==================================================
*/