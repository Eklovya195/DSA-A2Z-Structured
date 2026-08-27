/*
Problem: 78. Subsets
Problem Statement:Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.
Platform: Bit Manipulation / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/subsets/description/"

==================================================
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
==================================================
*/

// Approach 1: Brute Force
/*
=================================================
Algorithm:
    Let N be the size of the array.
    The total number of subsets is 2ⁿ, which can be computed as (1 << n).
    Each number from 0 to (2ⁿ − 1) represents one subset.
    For each number, check its binary representation.
    If the i-th bit is set, include nums[i] in the current subset.
    Store each generated subset in the result list.
    Return all subsets.t is found (though the problem guarantees one), return -1.
=================================================
*/

/*
for nums[1,2,3]:
give indexing to this nums from 0->2
dry run:
  total subsets = 2^3 = 8
  0 -> 000 ->no bit is 0 -> []
  1 -> 001 -> 0th index is 1 -> [1]
  2 -> 010 -> 1st index is 1 -> [2]
  3 -> 011 -> 0th & 1st index is 1 -> [1 2]
  4 -> 100 -> 2nd index is 1 -> [3]
  5 -> 101 -> 0th & 2nd index is 1 -> [1 3]
  6 -> 110 -> 1st & 2nd index is 1 -> [2 3]
  7 -> 111 -> 0th & 1st & 2nd index is 1 -> [1 2 3]
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findSubsets(vector<int> &nums){
    int n = nums.size();
    int total = 1<<n;  //2^n total subsets
    vector<vector<int>> ans;
    for(int mask=0;mask<total;mask++){
        //used to store subsets of each nums[i]
        vector<int> subsets;
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                subsets.push_back(nums[i]);
            }
        }
        ans.push_back(subsets);
    }
    return ans;
}

int main() {
    vector<int> nums={1,2,3};
    vector<vector<int>> ans = findSubsets(nums);
    for(auto it:ans){
        cout << "[";
        for(int x:it) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}


/*
==================================================================================================
Time Complexity: O(N × 2ⁿ), for each of the 2ⁿ subsets we may scan all N elements.
Space Complexity: O(N × 2ⁿ), to store all subsets of the power set.
==================================================================================================
*/