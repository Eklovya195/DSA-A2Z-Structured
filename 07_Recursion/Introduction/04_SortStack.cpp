/*
Problem:  Sort a Stack
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm=codolio"
==================================================
Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).
Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
==================================================
*/

// My Approach:
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int> arr;
        //O(n)
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        
        sort(arr.begin(),arr.end()); //O(nlogn)
        //O(n)
        for(int i=0;i<arr.size();i++){
            st.push(arr[i]);
        }
    }
};

int main() {
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    Solution obj;
    obj.sortStack(st);
    // Printing sorted stack (top to bottom)
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(nlogn)  n -> size of stack
Space Complexity: O(n) -> vector array takes O(n) space 
==================================================
*/

//recursive approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort(stack<int> &st,int n){
        if(n<=1) return;
        int topEle = st.top();
        st.pop();
        sort(st,n-1);
        stack<int> dummy;
        while(!st.empty() && st.top()>topEle){
            dummy.push(st.top());
            st.pop();
        }
        st.push(topEle);
        while(dummy.size()){
            st.push(dummy.top());
            dummy.pop();
        }
    }
    void sortStack(stack<int> &st) {
        int n = st.size();
        sort(st,n);
    }
};

int main() {
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    Solution obj;
    obj.sortStack(st);
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
Time Complexity: O(n^2)  n -> size of stack
    Each insertion may take up to O(n) and is done for n elements.
Space Complexity: O(n) -> dummy stack takes n space
==================================================
*/