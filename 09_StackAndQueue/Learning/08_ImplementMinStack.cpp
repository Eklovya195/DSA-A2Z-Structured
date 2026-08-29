/*
Problem:  155. Min Stack 
Platform: Stack & Queue / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/min-stack/"
==================================================
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
==================================================
*/

//Approach 1: Brute Force (Using Stack of Pairs)
/*
In this approach, each element in the stack stores:
    ● the actual value
    ● the minimum value up to that point
So for every element, we always know the minimum till that element.
*/

/*
#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private:
    stack<pair<int,int>> st;

    public:
    MinStack() {}

    void push(int value){
        if(st.empty()) st.push({value,value});
        else{
            int mini = min(value,st.top().second);
            st.push({value,mini});
        }
    }

    void pop(){
        if(!st.empty()) st.pop();
    }

    int top(){
        if(st.empty()) return -1; 
        return st.top().first;
    }
    int getMin(){
        if(st.empty()) return -1;
        return st.top().second;
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    cout << s.getMin();
    return 0;
}
*/

/*
==================================================================
Time Complexity: O(1) for push, pop, top, and getMin.
Space Complexity: O(2*N) ≈ O(N), because each element stores an extra minimum value
==================================================================
*/


//Approach 2:Optimal Approach (Single Stack with Encoding)

/*
Algorithm:
    Maintain:
        ● one stack
        ● one variable mini to store the current minimum
    Push operation:
        ● If the stack is empty, push value and set mini = value.
        ● If value > mini, push value normally.
        ● If value <= mini, push a modified value (2*value - mini) and update mini to value.
    Pop operation:
        ● If the top value is >= mini, pop normally.
        ● If the top value < mini, it means it was encoded.
        ○ Update mini = 2*mini - top.
    Top operation:
        ● If top >= mini, return top.
        ● Otherwise, return mini.
    GetMin operation:
        ● Return mini.
    Main logic:
        Encoded value hamesha current mini se chhoti hoti hai
        Proof:
        encoded = 2*value - mini
        Since value < mini
        ⇒ 2*value - mini < value
        ⇒ encoded < value < mini
    👉 Matlab:
    ● Stack me koi element mini se chhota dikhe
    ⇒ wo real value nahi, encoded value hai
*/

/*
Push time:
    encoded = 2*newMin - oldMin
Pop time:
    oldMin = 2*currentMin - encoded
Ye reversible encoding hai
Isliye ek hi stack kaam kar leta hai
*/
#include<bits/stdc++.h>
using namespace std;

class MinStack{
    private:
    stack<int> st;
    int mini;

    public:
    MinStack() {}

    void push(int value){
        if(st.empty()){
            mini = value;
            st.push(value);
        }else if(value>mini){
            st.push(value);
        }else{
            st.push(2*value-mini);
            mini = value;
        }
    }

    void pop(){
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x<mini){
            mini = 2*mini-x;
        }
    }

    int top(){
        if(st.empty()) return -1; 
        int x = st.top();
        if(x>=mini) return x;
        return mini;
    }
    int getMin(){
        return mini;
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    cout << s.getMin();
    return 0;
}

/*
==================================================================
Time Complexity: O(1) for push, pop, top, and getMin.
Space Complexity: O(N), as only one stack is used without storing extra pairs
==================================================================
*/