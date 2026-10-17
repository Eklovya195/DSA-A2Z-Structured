/*
Problem:  78. Subsets
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/subsets/?utm=codolio"
==================================================
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Subset: A subset of an array is a selection of elements (possibly none) of the array.
==================================================
*/

/*
Algorithm:
1. Find Total Subsets: Calculate the total number of subsets using the bitwise left-shift operation: total = 1 << n (which is 2^n).
2. Iterate Through Masks: Run an outer loop from mask = 0 up to total - 1. Each value of mask represents a unique subset configuration.
3. Inspect the Bits: For each mask, run an inner loop from i = 0 to n - 1 to check the status of each element:
	• Generate a probe for the i-th position using 1 << i.
	• Use the bitwise AND operator mask & (1 << i) to see if the bit at the i-th position is turned ON.
4. Build the Subset: If the condition evaluates to true (non-zero), add the corresponding element nums[i] to the current temporary subset list.
5. Collect Results: Once all n bits of the current mask are checked, push the temporary subset into your final answers collection.
     Return the collection after the outer loop finishes.
*/

//Iterative Approach:
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1<<n;  //2^n total subsets
        vector<vector<int>> ans; //contain final answer
        for(int mask=0;mask<total;mask++){
            //list for contaning subset 
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
};

int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    vector<vector<int>> ans = obj.subsets(nums);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}
*/


/*
==================================================
Complexity Analysis:
Time Complexity: O(n*2^n) — each character is processed once
Space Complexity: O(n*2^n) — (to store all subsequences)
==================================================
*/

/*
Algorithm(Recursion(Inclusive/Exclusive)):
    1. Start from index 0 with an empty string.
    2. At each index:
        ○ Recurse without taking the character.
        ○ Recurse after taking the character.
    3. When index reaches n, store the current subsequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //recursive Approach
    void funct(int idx,vector<int> &subset,vector<vector<int>> &ans,vector<int> &nums,int n){
        if(idx>=n){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        funct(idx+1,subset,ans,nums,n);
        subset.pop_back();
        funct(idx+1,subset,ans,nums,n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> subset;
        vector<vector<int>> ans;
        int idx = 0;
        funct(idx,subset,ans,nums,n);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    vector<vector<int>> ans = obj.subsets(nums);
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
Time Complexity: O(n*2^n) — each character is processed once
Space Complexity: O(n) — for recursive calls
    (O(n * 2^n) including ans storage)
==================================================
*/