/*
Problem:  Frog Jump with K distance
Platform: DP / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/frog-jump/description/?utm=codolio"
==================================================
A frog wants to reach the last step of a staircase. There are n steps, and each step has a height
given in an array heights. The frog starts at index 0 and wants to reach index n-1.
From any step i, the frog can jump to any step between i+1 and i+k (as long as that step
exists).
The energy required for a jump from step i to step j is abs(heights[i] - heights[j]).
The task is to find the minimum total energy needed to reach the last step.

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, 
            then 2 units to the 3rd stone, 
            then 2 units to the 4th stone, 
            then 3 units to the 6th stone, 
            4 units to the 7th stone, and 
            5 units to the 8th stone.
==================================================
*/

//Approach 1: Memoization Approach
/*
Algorithm
We use recursion with memoization to avoid recalculating the same states again and again.
    ● Define a function solveUtil(ind) that returns the minimum energy required to reach step ind.
    ● Base case:
        If ind == 0, the cost is 0 because the frog starts there.
    ● If the answer for ind is already stored in the dp array, return it.
    ● Otherwise, try all jumps from 1 to k:
        ○ If ind - jump >= 0, calculate the cost of jumping from ind-jump to ind.
        ○ Take the minimum of all possible jump costs.
    ● Store the result in dp[ind] and return it.
    ● The final answer is solveUtil(n-1)
*/

#include <bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     int rec(vector<int> &height,int idx,vector<int> &dp){
//         //base case
//         if(idx == 0) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int minSteps = INT_MAX;
//         for(int jump=0;jump<)
//     }

//     int minCost(vector<int>& height) {
//         int n = height.size();
//         vector<int> dp(n,-1);
//         return rec(height,n-1,dp);
//     }
// };

int main(){
    vector<int> stones = {0,1,3,5,6,8,12,17};
    Solution obj;
    cout << obj.minCost(stones);
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^n)  ->  recursion(2^n)
Space Complexity: O(n)  -> recursion
==================================================
*/