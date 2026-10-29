/*
Problem:  62. Unique Paths
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/unique-paths/description/?utm=codolio"
==================================================
You are given a grid with m rows and n columns. You start from the top-left cell (0,0) and want
to reach the bottom-right cell (m-1,n-1).
From any cell, you are allowed to move only in two directions:
● Right
● Down
You need to return the total number of unique paths from the start cell to the destination cell

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm
    We use recursion with memoization.
    ● Define a recursive function func(row, col) that returns the number of ways to reach cell (row, col) from (0,0).
    ● Base cases:
        ○ If row == 0 and col == 0, there is exactly 1 way (starting point).
        ○ If row < 0 or col < 0, return 0 because it is out of bounds.
    ● If the value for (row, col) is already stored in dp, return it.
    ● Otherwise:
        ○ Ways from top = func(row-1, col)
        ○ Ways from left = func(row, col-1)
        ○ Total ways = top + left
    ● Store the result in dp[row][col].
*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int dfs(int row,int col,vector<vector<int>> &dp){
//         //if reach at intial
//         if(row == 0 && col == 0){
//             return 1;
//         }
//         //if goes out of grid
//         if(row<0 || col<0) return 0;
        
//         if(dp[row][col] != -1) return dp[row][col];
//         int left = dfs(row,col-1,dp);
//         int up = dfs(row-1,col,dp);

//         return dp[row][col] = left+up;
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return dfs(m-1,n-1,dp);
//     }
// };

// int main(){
//     int m = 3,n = 2;
//     Solution obj;
//     cout << obj.uniquePaths(m,n);
//     return 0;
// }

//Befor Memoization time complexity was 2^(m*n)

/*
==================================================
Complexity Analysis:
Time Complexity: O(m * n)
    Each cell (row, col) is computed only once due to memoization.
Space Complexity: O(m * n) + O(m+n)
    m*n for DP table stores results for all grid cells.
    m+n for recursion stack space
==================================================
*/

//Memoization -> Tabulation Steps:
    // 1.Declare Base cases
    // 2. Compress all states in for loop
    // 3.copy the recurrence and return 

//Tabulation Approach
/*
Algorithm:
    This is a bottom-up dynamic programming solution.
    ● Create a dp array of size m x n.
    ● dp[row][col] represents the number of ways to reach cell (i, j).
    ● Base case:
        ○ dp[0][0] = 1
    ● For each cell (row, col):
        ○ Ways from top = dp[row-1][col] if row > 0
        ○ Ways from left = dp[row][col-1] if col > 0
        ○ dp[row][col] = up + left
    ● The final answer is stored in dp[m-1][n-1].

*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //base case dp[0][0] = 1 initialsise in loop here 

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0) dp[0][0] = 1;
                else{
                    int up=0,left=0;
                    if(row>0) up = dp[row-1][col];
                    if(col>0) left = dp[row][col-1];
                    dp[row][col] = up+left;
                }  
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    int m = 3,n = 2;
    Solution obj;
    cout << obj.uniquePaths(m,n);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(m * n)
    Each cell (row, col) is computed only once due to memoization.
Space Complexity: O(m * n)
    m*n for DP table stores results for all grid cells.
==================================================
*/

//beacuse here prev row and prev col used therefore we can space optimizated it
//Tabulation With space Optimization
/*
Algorithm
   From the relation dp[row][col] = dp[row-1][col] + dp[row][col-1], we observe:
    ● To compute the current row, we only need the previous row same col and the current row prev col.
    So we use:
    ● prev array → previous row
    ● temp array → current row
    Steps:
    ● Initialize prev with zeros.
    ● For each row:
        ○ Build temp using values from prev (up) and temp itself (left).
        ○ Assign prev = temp
    Final answer is prev[n-1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //initialize prev array with 0 values
        vector<int> prev(n,0);
        for(int row=0;row<m;row++){
            vector<int> curr(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0) curr[col] = 1;
                else{
                    int up=0,left=0;
                    if(row>0) up = prev[col];
                    if(col>0) left = curr[col-1];
                    curr[col] = up+left;
                }  
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    int m = 3,n = 2;
    Solution obj;
    cout << obj.uniquePaths(m,n);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(m * n)
    Each cell (row, col) is computed only once due to memoization.
Space Complexity: O(n)
    Only two 1D arrays of size n are used.
==================================================
*/
