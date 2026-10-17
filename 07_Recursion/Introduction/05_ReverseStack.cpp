/*
Problem:  Reverse a Stack
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://takeuforward.org/practice/dsa/reverse-a-stack?utm=codolio"
==================================================
You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). 
You are not allowed to use any loop constructs or additional data structures like arrays or queues.

Input: stack = [4, 1, 3, 2]
Output: [2, 3, 1, 4]
==================================================
*/

/*
Key Idea:
To reverse a stack using recursion, we break the problem into two parts:
    1. reverseStack
        ○ Remove the top element.
        ○ Recursively reverse the remaining stack.
        ○ Insert the removed element at the bottom of the stack.
    2. insertAtBottom
        ○ Inserts a given element at the bottom of the stack using recursion.
        ○ If the stack is empty, push the element.
        ○ Otherwise, pop the top, recursively insert at bottom, then push the popped element back.
    By repeating this process, the stack gets reversed when recursion unwinds
*/

//Recursive approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void InsertAtBottom(stack<int> &st,int val){
        //if stack is empty
        if(st.empty()){
            st.push(val);
            return;
        }
        int topval = st.top();
        st.pop();

        InsertAtBottom(st,val);
        st.push(topval);
    }

    void reverseStack(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int topval = st.top();
        st.pop();
        reverseStack(st);
        InsertAtBottom(st,topval);
    }
};

int main() {
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    Solution obj;
    obj.reverseStack(st);
    // Printing sorted stack (top to bottom)
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(n²)
    Each element is inserted at the bottom, which takes O(n) time, for n elements.
Space Complexity: O(n)
    Due to recursive call stack.
==================================================
*/