/*
Problem: 120. Triangle
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/triangle/?utm=codolio"
==================================================
You are given a triangular grid with n rows.
The first row has 1 element, the second row has 2 elements, and so on.
You start from the top element (0,0) and move to the last row.
From a cell (i, j), you are allowed to move only to:
● the bottom cell (i+1, j)
● the bottom-right cell (i+1, j+1)
You need to return the minimum possible path sum from the top to any cell in the last row

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm:
    This problem is a variation of the minimum path sum in a grid, but the grid is triangular.
    A greedy approach fails because choosing the locally smaller value may lead to a larger cost later.
    We use recursion with memoization.
    i->rowidx j->colidx here
    ● Define a recursive function solve(i, j) that returns the minimum path sum starting from cell (i, j) to the bottom.
    ● Base case:
        ○ If i == n-1 (last row), return triangle[i][j].
    ● If the value is already stored in dp[i][j], return it.
    ● Otherwise:
        ○ Move down: triangle[i][j] + solve(i+1, j)
        ○ Move diagonal: triangle[i][j] + solve(i+1, j+1)
        ○ Take the minimum of both.
    ● Store the result in dp to avoid recomputation.
    ● Final answer is solve(0, 0).
This also give tle in leetcode solution
*/

/*
#include <bits/stdc++.h>
using namespace std;
// const int M = 1e9+7;

class Solution {
public:
    int rec(int rowidx,int colidx,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp){
        //Memoization Approach
        if(rowidx==n-1) return triangle[rowidx][colidx];
        //if already present in dp means overlapping subproblem just return ans
        if(dp[rowidx][colidx]!=-1) return dp[rowidx][colidx];
        //move same col downside
        int sameidx = triangle[rowidx][colidx] + rec(rowidx+1,colidx,triangle,n,dp);
        //move next col downside
        int nextidx = triangle[rowidx][colidx] + rec(rowidx+1,colidx+1,triangle,n,dp);
        return dp[rowidx][colidx] = min(sameidx,nextidx);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(0,0,triangle,n,dp);
    }
};

int main(){
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution obj;
    cout << obj.minimumTotal(triangle);
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
    ● Create a dp table with the same shape as the triangle.
    ● Initialize the last row of dp with the values from the triangle, since there is no choice after that.
    ● Start from the second-last row and move upwards:
        ○ For each cell (i, j):
            ■ dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1])
    ● The answer will be stored at dp[0][0]
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        //base case used as last row
        for(int colidx=0;colidx<n;colidx++){
            dp[n-1][colidx] = triangle[n-1][colidx];
        }
        for(int rowidx=n-2;rowidx>=0;rowidx--){
            for(int colidx=rowidx;colidx>=0;colidx--){
                int up = triangle[rowidx][colidx] + dp[rowidx+1][colidx];
                int updig = triangle[rowidx][colidx] + dp[rowidx+1][colidx+1];
                dp[rowidx][colidx] = min(up,updig);
            }
        }
        return dp[0][0];
    }
};

int main(){
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution obj;
    cout << obj.minimumTotal(triangle);
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
   From the recurrence relation:
    dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1])
    We only need the next row to compute the current row.
    ● Use a 1D array front initialized with the last row of the triangle.
    ● Use another array cur for the current row.
    ● Traverse from bottom to top:
        ○ For each cell, compute minimum using front[j] and front[j+1].
    ● After each row, assign front = cur.
    ● Final answer is front[0].

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0);
        //base case used as last row
        for(int colidx=0;colidx<n;colidx++){
            front[colidx] = triangle[n-1][colidx];
        }
        for(int rowidx=n-2;rowidx>=0;rowidx--){
            vector<int> curr(n,0);
            for(int colidx=rowidx;colidx>=0;colidx--){
                int up = triangle[rowidx][colidx] + front[colidx];
                int updig = triangle[rowidx][colidx] + front[colidx+1];
                curr[colidx] = min(up,updig);
            }
            front = curr;
        }
        return front[0];
    }
};

int main(){
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution obj;
    cout << obj.minimumTotal(triangle);
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
