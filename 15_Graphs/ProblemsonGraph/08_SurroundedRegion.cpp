/*
Problem:  130. Surrounded Region
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/surrounded-regions/description/"
==================================================
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
==================================================
*/

/*
Approach:
    1. Any 'O' connected to a boundary 'O' cannot be surrounded.
    2. So, start DFS from every boundary 'O' and mark all connected 'O' cells as visited.
    3. After that, traverse the entire board.
    4. If an 'O' is not visited, it is surrounded, so change it to 'X'.
*/

#include<bits/stdc++.h>
using namespace std;

//using bfs 
class Solution {
public:
    vector<vector<char>> solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        vector<vector<int>> vis(n,vector(m,0));

        //visit first and last row
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0,j,board,vis,delrow,delcol);
            }
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1,j,board,vis,delrow,delcol);
            }
        }

        //visit first and last col
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,board,vis,delrow,delcol);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,delrow,delcol);
            }
        }

        // replace surrounded O's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
            }
        }
        return board;
    }

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis,int delrow[],int delcol[]){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int k = 0; k < 4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                    dfs(nrow, ncol, board, vis, delrow, delcol);
            }
        }
    }
};

int main(){
    vector<vector<char>> board = {
                {'X','X','X','X'},
                {'X','O','X','X'},
                {'X','O','O','X'},
                {'X','O','X','X'},
                {'X','X','O','O'}
    };
    Solution obj;
    vector<vector<char>> ans = obj.solve(board);
    for(auto i : ans) {
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N × M)
    Reason: Each cell is visited once and each visit checks 4 neighbors.
Space Complexity: O(N × M)
    Reason: Space used for visited matrix.
==================================================
*/