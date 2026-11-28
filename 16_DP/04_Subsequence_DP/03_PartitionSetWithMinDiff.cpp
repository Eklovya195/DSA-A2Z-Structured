/*
Problem: 2035. Partition Array Into Two Arrays to Minimize Sum Difference
Platform: DP / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1"
  This one also contain -ve no: "https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/?utm=codolio"
==================================================
We are given an array arr of n integers.
We need to partition the array into two subsets such that the absolute difference between
their sums is minimum.
Key idea:
If the total sum of the array is S and one subset has sum s1, then the other subset has sum S- s1.
The absolute difference will be | (S - s1) - s1 | = |S - 2*s1|.
So, we only need to find all possible subset sums s1 and choose the one that minimizes this difference.

Example explanation:
For arr = [1,2,3,4], total sum = 10.
Possible subset sum s1 = 5 gives difference |10 - 2*5| = 0, which is minimum.
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
    This problem is a variation of Subset Sum Equal to Target.
    ● First calculate the total sum totSum.
    ● A subset sum can range from 0 to totSum.
    ● Use a recursive function f(ind, target) that returns true if a subset with sum target can be formed using elements from index 0 to ind.
    Base cases:
    ● If target == 0, return true.
    ● If ind == 0, return true if arr[0] == target, else false.
    Choices:
    ● Do not take the current element → f(ind-1, target)
    ● Take the current element (only if arr[ind] <= target) → f(ind-1,target-arr[ind])
    Store results in a DP table to avoid recomputation.
    After filling the DP table, iterate over all possible subset sums s1 that are achievable and compute
    abs(totSum - 2*s1).
    Return the minimum value.
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool check(int idx,int target,vector<int> &arr,vector<vector<int>> &dp){
        //base case
        if(target == 0) return true;
        if(idx == 0) return arr[0] == target;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        //pick
        bool pick = false;
        if(arr[idx]<=target){
            pick = check(idx-1,target-arr[idx],arr,dp);
        }
        
        //not pick
        bool notpick = check(idx-1,target,arr,dp);
        
        return dp[idx][target] = pick||notpick;
    }

    int minDifference(vector<int>& arr) {
        //Memoization Approach
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int mini = 1e9;
        // Only need to check up to sum / 2 due to symmetry
        for (int s1 = 0; s1 <= sum / 2; s1++) {
            // Use the return value of check() directly so base cases are captured
            if (check(n - 1, s1, arr, dp)) {
                mini = min(mini, abs((sum - s1) - s1));
            }
        }
        return mini;
    }
};

int main(){
    vector<int> arr = {1, 4};
    Solution obj;
    cout << obj.minDifference(arr);
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
    Convert the memoization solution into bottom-up DP.
    ● Create a DP table dp[n][totSum+1] where
    dp[i][s] = true if a subset with sum s can be formed using elements 0..i.
    ● Initialization:
    ○ For all i, dp[i][0] = true.
    ○ If arr[0] <= totSum, set dp[0][arr[0]] = true.
    ● Fill the table using:
    ○ notTaken = dp[i-1][s]
    ○ taken = dp[i-1][s-arr[i]] if arr[i] <= s
    ● After filling, check all s where dp[n-1][s] is true and compute the minimum difference.
*/


/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        //Tabulation Approach
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }

        //Tabulation approach
        //last row of dp will tell that this sum is possible or not  
        int k = sum;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));

        //base case
        for(int idx=0;idx<n;idx++) dp[idx][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;
        for(int idx=1;idx<n;idx++){
            for(int t=1;t<=k;t++){
                bool notTake = dp[idx-1][t];
                bool take = false;
                if(arr[idx]<= t) take = dp[idx-1][t-arr[idx]];
                dp[idx][t] = take || notTake;
            }
        }

        //finding minimum absolute difference
        int mini = 1e9;
        for(int s1=0;s1<=sum/2;s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini,abs((sum-s1)-s1));
            }
        }
        return mini;
    }
};

int main(){
    vector<int> arr = {1, 6, 11, 5};
    Solution obj;
    cout << obj.minDifference(arr);
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
    dp[i][s] = dp[i-1][s] || dp[i-1][s-arr[i]],
    we only need the previous row.
    ● Use a 1D boolean array prev.
    ● Initialize prev[0] = true.
    ● If arr[0] <= totSum, set prev[arr[0]] = true.
    ● For each element, build a new cur array using prev.
    ● After processing all elements, check all achievable sums and compute the minimum difference.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        //Tabulation Approach
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }

        //Tabulation approach with space optimization
        //last row of dp will tell that this sum is possible or not  
        int k = sum;
        vector<bool> prev(k+1,false);
        vector<bool> curr(k+1,false);

        //base case
        prev[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int idx=1;idx<n;idx++){
            curr[0] = true;
            for(int t=1;t<=k;t++){
                bool notTake = prev[t];
                bool take = false;
                if(arr[idx]<= t) take = prev[t-arr[idx]];
                curr[t] = take || notTake;
            }
            prev = curr;
        }

        //finding minimum absolute difference
        int mini = 1e9;
        for(int s1=0;s1<=sum/2;s1++){
            if(prev[s1] == true){
                mini = min(mini,abs((sum-s1)-s1));
            }
        }
        return mini;
    }
};

int main(){
    vector<int> arr = {1, 6, 11, 5};
    Solution obj;
    cout << obj.minDifference(arr);
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
