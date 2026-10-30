/*
Problem:  63. Unique Paths ||
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/unique-paths-ii/?utm=codolio"
==================================================
You are given an m x n grid where each cell contains either 0 or 1.
0 means the cell is free, and 1 means the cell is blocked.
You start from the top-left cell (0,0) and want to reach the bottom-right cell (m-1,n-1).
You can move only right or down.
If a cell is blocked, you cannot pass through it.
Return the total number of unique paths from start to destination.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm
    We use recursion with memoization.
    //i-> row , j-> col
    ● Define a function func(i, j) that returns the number of ways to reach cell (i, j) from (0,0).
    ● Base cases:
    ○ If i < 0 or j < 0, return 0 (out of bounds).
    ○ If matrix[i][j] == 1, return 0 (blocked cell).
    ○ If i == 0 and j == 0, return 1 (starting point).
    ● If dp[i][j] is already computed, return it.
    ● Otherwise:
    ○ Ways from top = func(i-1, j)
    ○ Ways from left = func(i, j-1)
    ○ Store and return dp[i][j] = up + left.
    The final answer is func(m-1, n-1)
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int row,int col,vector<vector<int>> &obstacleGrid,vector<vector<int>> &dp){
        //base case
        if(row == 0 && col == 0){
            return 1;
        }
        if(row<0 || col<0 || obstacleGrid[row][col] == 1) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        //moving left 
        int left = dfs(row,col-1,obstacleGrid,dp);
        //moving down
        int up = dfs(row-1,col,obstacleGrid,dp);
        return dp[row][col] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //edge case
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //moving from last cell to first cell in opposite direction
        return dfs(m-1,n-1,obstacleGrid,dp);
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution obj;
    cout << obj.uniquePathsWithObstacles(obstacleGrid);
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
    //i-> row , j-> col
    ● Create a DP table dp[m][n] where dp[i][j] stores number of ways to reach (i,j).
    ● If a cell is blocked (matrix[i][j] == 1), set dp[i][j] = 0.
    ● Base case:
        ○ If (i,j) == (0,0) and not blocked, dp[0][0] = 1.
    ● For every cell:
        ○ Ways from top = dp[i-1][j] if i > 0
        ○ Ways from left = dp[i][j-1] if j > 0
        ○ dp[i][j] = up + left
    ● Final answer is dp[m-1][n-1].


*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //edge case
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(obstacleGrid[row][col] == 1) dp[row][col] = 0;
                else if(row==0 && col==0) dp[0][0] = 1;
                else{
                    int left = 0,up = 0;
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
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution obj;
    cout << obj.uniquePathsWithObstacles(obstacleGrid);
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
   From the recurrence
    dp[i][j] = dp[i-1][j] + dp[i][j-1],
    we only need the previous row and current row.
    ● Use two 1D arrays:
        ○ prev → previous row
        ○ curr → current row
    ● If a cell is blocked, set curr[j] = 0.
    ● Otherwise:
        ○ up = prev[j]
        ○ left = curr[j-1]
        ○ curr[j] = up + left
    ● After each row, assign prev = curr.
    ● Final answer is prev[n-1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //edge case
        if(obstacleGrid[0][0] == 1) return 0;
        vector<int> prev(n,-1);
        for(int row=0;row<m;row++){
            vector<int> curr(n,-1);
            for(int col=0;col<n;col++){
                if(obstacleGrid[row][col] == 1) curr[col] = 0;
                else if(row==0 && col==0) curr[0] = 1;
                else{
                    int left = 0,up = 0;
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
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    Solution obj;
    cout << obj.uniquePathsWithObstacles(obstacleGrid);
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
