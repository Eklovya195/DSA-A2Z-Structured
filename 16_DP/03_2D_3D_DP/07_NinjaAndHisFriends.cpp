/*
Problem: Ninja And His Friends Or Maxiumum Chocolates Pickup(GFG)
Platform: DP / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm=codolio"
                "https://takeuforward.org/practice/dsa/ninja-and-his-friends?utm=codolio"
==================================================
We are given a grid of size N x M where each cell contains some chocolates.
Alice starts at cell (0,0) and Bob starts at cell (0, M-1).
Both Alice and Bob move row by row downward. From a cell (i, j), they can move to:
● bottom (i+1, j)
● bottom-left (i+1, j-1)
● bottom-right (i+1, j+1)
When they visit a cell, they collect all chocolates from that cell.
If both of them land on the same cell, chocolates are counted only once.
They cannot move outside the grid.
We need to return the maximum total chocolates Alice and Bob can collect together

Input: grid[][] = [[4, 1, 2], [3, 6, 1], [1, 6, 6], [3, 1, 2]]
Output: 32
Explaination:
The path followed by first robot is: (0, 0) -> (1, 0) -> (2, 1) -> (3, 0), so first robot collected: 4 + 3 + 6 + 3 = 16 chocolates.
The path followed by second robot is: (0, 2) -> (1, 1) -> (2, 2) -> (3, 2), so second robot collected: 2 + 6 + 6 + 2 = 16 chocolates.
==================================================
*/

//Memoization Approach (We think about Memoiztion beause of overlapping sub problems)
/*
Algorithm:
    This is a 3-dimensional DP problem because the state depends on:
    ● current row row
    ● Alice’s column colA
    ● Bob’s column colB
    Greedy does not work because taking the maximum chocolates at the current step may block better choices later.
    We use recursion with memoization.
    ● Define rec(row, colA, colB) = maximum chocolates collectible starting from row row, where Alice is at column colA and Bob at column colB.
    ● Prunity Case:
        ○ If colA or colB goes out of bounds, return a very small value (-1e9) to mark an invalid path.
    ● Base case:
        ○ If row == n-1 (last row):
            ■ If colA == colB, return grid[row][colA]
            ■ Else return grid[row][colA] + grid[row][colB]
    ● If the value is already stored in dp, return it.
    ● Otherwise:
        ○ From (row, colA, colB), try all 3 x 3 = 9 combinations of moves for Alice and Bob.
        ○ For each combination, move to the next row and take the maximum result.
    ● Store and return the result
*/

/*
#include <bits/stdc++.h>
using namespace std;

//Memoization Approach
class Solution {
    const int M = -1e9;
  public:
    int rec(int row,int colA,int colB,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        //prunity (Out of grid case)
        if(colA<0 || colA>=m || colB<0 || colB>=m) return M;

        //base case
        if(row==n-1){
            if(colA==colB) return grid[row][colA];
            else return grid[row][colA]+grid[row][colB];
        }

        //if already available in the dp Memoization
        if(dp[row][colA][colB]!=-1) return dp[row][colA][colB];
        //here 9 cases will be there which needs to be checked 
        //for each one Alice change there are 3 possiblity of changes for Bob also
        //cColA -> change in col of Alice
        int maxi = 0;
        //3*3 loop is used here 
        for(int cColA=-1;cColA<=1;cColA++){
            for(int cColB=-1;cColB<=1;cColB++){
                //if both Alice and Bob are on same col
                if(colA==colB) maxi = max(maxi,grid[row][colA]+rec(row+1,colA+cColA,colB+cColB,grid,dp));
                else maxi = max(maxi,grid[row][colA]+grid[row][colB]+rec(row+1,colA+cColA,colB+cColB,grid,dp));
            }
        }
        return dp[row][colA][colB]=maxi;
    }
  
    int maxChocolate(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        //3D DP
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return rec(0,0,m-1,grid,dp);
    }
};

int main(){
    vector<vector<int>> grid = {{4,1,2},{3,6,1},{1,6,6},{3,1,2}};
    Solution obj;
    cout << obj.maxChocolate(grid);
    return 0;
}
*/


//Befor Memoization time complexity was 3^n*3^n*9 because of recursion
/*
==================================================
Complexity Analysis:
Time Complexity: O(N * M * M * 9)
    There are N * M * M states, and for each we try 9 move combinations.
Space Complexity: O(N * M * M) + O(N)
    DP table plus recursion stack
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
    This is the bottom-up version of the memoized solution.
    ● Create a 3D DP table dp[i][colA][colB].
    ● Base case:
        ○ Fill the last row (i = n-1) directly using grid values.
    ● Move from row n-2 up to 0:
        ○ For each (colA, colB) pair, try all 9 move combinations.
        ○ Take the maximum possible chocolates.
    ● The final answer is stored at dp[0][0][m-1]
*/

/*
#include <bits/stdc++.h>
using namespace std;

//Tabulation Approach
class Solution {
    const int M = -1e9;
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        //3D DP
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        //base case for last row
        for(int colA=0;colA<m;colA++){
            for(int colB=0;colB<m;colB++){
                if(colA==colB) dp[n-1][colA][colB] = grid[n-1][colA];
                else dp[n-1][colA][colB] = grid[n-1][colA] + grid[n-1][colB];
            }
        }
        //run loop from row n-2 to 0
        for(int row=n-2;row>=0;row--){
            for(int colA=0;colA<m;colA++){
                for(int colB=0;colB<m;colB++){
                    int maxi = M;
                    //Alice and Bob are on same col or differnt column
                    int value = (colA==colB)?grid[row][colA]:grid[row][colA] + grid[row][colB];
                    //3*3 loop for every way 
                    for(int cColA=-1;cColA<=1;cColA++){ 
                        for(int cColB=-1;cColB<=1;cColB++){
                            //if not out of grid
                            int newColA = colA + cColA;
                            int newColB = colB + cColB;
                            if(newColA>=0 && newColA<m && newColB>=0 && newColB<m){
                                int total = value + dp[row+1][newColA][newColB];
                                maxi = max(maxi,total);
                            }
                        }
                    }
                    dp[row][colA][colB] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

int main(){
    vector<vector<int>> grid = {{4,1,2},{3,6,1},{1,6,6},{3,1,2}};
    Solution obj;
    cout << obj.maxChocolate(grid);
    return 0;
}

*/
/*
==================================================
Complexity Analysis:
Time Complexity: O(N * M * M * 9)
Space Complexity: O(N * M * M)
==================================================
*/

//beacuse here next row same col and next row next col is used only
//Tabulation With space Optimization
/*
Algorithm
   In tabulation, each row depends only on the next row.
    ● Instead of a full 3D DP table, use:
        ○ front[m][m] → stores values for row i+1
        ○ curr[m][m] → stores values for row i
    ● Initialize front using the last row of the grid.
    ● Move upward row by row, filling curr from front.
    ● After each row, assign front = curr.
    ● Final answer is front[0][m-1].
*/

#include <bits/stdc++.h>
using namespace std;

//Tabulation Approach with space optimization
class Solution {
    const int M = -1e9;
  public:
    int maxChocolate(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        //3D DP -> 2D reduced space 
        vector<vector<int>> front(m,vector<int>(m,0));
        vector<vector<int>> curr(m,vector<int>(m,0));
        //base case for last row
        for(int colA=0;colA<m;colA++){
            for(int colB=0;colB<m;colB++){
                if(colA==colB) front[colA][colB] = grid[n-1][colA];
                else front[colA][colB] = grid[n-1][colA] + grid[n-1][colB];
            }
        }
        //run loop from row n-2 to 0
        for(int row=n-2;row>=0;row--){
            for(int colA=0;colA<m;colA++){
                for(int colB=0;colB<m;colB++){
                    int maxi = M;
                    //Alice and Bob are on same col or differnt column
                    int value = (colA==colB)? grid[row][colA]:grid[row][colA] + grid[row][colB];
                    //3*3 loop for every way 
                    for(int cColA=-1;cColA<=1;cColA++){ 
                        for(int cColB=-1;cColB<=1;cColB++){
                            //if not out of grid
                            int newColA = colA + cColA;
                            int newColB = colB + cColB;
                            if(newColA>=0 && newColA<m && newColB>=0 && newColB<m){
                                int total = value + front[newColA][newColB];
                                maxi = max(maxi,total);
                            }
                        }
                    }
                    curr[colA][colB] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};

int main(){
    vector<vector<int>> grid = {{4,1,2},{3,6,1},{1,6,6},{3,1,2}};
    Solution obj;
    cout << obj.maxChocolate(grid);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N * M * M * 9)
Space Complexity: O(M * M)
    only 2D DP's are used not 3D DP
==================================================
*/
