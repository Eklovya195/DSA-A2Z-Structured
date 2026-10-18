/*
Problem:  90. Subsets II
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/subsets-ii/description/?utm=codolio"
==================================================
Explanation:
You are given an integer array nums that may contain duplicate elements.
Your task is to generate the power set (all possible subsets) such that no duplicate subset
appears in the final answer.
A subset:
    ● can be empty
    ● can contain some or all elements
    ● order inside a subset does not matter
Because duplicates exist in the input array, care must be taken to avoid printing the same subset more than once.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
==================================================
*/

/*
==================================================
Approach 1: Brute force
Idea
Generate all possible subsets using recursion (pick / not pick).
Since duplicates will appear, store all subsets inside a set, which automatically removes
duplicates.
==================================================
*/

/*
==================================================
Algorithm:
    1. Sort the array (for consistent subset formation)
    2. Use recursion to generate all subsets:
        ○ pick the current element
        ○ do not pick the current element
    3. When the index reaches the end:
        ○ insert the current subset into a set
    4. Convert the set into a vector and return it
==================================================
*/

//Brute Force Approach:
//Here i am using picking and not picking approach and this find in base case
//cause more time complexity
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funcGenerate(int idx,vector<int> &subset,vector<vector<int>> &ans,vector<int> &nums){
        //base case
        if(idx >= nums.size()){
            if(find(ans.begin(),ans.end(),subset) == ans.end()){
                ans.push_back(subset);
            }
            return;
        }
        subset.push_back(nums[idx]);
        funcGenerate(idx+1,subset,ans,nums);

        subset.pop_back();
        funcGenerate(idx+1,subset,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        funcGenerate(0,subset,ans,nums);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2};
    Solution obj;
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for(const auto& row:ans){
        cout << "[";
        for(int num:row){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^N * N * 2^N)
Space Complexity: O(2^N * N)
==================================================
*/

//Optimal Approach
//Recursive Approach 2: (Backtracking with skipping duplicates)
//did with one function call and no need of find also
/*
==================================================
Algorithm:(Backtracking with skipping duplicates)
    1. Sort the array
    2. Use backtracking:
        ○ Add current subset to result
        ○ Loop from start index to end
        ○ If i > start and nums[i] == nums[i-1], skip
        ○ Pick element → recurse → backtrack
    5. Return ans
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funcGenerate(int idx,vector<int> &subset,vector<vector<int>> &ans,vector<int> &nums){
        //base case
        ans.push_back(subset);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            funcGenerate(i+1,subset,ans,nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        funcGenerate(0,subset,ans,nums);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,2};
    Solution obj;
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for(const auto& row:ans){
        cout << "[";
        for(int num:row){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(2^N)
Space Complexity:
    ○ O(2^N) for output
    ○ O(N) recursion stack
==================================================
*/