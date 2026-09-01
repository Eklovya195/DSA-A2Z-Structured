/*
Problem: Next Smaller Element
Problem Statement: You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).
    The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.
    If no such element exists, assign -1 as the NSE for that position.
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1"
==================================================
Input: arr[] = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation: 
The first element smaller than 4 having index > 0 is 2.
The first element smaller than 8 having index > 1 is 5.
The first element smaller than 5 having index > 2 is 2.
There are no elements smaller than 4 having index > 3.
There are no elements smaller than 4 having index > 4.
==================================================
*/

//Brute force Approach
/*
Algorithm:
    ● Create an answer array of size n.
    ● For each element at index i:
        ○ Traverse the next n-1 elements.
        ○ If a smaller element is found, store it in ans[i] and stop searching.
        else store -1 if smaller element is not found in right of that element
    ● After checking all elements, return the answer array.

*/

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {4,1};
    int n = nums.size();
    vector<int> ans;

    for(int i=0;i<n;i++){
        int a = nums[i];
        // Start from next index into right
        int j = i+1;
        while(j<n){
            if(nums[j]<a){
                ans.push_back(nums[j]);
                break;
            }
            j++;
        }
        if(j>=n) ans.push_back(-1);
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
    ● Initialize an answer array.
    ● Use a stack to maintain elements right to left.
        ○ Traverse the array from index n - 1 to 0 to simulate traversal.
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

vector<int> NSE(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<=st.top()){
            st.pop();
        }
        
        if(!st.empty()){
            ans[i] = st.top();
        }

        st.push(nums[i]);
    }
    return ans;
}

int main(){
    vector<int> nums = {4, 8, 5, 2, 25};
    vector<int> ans = NSE(nums);
    //print the answer
    for(int x : ans) cout << x << " ";
    return 0;
}


/*
==================================================================
Time Complexity:O(N)
Space Complexity: O(N) to store ans array
==================================================================
*/