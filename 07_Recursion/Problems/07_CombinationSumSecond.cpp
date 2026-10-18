/*
Problem:  40. Combination Sum II
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/combination-sum-ii/description/?utm=codolio"
==================================================
Explanation
You are given an array of integers candidates and a target value target.
Your task is to find all unique combinations where the chosen numbers sum to target.
Rules:
    ● Each number can be used at most once in a combination
    ● The input array may contain duplicates
    ● The result must not contain duplicate combinations
This problem is very similar to Combination Sum I, but with two key differences:
    1. An element can be picked only once
    2. Duplicate combinations must be avoided


Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
==================================================
*/

/*
==================================================
Core Idea (Backtracking with Duplicate Handling):
We still use recursion + backtracking, but with these rules:
    1. Sort the array first
        ○ Helps in skipping duplicates
        ○ Helps in early stopping when element > target
    2. Use a loop instead of pick / not-pick recursion
        ○ At every recursive level, try all possible elements starting from index
    3. Skip duplicates
        ○ If arr[i] == arr[i-1] and i > index, skip it
    4. Move to next index (i + 1) after picking an element
        ○ Ensures each number is used only once
==================================================
*/

/*
==================================================
Algorithm:
    1. Sort the candidates array
    2. Start recursion from index 0
    3. For every index i:
        ○ Skip duplicate values
        ○ Stop if arr[i] > target
        ○ Pick arr[i] and recurse with:
            ■ target - arr[i]
            ■ i + 1
    4. If target == 0, store the combination
    5. Backtrack after recursion
==================================================
*/

//Recursive Approach(Include/Exclude):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(int idx,vector<int>& candidates, int target,vector<int> &subset,vector<vector<int>> &ans,int &sum){
        if(sum == target){
            ans.push_back(subset);
            return;
        }
        if(idx == candidates.size() || sum > target){ 
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            // skip duplicates at the same level
            //i>idx means always allow first idx to pick
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(sum+candidates[i] > target) break;
            subset.push_back(candidates[i]);
            sum += candidates[i];
            funGenerate(i+1,candidates,target,subset,ans,sum);
            sum -= candidates[i];
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        //sort the array first
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> subset;
        funGenerate(0,candidates,target,subset,ans,sum);
        return ans;
    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum2(candidates,target);
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
Time Complexity: O(2^n × k)
    Each element can be chosen or skipped, and storing a combination takes O(k)
Space Complexity:
    ○ O(k × x) to store all valid combinations
    ○ O(k) recursion stack
    (k = average length of combination, x = number of valid combinations)
==================================================
*/