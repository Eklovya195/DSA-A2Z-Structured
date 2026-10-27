/*
Problem:  213. House Robber ||
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/house-robber-ii/?utm=codolio"
==================================================
A thief wants to rob houses arranged in a circular street. Each house has some money stored in
it, given in an array Arr.
The security system is active such that if two adjacent houses are robbed, the police will be
notified.
Because the houses are in a circle, the first and the last house are also adjacent.
The task is to find the maximum amount of money the thief can rob without robbing any two
adjacent houses.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
==================================================
*/

//Memoization Approach
/*
Algorithm
    This problem is a variation of the linear House Robber problem.
    Because the houses are circular:
    ● We cannot pick both the first and the last house together.
    So we split the problem into two linear subproblems:
    1. Exclude the first house and consider houses from index 1 to n-1
    2. Exclude the last house and consider houses from index 0 to n-2
    For both cases, we solve the linear House Robber problem and take the maximum of the two results.
    For the linear solution:
    We use recursion with the pick / not-pick idea.
    At every index i, we have two choices:
        ● Pick the current element arr[i]. If we pick it, we cannot pick the adjacent element, so we move to index i-2.
        ● Do not pick the current element. Then we move to index i-1.
    We define a recursive function that returns the maximum sum we can get up to index i.
        ● If i < start, return 0 because no elements are left.
        ● If i == start, return arr[0] because only one element is available.
        ● If the answer for index i is already computed, return it from the dp array.
        ● Otherwise, compute both choices (pick and not pick), take the maximum, store it in dp[i], and return it.
    The final answer is the value computed for the last index
*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int CalculatingSum(int idx,int start,vector<int> &nums,vector<int> &dp){
//         if(idx == start) return nums[idx];
//         if(idx<start) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         //pick
//         int pick = nums[idx] + CalculatingSum(idx-2,start,nums,dp);
//         //not pick
//         int notpick = 0 + CalculatingSum(idx-1,start,nums,dp);
//         return dp[idx] = max(pick,notpick);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         vector<int> dp(n,-1);
//         int ans1 = CalculatingSum(n-1,1,nums,dp);
//         fill(dp.begin(),dp.end(),-1);
//         int ans2 = CalculatingSum(n-2,0,nums,dp);
//         return max(ans1,ans2);
//     }
// };

// int main(){
//     vector<int> nums = {2,3,2};
//     Solution obj;
//     cout << obj.rob(nums);
//     return 0;
// }


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each index is solved once and stored in the dp array.
Space Complexity: O(N + N)
    One O(N) for the dp array and one O(N) for the recursion stack
==================================================
*/

//Tabulation Approach
/*
Algorithm:
    This is a bottom-up dynamic programming approach.
    ● Create a dp array where dp[i] stores the maximum sum possible up to index i.
    ● dp[start] = arr[start] because only one element is available.
    ● dp[1] = max(arr[0], arr[1]) because we can pick only one of them.
    ● For every index i from 2 to n-1:
        ○ If we pick arr[i], the sum becomes arr[i] + dp[i-2].
        ○ If we do not pick it, the sum is dp[i-1].
        ○ Store the maximum of these two in dp[i].
    ● The answer is dp[end-1].
*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int solve(vector<int> &nums,int start,int end){
//         //Tabulation (Bottm Up Approach)
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         dp[start] = nums[start];

//         for(int i=start+1;i<=end;i++){
//             int take = nums[i];
//             if(i>start+1) take += dp[i-2];
//             int notTake = 0 + dp[i-1];
//             dp[i] = max(take,notTake);
//         }
//         return dp[end-1];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         int ans1 = solve(nums,0,n-2);
//         int ans2 = solve(nums,1,n-1);
//         return max(ans1,ans2);
//     }
// };

// int main(){
//     vector<int> nums = {1,2,3,1};
//     Solution obj;
//     cout << obj.rob(nums);
//     return 0;
// }


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each index is solved once and stored in the dp array.
Space Complexity: O(N)
    space by dp array
==================================================
*/


//Tabulation With space Optimization
/*
Algorithm
    This problem is a variation of the linear House Robber problem.
    Because the houses are circular:
    ● We cannot pick both the first and the last house together.
    So we split the problem into two linear subproblems:
    1. Exclude the first house and consider houses from index 1 to n-1
    2. Exclude the last house and consider houses from index 0 to n-2
    For both cases, we solve the linear House Robber problem and take the maximum of the two
    results.
    For the linear solution:
    ● prev stores the maximum money robbed till the previous house
    ● prev2 stores the maximum money robbed till the house before the previous one
    ● At each house, we decide:
        ○ Pick the current house and add prev2
        ○ Or skip the current house and take prev
    ● We update prev and prev2 accordingly
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums,int start,int end){
        //Tabulation (Bottm Up Approach)
        int n = nums.size();
        int prev = nums[start];
        int prev2 = 0;

        for(int i=start+1;i<=end;i++){
            int take = nums[i];
            if(i>start+1) take += prev2;
            int notTake = 0 + prev;
            int curri = max(take,notTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans1 = solve(nums,0,n-2);
        int ans2 = solve(nums,1,n-1);
        return max(ans1,ans2);
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution obj;
    cout << obj.rob(nums);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each index is solved once and stored in the dp array.
Space Complexity: O(1)
==================================================
*/



// you can also keep same code of solve as in house robber problem and 
// made changes in main(rob) code by creating two temp array and breaking problem in two piece

// class Solution {
// public:
//     //here that code is eaxct same as house robber 
//     int CalculatingSum(int idx,vector<int> &nums,vector<int> &dp){
//         if(idx == 0) return nums[idx];
//         if(idx<0) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         //pick
//         int pick = nums[idx] + CalculatingSum(idx-2,nums,dp);
//         //not pick
//         int notpick = 0 + CalculatingSum(idx-1,nums,dp);
//         return dp[idx] = max(pick,notpick);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[0];
//         vector<int> temp1,temp2;
//         for(int i=0;i<n;i++){
//             if(i!=0) temp1.push_back(nums[i]);
//             if(i!=n-1) temp2.push_back(nums[i]);
//         }
//         vector<int> dp(n,-1);
//         //here problem is break into two pieces
//         int ans1 = CalculatingSum(temp1.size()-1,temp1,dp);
//         fill(dp.begin(),dp.end(),-1);
//         int ans2 = CalculatingSum(temp2.size()-1,temp2,dp);
//         return max(ans1,ans2);
//     }
// };
