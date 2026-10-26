/*
Problem:  198. House Robber
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/house-robber/description/?utm=codolio"
==================================================
Given an array of N positive integers, we need to find the maximum sum of a subsequence such
that no two chosen elements are adjacent in the original array.
A subsequence means we can delete some elements, but the remaining elements must stay in
the same order

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
==================================================
*/

//Memoization Approach
/*
Algorithm
    We use recursion with the pick / not-pick idea.
    At every index i, we have two choices:
        ● Pick the current element arr[i]. If we pick it, we cannot pick the adjacent element, so we move to index i-2.
        ● Do not pick the current element. Then we move to index i-1.
    We define a recursive function that returns the maximum sum we can get up to index i.
        ● If i < 0, return 0 because no elements are left.
        ● If i == 0, return arr[0] because only one element is available.
        ● If the answer for index i is already computed, return it from the dp array.
        ● Otherwise, compute both choices (pick and not pick), take the maximum, store it in dp[i], and return it.
    The final answer is the value computed for the last index
*/
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int funGenerate(int idx,vector<int> &nums,vector<int> &dp){
        //base case
        if(idx==0) return dp[idx] = nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //pick
        int leftsum =  nums[idx] + funGenerate(idx-2,nums,dp);
        //not pick
        int rightsum =  0 + funGenerate(idx-1,nums,dp);
        return dp[idx] = max(leftsum,rightsum);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return funGenerate(n-1,nums,dp);
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution obj;
    cout << obj.rob(nums);
    return 0;
}
*/

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
    ● dp[0] = arr[0] because only one element is available.
    ● dp[1] = max(arr[0], arr[1]) because we can pick only one of them.
    ● For every index i from 2 to n-1:
        ○ If we pick arr[i], the sum becomes arr[i] + dp[i-2].
        ○ If we do not pick it, the sum is dp[i-1].
        ○ Store the maximum of these two in dp[i].
    ● The answer is dp[n-1].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //Tabulation (Bottm Up Approach)
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[n-1];
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
Space Complexity: O(N)
    space by dp array
==================================================
*/


//Tabulation With space Optimization
/*
Algorithm
    In the tabulation approach, we only need the results of the previous two indices to compute the
    current answer. So instead of using a full dp array, we use two variables.
    ● prev stores the answer up to the previous index.
    ● prev2 stores the answer up to two indices back.
    ● For each element:
        ○ Include current element: nums[i] + prev2
        ○ Exclude current element: prev
        ○ Take the maximum of both and store it in a temporary variable.
        ○ Update prev2 and prev.
    ● The final answer is stored in prev
*/
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //Tabulation With Space Optimization
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int notTake = 0 + prev;
            int curri = max(take,notTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution obj;
    cout << obj.rob(nums);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each index is solved once and stored in the dp array.
Space Complexity: O(1)
==================================================
*/

