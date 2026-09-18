/*
Problem: 1021. Remove Outermost Parenthesis
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/remove-outermost-parentheses/description/"
==================================================
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
==================================================
*/

/*
Approach:
    1.if first time '(' come:
        just push it in the stack
    2.if '(' came other than first time
        add it in answer
        push it in stack as well
    3.if ')' came
        remove top of stack and check if stack is empty or not
        if satck is not empty-> add ')' to ans 
        else don't do anything
    4. finally return ans
*/

//This was my first intution to solve this problem (Using stack)
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        for(char c:s){
            if(st.empty() && c=='('){
                st.push(c);
            }
            else if(!st.empty() && c=='('){
                ans += c;
                st.push(c);
            }else{
                st.pop();
                if(!st.empty()){
                    ans += c;
                }
            }
        }
        return ans;
    }
};

int main(){
    string s = "(()())(())(()(()))";
    Solution obj;
    string ans = obj.removeOuterParentheses(s);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)
    (single pass)
Space Complexity: O(N) //stack is used
==================================================
*/

//Optimal (No need of stack)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for(char c:s){
            if(c=='('){
                depth++;
                if(depth>1){
                    ans += c;
                } 
            }
            else{
                if(depth>1){
                    ans += c;
                }
                depth--;
            }
        }
        return ans;
    }
};

int main(){
    string s = "(()())(())(()(()))";
    Solution obj;
    string ans = obj.removeOuterParentheses(s);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N)
    (single pass)
Space Complexity: O(1)
==================================================
*/