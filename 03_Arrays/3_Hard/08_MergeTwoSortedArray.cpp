/*
Problem: 88. Merge Two Sorted Array
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/merge-sorted-array/description/"
==================================================
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
==================================================
*/

//Approach : Optimal Approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        //if element are present in nums2
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        return nums1;
    }
};

int main(){
    int m = 3;
    int n = 3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    Solution obj;
    vector<int> ans = obj.merge(nums1,m,nums2,n);
    for(int i=0;i<m+n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}


/*
==================================================
Time Complexity: O(N+M), we traverse both the arrays exactly once.
Space Complexity: O(1), constant extra space is used to store pointers
==================================================
*/
