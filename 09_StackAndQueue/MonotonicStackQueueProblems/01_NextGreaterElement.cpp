/*
Problem: 496. Next Greater Element
Problem Statement: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
    You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
    For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
    Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/next-greater-element-i/description/"
==================================================
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
==================================================
*/

//Brute Force Approach
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> num1 = {2,4};
    vector<int> num2 = {1,2,3,4};

    int n1 = num1.size();
    int n2 = num2.size();

    vector<int> ans;
    for(int i=0;i<n1;i++){
        int a1 = num1[i];
        int j=0;
        while(num2[j]!=a1){
            j++;
        }

        int k = j+1;
        while(k<n2){
            if(num2[k]>a1){
                ans.push_back(num2[k]);
                break;  //break breaks while loop
            }
            k++;
        }

        if(k>=n2) ans.push_back(-1);
    }

    for(int i=0;i<n1;i++){
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

//Monotonic Stack Approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> mp;

        // Find NGE for every element in nums2
        for(int x : nums2){

            while(!st.empty() && st.top() < x){
                mp[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        // Elements remaining in stack have no NGE
        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> ans;

        for(int x : nums1){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};

/*
==================================================================
Building map: O(n2)
Building answer: O(n1)

Time Complexity: O(n1 + n2)
Space Complexity: O(n2)
==================================================================
*/