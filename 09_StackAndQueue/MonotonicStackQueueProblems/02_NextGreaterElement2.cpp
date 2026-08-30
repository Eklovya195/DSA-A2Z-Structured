/*
Problem: 503. Next Greater Element ||
Problem Statement: Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
    The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/next-greater-element-ii/description/"
==================================================
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
==================================================
*/

//Brute force Approach
/*
Algorithm:
    ● Create an answer array of size n, initialized with -1.
    ● For each element at index i:
        ○ Traverse the next n-1 elements in circular order using (i + j) % n.
        ○ If a greater element is found, store it in ans[i] and stop searching.
    ● After checking all elements, return the answer array.

*/

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,1};
    int n = nums.size();
    vector<int> ans;

    for(int i=0;i<n;i++){
        int a = nums[i];

        // Start from next circular index
        int idx = (i+1)%n;
        while(idx!=i){
            if(nums[idx] > a){
                ans.push_back(nums[idx]);
                break;
            }
            idx = (idx+1)%n;
        }

        // We came back to i without finding greater element
        if(idx==i) ans.push_back(-1);
    }

    //print the answer
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
==================================================================
Time Complexity:O(N^2)
Space Complexity: O(N) to store ans array
==================================================================
*/

//Optimal Approach (Using Monotonic Stack)
/*
==================================================================
Algorithm:
    ● Initialize an answer array with -1.
    ● Use a stack to maintain elements in decreasing order.
        ○ Traverse the array from index 2*n - 1 to 0 to simulate circular traversal.
    ● Use i % n to get the actual index.
    ● While stack is not empty and top ≤ current element, pop from stack.
    ● If i < n:
        ○ If stack is empty → answer is -1
        ○ Else → top of stack is the next greater element
    ● Push current element into the stack.
    ● Return the answer array.
==================================================================
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> nums){
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    
    for(int i=2*n-1;i>=0;i--){  //O(2N)
        while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();   //O(2N)
        }

        if(i<n){
            nge[i] = st.empty()?-1:st.top();
        }
        st.push(nums[i%n]);  //O(2N)
    }
    return nge;
}

int main(){
    vector<int> nums = {1,2,1};
    vector<int> ans = NGE(nums);
    //print the answer
    for(int x : ans) cout << x << " ";
    return 0;
}

/*
==================================================================
Time Complexity:O(4*N)
Space Complexity: O(2*N) to store ans array
==================================================================
*/