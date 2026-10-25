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

//This Approach will give tle as this is simple recursion approach 
// but we need to uderstand this first to understand the solution

// #include <bits/stdc++.h>
// using namespace std;

// //this is the solution
// class Solution {
// public:
//     int rec(vector<int>& heights,int idx,int k){
//         if(idx == heights.size()-1) return 0;
//         int minSteps = INT_MAX;
//         for(int i=1;i<=k;i++){
//            if(idx+i<heights.size()){
//                 int jumps = rec(heights,idx+i,k) + abs(heights[idx]-heights[idx+i]);
//                 minSteps = min(minSteps,jumps);
//            }
//         }
//         return minSteps;
//     }

//     int frogJump(vector<int>& heights, int k) {
//         int n = heights.size();
//         return rec(heights,0,k);
//     }
// };


// int main(){
//     vector<int> heights = {10, 5, 20, 0, 15};
//     int k = 2;
//     Solution obj;
//     cout << obj.frogJump(heights,k);
//     return 0;
// }

/*
==================================================
Complexity Analysis:
Time Complexity: O(k^n)
Space Complexity: O(n)
    The recursion stack goes up to n in the worst case.
==================================================
*/


//Approach 1: Memoization Approach
/*
Algorithm
We use recursion with memoization to avoid recalculating the same states again and again.
    ● Define a function rec(ind) that returns the minimum energy required to reach step ind.
    ● Base case:
        If ind == n-1, the cost is 0 because the frog reach at the end.
    ● If the answer for ind is already stored in the dp array, return it.
    ● Otherwise, try all jumps from 1 to k:
        ○ If ind + jump < n, calculate the cost of jumping from index to index+jump.
        ○ Take the minimum of all possible jump costs.
    ● Store the result in dp[ind] and return it.
    ● The final answer is min of all energy
*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int rec(vector<int>& heights,int idx,int k,vector<int> &dp){
//         if(idx == heights.size()-1) return 0;
//         if(dp[idx]!=-1) return dp[idx];
//         int minSteps = INT_MAX;
//         for(int i=1;i<=k;i++){
//            if(idx+i<heights.size()){
//                 int jumps = rec(heights,idx+i,k,dp) + abs(heights[idx]-heights[idx+i]);
//                 minSteps = min(minSteps,jumps);
//            }
//         }
//         return dp[idx] = minSteps;
//     }

//     int frogJump(vector<int>& heights, int k) {
//         int n = heights.size();
//         vector<int> dp(n,-1);
//         return rec(heights,0,k,dp);
//     }
// };


// int main(){
//     vector<int> heights = {10, 5, 20, 0, 15};
//     int k = 2;
//     Solution obj;
//     cout << obj.frogJump(heights,k);
//     return 0;
// }

/*
==================================================
Complexity Analysis:
Time Complexity: O(n * k)
    For each index, we try up to k jumps, and each state is computed only once due to memoization.
Space Complexity: O(n)
    The dp array stores results for all n indices. The recursion stack also goes up to n in the worst case.
==================================================
*/


//Approach 2: Tablulation Approach
/*
Algorithm
    This approach solves the problem using bottom-up dynamic programming.
    ● Create a dp array where dp[i] represents the minimum energy required to reach step i.
    ● Initialize dp[n-1] = 0 because no energy is needed at the start.
    ● For each step i from n-2 to 0:
        ○ Try all jumps from 1 to k.
        ○ If i + j < n, compute:
                dp[i + j] + abs(height[i] - height[i + j])
                    ○ Store the minimum of all such values in dp[i].
    ● The answer is stored in dp[0].
        This builds the solution step by step without recursion.
*/

#include <bits/stdc++.h>
using namespace std;

//here moving from n-2 to 0
// class Solution {
// public:
//     int frogJump(vector<int>& heights, int k) {
//         int n = heights.size();
//         vector<int> dp(n,INT_MAX);
//         dp[n-1] = 0;
//         for(int i=n-2;i>=0;i--){
//             for(int j=1;j<=k;j++){
//                 if(i+j<n){
//                     int jumps = dp[i+j] + abs(heights[i]-heights[i+j]);
//                     dp[i] = min(dp[i],jumps);
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

//use this if you want bottom to up like from 0 to n-1
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int minSteps = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jumps = dp[i-j] + abs(heights[i]-heights[i-j]);
                    minSteps = min(minSteps,jumps);
                }
            }
            dp[i] = minSteps;
        }
        return dp[n-1];
    }
};


int main(){
    vector<int> heights = {10, 5, 20, 0, 15};
    int k = 2;
    Solution obj;
    cout << obj.frogJump(heights,k);
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(n * k)
    For each index, we try up to k jumps, and each state is computed only once due to memoization.
Space Complexity: O(n)
    The dp array stores results for all n indices. The recursion stack also goes up to n in the worst case.
==================================================
*/


// NOTE:- We can reduce the space complexity from n to k but not to 1