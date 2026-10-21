/*
Problem:  51. N-Queens
Platform: Recursion / Striver A2Z
Difficulty: Hard
Problem Link: "https://leetcode.com/problems/n-queens/description/?utm=codolio"
==================================================
Problem Explanation
You are given an integer n, representing an n × n chessboard.
Your task is to place n queens on the board such that:
1. No two queens attack each other.
2. A queen can attack another queen if they are:
○ In the same row
○ In the same column
○ On the same diagonal
You must return all distinct valid board configurations.
Each configuration is represented as:
● 'Q' → Queen placed
● '.' → Empty cell


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
==================================================
*/

/*
Approach 1: Most Brute Force / Basic Backtracking
Idea
We place queens column by column.
For each column:
    ● Try placing a queen in every col
    ● Before placing, check if it is safe
    ● If safe → place queen and move to next row as level
    ● If not → try next col
    ● If no col works → backtrack

Safety Check (Important)
To check if a queen can be placed at (row, col):
    1. Check same col on upper side
    2. Check upper-left diagonal
    3. Check upper-right diagonal
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //My approach of checking which i sso brute that it takes O(N^2)
    bool check(int row,int col,vector<string> &board,int n){
        //iterate through all upper rows
        for(int i=0;i<row;i++){
            int prow = i;
            int pcol = -1;
            //finding col of previous placed queen
            for(int j=0;j<n;j++){
                if(board[i][j] == 'Q'){
                    pcol = j;
                    break;
                }
            }

            //check if it attacked by previous column or diagonal column
            if(pcol == col || abs(pcol-col)==abs(prow-row)){
                return false;
            }
        }
        return true;
    }
    void funGenerate(int level,int n,vector<string> &board,vector<vector<string>> &ans){
        //base case
        if(level == n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(check(level,col,board,n)){
                //placing queen
                board[level][col] = 'Q'; 
                //moving to next row
                funGenerate(level+1,n,board,ans);
                //backtracking
                board[level][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        //create a board of n*n size
        //fill whole board with '.'
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        //here starting 0 means row 0
        //row are considered here as level
        funGenerate(0,n,board,ans);   
        return ans;
    }
};

int main(){
    int n = 4;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for(const auto& row:ans){
        cout << "[";
        for(string ans:row){
            cout << ans << ",";
        }
        cout << "]\n";
    }
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N! × N^2)
    N! because first row has N choice -> N-1 choice -> N-2 choice ....
    (Trying all permutations + safety checks)
Space Complexity: O(N²)
    (Board + recursion stack)
==================================================
*/

//Better Approach where checking is done in O(N) times
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //This changes checking time from O(N^2) to O(N)
    bool check(int row,int col,vector<string> &board,int n){
        //check upper col
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //check upper left diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //check upper right diagonals
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void funGenerate(int level,int n,vector<string> &board,vector<vector<string>> &ans){
        //base case
        if(level == n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(check(level,col,board,n)){
                //placing queen
                board[level][col] = 'Q'; 
                //moving to next row
                funGenerate(level+1,n,board,ans);
                //backtracking
                board[level][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        //create a board of n*n size
        //fill whole board with '.'
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        //here starting 0 means row 0
        //row are considered here as level
        funGenerate(0,n,board,ans);   
        return ans;
    }
};

int main(){
    int n = 4;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for(const auto& row:ans){
        cout << "[";
        for(string ans:row){
            cout << ans << ",";
        }
        cout << "]\n";
    }
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N! × N)
    N! because first row has N choice -> N-1 choice -> N-2 choice ....
    (Trying all permutations + safety checks)
Space Complexity: O(N²)
    (Board + recursion stack)
==================================================
*/

//Optimal Approach
/*
Optimal Approach (Using Hashing for Fast Safety Check)
Instead of checking the entire board every time, we use 3 helper arrays:
1. upperCol[col] → checks if a col already has a queen
2. leftDiagonal[level-col+n-1] → checks \ diagonal
3. rightDiagonal[col + row] → checks / diagonal
This allows O(1) safety checks.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(int level,int n,vector<string> &board,vector<vector<string>> &ans,vector<bool> &upperCol,
        vector<bool> &leftDiagonal,vector<bool> &rightDiagonal){
        //base case
        if(level == n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(!upperCol[col] && !leftDiagonal[level-col+n-1] && !rightDiagonal[level+col]){
                // Place Queen & Hash the paths
                board[level][col] = 'Q';
                upperCol[col] = true;
                leftDiagonal[level-col+n-1] = true;
                rightDiagonal[level+col] = true;

                //move to next row
                funGenerate(level+1,n,board,ans,upperCol,leftDiagonal,rightDiagonal);

                //Backtracking:Remove Queen and unhase the paths
                board[level][col] = '.';
                upperCol[col] = false;
                leftDiagonal[level-col+n-1] = false;
                rightDiagonal[level+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        //create a board of n*n size
        //fill whole board with '.'
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        //three vector used for hashing
        vector<bool> upperCol(n,false);
        vector<bool> leftDiagonal(2*n-1,false);
        vector<bool> rightDiagonal(2*n-1,false);
        //here starting 0 means row 0
        //row are considered here as level
        funGenerate(0,n,board,ans,upperCol,leftDiagonal,rightDiagonal);   
        return ans;
    }
};

int main(){
    int n = 4;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for(const auto& row:ans){
        cout << "[";
        for(string ans:row){
            cout << ans << ",";
        }
        cout << "]\n";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N!)
    N! because first row has N choice -> N-1 choice -> N-2 choice ....
    (Trying all permutations)
Space Complexity: O(N)
    (helper array + recursion stack)
==================================================
*/