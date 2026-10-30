/*
Problem:  64. Min Path Sum
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/minimum-path-sum/?utm=codolio"
==================================================
You are given an m x n grid filled with non-negative numbers.
You start from the top-left cell (0,0) and want to reach the bottom-right cell (m-1,n-1).
You are allowed to move only right or down at any point.
Your task is to find the minimum possible sum of numbers along any valid path.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm
    This problem is similar to Grid Unique Paths, but instead of counting paths, we minimize cost.
    Why greedy does not work:
    Choosing the locally smallest value can lead to a path with a larger cost later. Hence, we must
    explore all valid paths using DP.
    Steps:
    ● Define a recursive function minPath(i, j) that returns the minimum path sum to reach cell (i,j).
    ● Base cases:
        ○ If (i,j) == (0,0), return grid[0][0].
        ○ If i < 0 or j < 0, return a very large value (1e9) to reject invalid paths.
    ● If dp[i][j] is already computed, return it.
    ● Otherwise:
        ○ Cost from up = grid[i][j] + minPath(i-1, j)
        ○ Cost from left = grid[i][j] + minPath(i, j-1)
        ○ Store and return the minimum of the two.
    ● Final answer is minPath(n-1, m-1)
*/


/*
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

class Solution {
public:
    int pathcheck(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row==0 && col==0){
            return grid[0][0];
        }
        if(row<0 || col<0) return M;
        if(dp[row][col] != -1) return dp[row][col];
        int left = grid[row][col] + pathcheck(row,col-1,grid,dp);
        int up = grid[row][col] + pathcheck(row-1,col,grid,dp);
        return dp[row][col] = min(left,up);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return pathcheck(m-1,n-1,grid,dp);
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution obj;
    cout << obj.minPathSum(grid);
    return 0;
}
*/


//Befor Memoization time complexity was 2^(m*n) because of recursion

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
    This is a bottom-up DP approach.
    ● Create a dp[n][m] table.
    ● Base case: dp[0][0] = grid[0][0].
    ● Traverse the grid row by row:
        ○ For each cell (i,j):
            ■ Cost from up = dp[i-1][j] if i>0 else large value
            ■ Cost from left = dp[i][j-1] if j>0 else large value
            ■ dp[i][j] = grid[i][j] + min(up, left)
    ● Final answer is dp[n-1][m-1].
*/

/*
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0 && col==0) dp[0][0] = grid[0][0];
                else{
                    int up = M,left = M;
                    //requiring prev row j col
                    if(row>0) up = grid[row][col] + dp[row-1][col];
                    //requiring same row prev col
                    if(col>0) left = grid[row][col] + dp[row][col-1];
                    dp[row][col] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution obj;
    cout << obj.minPathSum(grid);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(m * n)
    Each cell (row, col) is computed only once due to memoization.
Space Complexity: O(m * n)
    m*n for 2-D DP table stores results for all grid cells.
==================================================
*/

//beacuse here prev row and prev col used therefore we can space optimizated it
//Tabulation With space Optimization
/*
Algorithm
   From the recurrence:
    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
    We only need:
    ● Previous row
    ● Current row
    Steps:
    ● Use a 1D array prev for previous row.
    ● For each row, build a temp array for current row.
    ● After finishing a row, assign prev = temp.
    ● Final answer is prev[m-1].
*/


#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        for(int row=0;row<m;row++){
            vector<int> curr(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0) curr[0] = grid[0][0];
                else{
                    int up = M,left = M;
                    if(row>0) up = grid[row][col] + prev[col];
                    if(col>0) left = grid[row][col] + curr[col-1];
                    curr[col] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution obj;
    cout << obj.minPathSum(grid);
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
