/*
Problem:  39. Combination Sum
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/combination-sum/?utm=codolio"
==================================================
You are given an array of distinct integers and a target value.
Your task is to find all unique combinations of numbers such that the sum equals the target.
    Rules:
    ● You can use the same number unlimited times
    ● Order of numbers inside a combination does not matter
    ● Each combination must be unique based on frequency of elements
This is a classic recursion + backtracking problem.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
==================================================
*/

/*
Idea
    At every index, we decide:
        ● Pick the current element (stay on same index because reuse is allowed)
        ● Not pick the current element (move to next index)
    We keep track of:
        ● current index
        ● sum
        ● current combination (subsets)
    When:
        ● target == sum → valid combination found
            push it into the ans
        ● index == array.size() → stop recursion

*/
/*
Algorithm:
    1. Start recursion from index 0
    2. If current element ≤ target:
        ○ pick it
        ○ reduce target
        ○ stay on same index
    3. Always explore the not-pick case:
        ○ move to next index    
    4. Backtrack after each recursive call
    5. Collect all valid combinations
*/

//Recursive Approach(Include/Exclude):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(int idx,vector<int>& candidates, int target,int n,vector<int> &subset,vector<vector<int>> &ans,int &sum){
        if(idx == n || sum >= target){
            if(sum == target){
                ans.push_back(subset);
            }
            return;
        }

        //include 
        subset.push_back(candidates[idx]);
        sum += candidates[idx];
        funGenerate(idx,candidates,target,n,subset,ans,sum);

        sum -= candidates[idx];
        subset.pop_back();

        //exclude
        funGenerate(idx+1,candidates,target,n,subset,ans,sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        int idx = 0;
        vector<vector<int>> ans;
        vector<int> subset;
        funGenerate(idx,candidates,target,n,subset,ans,sum);
        return ans;
    }
};

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(candidates,target);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: Exponential (depends on number of combinations formed)
Space Complexity:
    ○ O(k × x) to store results
    ○ O(k) recursion depth
    (k = average length of a combination, x = number of combinations)

This approach strictly follows pick / not-pick recursion, allows reuse of elements, and avoids
duplicate combinations.
==================================================
*/