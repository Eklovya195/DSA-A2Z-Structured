/*
Problem: 1614. Maximum Nesting Depth of Parenthesis
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/"
==================================================
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.
==================================================
*/

//My first Intution using satck
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt = 0;
        int maxi = 0;
        for(char c:s){
            if(c=='('){
                cnt++;
                st.push(c);
            }else if(c==')'){
                cnt--;
                st.pop();
            }else{
                continue;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

int main(){
    string s = "()(())((()()))";
    Solution obj;
    cout << obj.maxDepth(s);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) //N is the size of string s
    (single pass)
Space Complexity: O(N) //using stack
==================================================
*/

//Optimal (Actually there is no need of stack in this problem)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxi = 0;
        for(char c:s){
            if(c=='('){
                cnt++;
            }else if(c==')'){
                cnt--;
            }else{
                continue;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

int main(){
    string s = "()(())((()()))";
    Solution obj;
    cout << obj.maxDepth(s);
    return 0;
}

/*
==================================================
Time Complexity: O(N) //N is the size of string s
    (single pass)
Space Complexity: O(1) 
==================================================
*/