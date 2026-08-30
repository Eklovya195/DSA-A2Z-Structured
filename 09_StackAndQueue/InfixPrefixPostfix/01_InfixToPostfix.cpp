/*
==================================================================
    You are given an infix expression.
    Your task is to convert this infix expression into a postfix expression.
    In an infix expression, the operator comes between operands, for example a + b.
    In a postfix expression, the operator comes after operands, for example ab+.
    Postfix expressions are easier for computers to evaluate because they do not need parentheses
    or precedence rules during evaluation
==================================================================
*/

/*
==================================================================
Question Explanation:
    Given an infix expression containing operands (letters or digits), operators (+ - * / ^), and
    parentheses, convert it into a postfix expression by following operator precedence and
    associativity rules.
    Operator precedence (high to low):
        ^
        * /
        + -
    Associativity:
        ^ is right associative
        * / + - are left associative
==================================================================
*/

/*
==================================================================
Example Explanation:
    Input:
        (p + q) * (m - n)
        Step-by-step:
        ● Convert (p + q) → pq+
        ● Convert (m - n) → mn-
        ● Apply * → pq+mn-*
    Output:
        pq+mn-*
==================================================================
*/

/*
==================================================================
Algorithm:
    1. Create an empty stack to store operators.
    2. Traverse the infix expression from left to right.
    3. If the current character is an operand, add it to the result.
    4. If the character is '(', push it onto the stack.
    5. If the character is ')', pop from the stack and add to result until '(' is found. Remove '('.
    6. If the character is an operator:
        ○ Pop operators from the stack while:
            ■ the stack is not empty, and
            ■ the precedence of the current operator is less than the precedence of the stack top, or
            ■ the precedence is equal and the operator is left associative
        ○ Push the current operator onto the stack.
    7. After processing the entire expression, pop all remaining operators from the stack and
    add them to the result.
    8. The final result is the postfix expression.
==================================================================
*/

#include <bits/stdc++.h>
using namespace std;

//fxn to check precedence
int prec(char c){
    if(c == '^') return 3;
    else if(c == '*' || c=='/') return 2;
    else if(c == '+' || c=='-') return 1;
    else return -1;
}

//fxn to check right associativity
bool isRightAssociative(char c){
    return c=='^';
}

string InfixToPostfix(string s){
    string ans = "";
    stack<char> st;

    for(char c:s){

        //1.Check for opearands
        if((c>='A'&&c<='Z')||
           (c>='a'&&c<='z')||
           (c>='0'&&c<='9')){
            ans += c;
        }

        //2.for open bracket
        else if(c == '('){
            st.push(c);
        }

        //3. for close bracket
        else if(c==')'){
            //while st.top!= '(' put all operators in ans
            while(!st.empty()&&st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop(); //to remove '(' bracket
        }

        //4.operators
        else{
            while(!st.empty() &&
                 (prec(c) < prec(st.top()) ||
                 (prec(c) == prec(st.top()) && !isRightAssociative(c)))) {
                    ans += st.top();
                    st.pop();
            }
            st.push(c);
        }
    }

    //pop remaining elements
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string exp = "(p+q)*(m-n)";
    cout << InfixToPostfix(exp);
    return 0;
}

/*
==================================================================
Time Complexity:O(N), where N is the length of the infix expression. Each character is processed once.
Space Complexity:O(N), due to the stack used to store operators and parentheses.
==================================================================
*/


/*
One-line Intuition (interview ready):
    Operators are popped from the stack if they have higher precedence, or equal
    precedence with left associativity.
Complete process:
● Operand → output
● ( → push
● ) → pop till (
● Operator:
    ○ pop stronger operators
    ○ pop equal & left associative
    ○ then push current
*/

/*
🔴 CORE RULE:
    Postfix me operator tab likhte hain jab usse zyada important kaam ho chuka ho.
    Stack bas operators ko rok ke rakhne ke liye hai.

    Step 0: Sirf 3 cheezein hoti hain
        Expression me aayega:
        1. Operand (a, b, 1, 2…)
        2. Operator (+ - * / ^)
        3. Bracket ( )
    🟢 Rule 1: Operand aaye
        a, b, x, 5
        👉 Seedha output me daal do
        ❓ Kyun?
        Operand ko kisi ka wait nahi hota.
    🟢 Rule 2: '(' aaye
        👉 Stack me daal do
        Bracket ka matlab:
        “Iske andar ka kaam pehle complete karo”
    🟢 Rule 3: ')' aaye
        👉 Stack se pop karte jao
        👉 Jab tak '(' na mil jaye
        👉 '(' ko output me nahi daalte
    🔴 Rule 4 : Operator aaye
        Ab dhyaan se 👇
        Jab operator c aaye:
        ● Stack ke top ko dekho
        ● Agar stack top:
            ○ zyada powerful hai
            ○ ya same power ka hai aur left associative hai
        👉 to pehle usko output me daal do
        Fir:
        👉 current operator ko stack me push karo
*/