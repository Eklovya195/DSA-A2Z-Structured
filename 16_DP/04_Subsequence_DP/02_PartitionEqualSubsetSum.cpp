/*
Problem: 416. Partition Equal Subset Sum
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/partition-equal-subset-sum/?utm=codolio"
==================================================
We are given an array arr of n integers.
We need to check whether the array can be divided into two subsets such that the sum of
elements in both subsets is equal.
If such a partition exists, return true, otherwise return false.
Explanation idea:
If the total sum of the array is S, then each subset must have sum S/2.
So the problem reduces to checking whether there exists a subset with sum = S/2.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
==================================================
*/

//This question is exact similar to previous question as we only need to find is there any subsequence 
//whose sum is S/2. if sum is odd return false else do same as did in last question
//Recursive Approach
/*
class Solution {
public:
    bool check(int idx,vector<int> &nums,int target){
        if(target == 0) return true;
        if(idx == 0) return nums[0] == target;

        //pick
        bool pick = false;
        if(nums[idx]<=target){
            pick = check(idx-1,nums,target-nums[idx]);
        }

        //notpick
        bool notpick = check(idx-1,nums,target);
        return pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        return check(n-1,nums,target);
    }
};


//Time Complexity of this approach is O(2^n) and space Complexity is O(n)
*/

//Memoization Approach (We think about Memoization beause of overlapping sub problems)
/*
Algorithm:
    This problem is a direct modification of Subset Sum Equal to Target.
    1. Calculate the total sum of the array.
    2. If the total sum is odd, it is impossible to split it into two equal subsets, so return false.
    3. Otherwise, set target = totalSum / 2.
    4. Now check whether there exists a subset with sum equal to target.
    Define a recursive function f(ind, target):
    ● It returns true if a subset with sum target can be formed using elements from index 0 to ind.
    Base cases:
    ● If target == 0, return true (subset found).
    ● If ind == 0, return true if arr[0] == target, else false.
    Recursive choices:
    ● Not take the current element → f(ind-1, target)
    ● Take the current element (only if arr[ind] <= target) → f(ind-1,
    target-arr[ind])
    Return true if any of the above choices gives true.
    To avoid recomputation, store results in a DP table dp[ind][target].
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int idx,vector<int> &nums,int target, vector<vector<int>> &dp){
        //Memoization Approach
        if(target == 0) return true;
        if(idx == 0) return nums[0] == target;

        if(dp[idx][target] != -1) return dp[idx][target];
        //pick
        bool pick = false;
        if(nums[idx]<=target){
            pick = check(idx-1,nums,target-nums[idx],dp);
        }

        //notpick
        bool notpick = check(idx-1,nums,target,dp);
        return dp[idx][target] = pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return check(n-1,nums,target,dp);
    }
};


int main(){
    vector<int> arr = {1,5,11,5};
    int k = 8;
    Solution obj;
    cout << obj.canPartition(arr);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*k)
    There are N*K states, each solved once.
Space Complexity: O(N*k) + O(N)
    DP table plus recursion stack depth.
==================================================
*/

//Memoization -> Tabulation Steps:
    // 1.Declare Base cases
    // 2. Compress all states in for loop
    // 3.copy the recurrence and return 
//Thumb Rule: whatever you have written for memoization, its opposite for tabulation
//Tabulation Approach
/*
Algorithm:
    This is the bottom-up version of the memoization solution.
    1. Compute total sum. If it is odd, return false.
    2. Set target = totalSum / 2.
    3. Create a DP table dp[n][target+1] where
    dp[i][t] is true if a subset with sum t can be formed using elements from 0 to i.
    Initialization:
    ● For all i, set dp[i][0] = true (sum 0 is always possible).
    ● If arr[0] <= target, set dp[0][arr[0]] = true.
    Transition:
    ● notTaken = dp[i-1][t]
    ● taken = dp[i-1][t-arr[i]] if arr[i] <= t
    ● dp[i][t] = notTaken || taken
    Final answer is dp[n-1][target]
*/


/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        //base case
        for(int idx=0;idx<n;idx++) dp[idx][0] = true;
        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int idx=1;idx<n;idx++){
            for(int t=1;t<=target;t++){
                //pick
                bool pick = false;
                if(nums[idx]<=t){
                    pick = dp[idx-1][t-nums[idx]];
                }

                //notpick
                bool notpick = dp[idx-1][t];
                dp[idx][t] = pick || notpick;
            }
        }
        return dp[n-1][target];
    }
};


int main(){
    vector<int> arr = {1,5,11,5};
    int k = 8;
    Solution obj;
    cout << obj.canPartition(arr);
    return 0;
}
*/


/*
==================================================
Complexity Analysis:
Time Complexity: O(N*k)
    Two nested loops.
Space Complexity: O(N*k)
    DP table stores results for all cells
==================================================
*/

//beacuse here next row same col and next row next col is used only
//Tabulation With space Optimization
/*
Algorithm
   From the relation:
    dp[i][t] = dp[i-1][t] || dp[i-1][t-arr[i]]
    We only need the previous row, so we use a 1D array.
    Steps:
    ● Use a boolean array prev of size K+1.
    ● Initialize prev[0] = true.
    ● If arr[0] <= K, set prev[arr[0]] = true.
    ● For each new element, create cur array:
        ○ cur[0] = true
        ○ Update cur[target] using values from prev.
    ● Move cur into prev.
    Final answer is prev[K].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<bool> prev(k+1,0);
        vector<bool> curr(k+1,0);
        //base case
        prev[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int idx=1;idx<n;idx++){
            curr[0] = true;
            for(int t=1;t<=target;t++){
                //pick
                bool pick = false;
                if(nums[idx]<=t){
                    pick = prev[t-nums[idx]];
                }

                //notpick
                bool notpick = prev[t];
                curr[t] = pick || notpick;
            }
            prev = curr;
        }
        return dp[n-1][target];
    }
};


int main(){
    vector<int> arr = {1,5,11,5};
    int k = 8;
    Solution obj;
    cout << obj.canPartition(arr);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N*k)
    Two nested loops.
Space Complexity: O(k)
    Only one row is stored at any time
==================================================
*/
