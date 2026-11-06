/*
Problem: 120. Triangle
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/minimum-falling-path-sum/description/?utm=codolio"
==================================================
You are given a 2D grid matrix with integer values.
You can start from any cell in the first row and must reach any cell in the last row.
From a cell (i, j), you are allowed to move to:
● bottom (i+1, j)
● bottom-left (i+1, j-1)
● bottom-right (i+1, j+1)
You need to return the minimum falling path sum (same logic applies for maximum by
replacing min with max).

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm:
    A greedy approach does not work because choosing a locally smaller value may lead to a worse path later.
    We use recursion with memoization.
    ● Define a recursive function dfs(row, col) that returns the minimum falling path sum starting from (row, col).
    ● Base cases:
        ○ If col < 0 or col >= m, return a very large value (1e9) to reject invalid paths.
        ○ If row == n-1 (last row), return matrix[row][col].
    ● If dp[row][col] is already computed, return it.
    ● Otherwise:
        ○ Try all three possible moves: down, down-left, down-right.
        ○ Add the current cell value to the minimum of these.
    ● Since the path can start from any column in the first row, compute the answer for all columns in row 0 and take the minimum.
This also give tle in leetcode solution
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int M = 1e9;
public:
    // Memoization Approach
    int rec(int ridx,int cidx,vector<vector<int>>& matrix,int n,vector<vector<int>> &dp){
        if(cidx<0 || cidx>=n) return M;
        if(ridx==n-1) return matrix[ridx][cidx];
        
        if(dp[ridx][cidx] != -1) return dp[ridx][cidx];
        int leftdig =  rec(ridx+1,cidx-1,matrix,n,dp);
        int rightdig =  rec(ridx+1,cidx+1,matrix,n,dp);
        int down =  rec(ridx+1,cidx,matrix,n,dp);
        return dp[ridx][cidx] = matrix[ridx][cidx] + min({leftdig,rightdig,down});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = M;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int col=0;col<n;col++){
            ans = min(rec(0,col,matrix,n,dp),ans);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    Solution obj;
    cout << obj.minFallingPathSum(matrix);
    return 0;
}
*/


//Befor Memoization time complexity was 2^(n*n) because of recursion
/*
==================================================
Complexity Analysis:
Time Complexity: O(N*N)
    Every cell in the triangle is computed once.
Space Complexity: O(N*N) + O(N)
    DP table plus recursion stack depth.
==================================================
*/

//Memoization -> Tabulation Steps:
    // 1.Declare Base cases
    // 2. Compress all states in for loop
    // 3.copy the recurrence and return 
//Thumb Rule: whatever you written for memoization its opposite for tabulation
//Tabulation Approach
/*
Algorithm:
    This is a bottom-up DP approach.
    ● Create a dp array of size n x n.
    ● Initialize the last row of dp with the values from the matrix.
    ● Move from the second-last row upwards:
        ○ For each cell (row, col):
            ■ Take minimum of:
            ■ dp[row+1][col]
            ■ dp[row+1][col-1] if valid
            ■ dp[row+1][col+1] if valid
            ■ Add current cell value.
    ● After filling, the answer is the minimum value in dp[0].
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int M = 1e9;
public:
    // Tabulation Approach
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //initialise last row as it is
        for(int col=0;col<n;col++){
            dp[n-1][col] = matrix[n-1][col];
        }
        //run from seocnd last row to first row
        for(int row=n-2;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                int leftdown = (col>0) ? dp[row+1][col-1] : M;
                int rightdown = (col<n-1) ? dp[row+1][col+1] : M;
                int down = dp[row+1][col];
                dp[row][col] = matrix[row][col] + min({leftdown,rightdown,down});
            }
        }
        int mini = M;
        for(int col=0;col<n;col++){
            mini = min(mini,dp[0][col]);
        }
        return mini;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    Solution obj;
    cout << obj.minFallingPathSum(matrix);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*N)
    Entire triangular grid is processed once.
Space Complexity: O(N*N)
    DP table stores results for all cells
==================================================
*/

//beacuse here next row same col and next row next col is used only
//Tabulation With space Optimization
/*
Algorithm
   From the relation:
    dp[row][col] = matrix[row][col] + min(dp[row+1][col],dp[row+1][col-1], dp[row+1][col+1])
    We only need the next row to compute the current row.
    ● Use a 1D array front initialized with the last row of the matrix.
    ● For each row from bottom to top:
        ○ Build a curr array using values from front.
        ○ Replace front with curr.
    ● Final answer is the minimum value in front
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
const int M = 1e9;
public:
    // Tabulation Approach with space optimization
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> front(n,0);
        //initialise last row as it is
        for(int col=0;col<n;col++){
            front[col] = matrix[n-1][col];
        }
        //run from seocnd last row to first row
        for(int row=n-2;row>=0;row--){
            vector<int> curr(n,0);
            for(int col=n-1;col>=0;col--){
                int leftdown = (col>0) ? front[col-1] : M;
                int rightdown = (col<n-1) ? front[col+1] : M;
                int down = front[col];
                curr[col] = matrix[row][col] + min({leftdown,rightdown,down});
            }
            front = curr;
        }
        int mini = M;
        for(int col=0;col<n;col++){
            mini = min(mini,front[col]);
        }
        return mini;
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    Solution obj;
    cout << obj.minFallingPathSum(matrix);
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*N)
    Every element in the triangle is processed once.
Space Complexity: O(N)
    Only one row is stored at any time
==================================================
*/
