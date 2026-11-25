/*
Problem: Subsequence Sum equal to target
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1?utm=codolio"
==================================================
Given an array arr[] and target sum k, 
check if there exists a subsequence such that the sum of all elements in the subsequence equals to k.
A subset can be contiguous or non-contiguous, but the order of elements must remain the same
as in the original array.

Input: arr = [10, 1, 2, 7, 6, 1, 5], k = 8.
Output: true
Explanation: Subsequences like [2, 6], [1, 7] sum upto 8
==================================================
*/

//Recursive Approach
/*
class Solution {
  public:
    bool check(int idx,vector<int> &arr,int k){
        //base case
        if(k == 0) return true;
        if(idx == 0) return arr[0] == target;
        
        //pick
        bool pick = false;
        if(arr[idx]<=target){
            pick = check(idx-1,arr,k-arr[idx]);
        }
        
        //not pick
        bool notpick = check(idx-1,arr,k);
        
        return pick||notpick;
    }
  
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        int idx = n-1;
        bool ans = check(idx,arr,k);
        return ans;
    }
};

//Time Complexity of this approach is O(2^n) and space Complexity is O(n)
*/

//Memoization Approach (We think about Memoization beause of overlapping sub problems)
/*
Algorithm:
    Greedy does not work here because we are not optimizing step by step; we just need to check existence.
    We use recursion with memoization using the pick / not pick technique.
    Define a function f(idx, target) that returns true if a subset with sum target can be
    formed using elements from index 0 to idx.
    Base cases:
        ● If target == 0, we already formed the required sum, return true.
        ● If idx == 0, return true if arr[0] == target, else false.
    At each index, we have two choices:
        ● Not pick the current element → f(idx-1, target)
        ● Pick the current element (only if arr[idx] <= target) → f(idx-1,target-arr[idx])
    If either choice returns true, the answer is true.
    To avoid recomputation, store results in a DP table dp[idx][target].
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(int idx,vector<int> &arr,int k,vector<vector<int>> &dp){
        //base case
        if(k == 0) return true;
        if(idx == 0) return arr[0] == k;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        //pick
        bool pick = false;
        if(arr[idx]<=k){
            pick = check(idx-1,arr,k-arr[idx],dp);
        }
        
        //not pick
        bool notpick = check(idx-1,arr,k,dp);
        
        return dp[idx][k] = pick||notpick;
    }
  
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int idx = n-1;
        return check(idx,arr,k,dp);
    }
};

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;
    Solution obj;
    cout << obj.checkSubsequenceSum(arr);
    return 0;
}
*/

//Befor Memoization time complexity was 2^(n*n) because of recursion
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
    We convert the recursive solution into bottom-up DP.
    Let dp[i][t] be true if a subset with sum t can be formed using elements from index 0 to i.
    Initialization:
    ● For all i, dp[i][0] = true (sum 0 is always possible).
    ● If arr[0] <= K, set dp[0][arr[0]] = true.
    Transition:
    ● notTaken = dp[i-1][t]
    ● taken = dp[i-1][t-arr[i]] if arr[i] <= t
    ● dp[i][t] = notTaken || taken
    Final answer is dp[n-1][K].
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        //Tabulation Approach
        int n = arr.size();
        vector<vector<char>> dp(n,vector<char>(k+1,0));
        //base cases
        for(int idx=0;idx<n;idx++) dp[idx][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;

        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=k;target++){
                //pick
                bool pick = false;
                if(arr[idx]<=target){
                    pick = dp[idx-1][target-arr[idx]];
                }

                //not pick
                bool notpick = dp[idx-1][target];
                dp[idx][target] = pick || notpick;
            }
            if(dp[idx][k]) return true; // Stop immediately once sum K is found
        }
        return dp[n-1][k];
    }
};

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;
    Solution obj;
    cout << obj.checkSubsequenceSum(arr,k);
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
   From the relation
    dp[i][t] = dp[i-1][t] || dp[i-1][t-arr[i]]
    We only need the previous row, so we can optimize space to 1D.
    Steps:
    1. Compute total sum, return false if odd.
    2. Set target = totalSum / 2.
    3. Use a 1D array prev[target+1].
    4. Initialize:
    ○ prev[0] = true
    ○ If arr[0] <= target, set prev[arr[0]] = true
    5. For each new element, build a new cur array using prev.
    6. Move cur into prev.
    Final answer is prev[target].
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
        vector<bool> prev(target+1,0);
        vector<bool> curr(target+1,0);
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
            if(curr[target]) return true; // Stop immediately once sum K is found
            prev = curr;
        }
        return prev[target];
    }
};

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;
    Solution obj;
    cout << obj.checkSubsequenceSum(arr,k);
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
