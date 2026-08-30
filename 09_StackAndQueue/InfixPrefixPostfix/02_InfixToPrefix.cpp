/*
==================================================================
Algorithm:
    ● Reverse the infix expression.
    ● Replace ( with ) and ) with (.
    ● Convert the modified infix expression to postfix using operator precedence rules.
    ● Reverse the postfix expression to get the prefix expression.
    ● Use a stack to handle operators during conversion.
==================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check precedence
int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

// Function to check right associativity
bool isRightAssociative(char c){
    return c == '^';
}

// Infix to Postfix
string InfixToPostfix(string s){
    string ans = "";
    stack<char> st;

    for(char c : s){   //O(N)

        // Operand
        if((c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9')){
            ans += c;
        }

        // Opening bracket
        else if(c == '('){
            st.push(c);
        }

        // Closing bracket
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }

        // Operator
        //this is the most important part of this code
        else{     //O(N)
            while(!st.empty() &&
                  st.top() != '(' &&
                  (prec(c) < prec(st.top()) ||
                   (prec(c) == prec(st.top()) &&
                    !isRightAssociative(c)))){

                ans += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


// Infix to Prefix
string InfixToPrefix(string s){

    // 1. Reverse string
    reverse(s.begin(), s.end());

    // 2. Swap brackets
    for(char &c : s){
        if(c == '(')
            c = ')';
        else if(c == ')')
            c = '(';
    }

    // 3. Convert reversed expression to postfix
    string postfix = InfixToPostfix(s);

    // 4. Reverse postfix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}


int main(){
    string exp = "(p^q)*(m-n)";
    cout << InfixToPrefix(exp);
    return 0;
}

/*
==================================================================
Time Complexity: O(N) Each character is processed a constant number of times.
Space Complexity: O(N) Stack space used for operators during conversion
==================================================================
*/