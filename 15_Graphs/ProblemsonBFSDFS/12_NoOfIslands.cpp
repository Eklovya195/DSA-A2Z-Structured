/*
Problem:  200. Number of Islands
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/number-of-islands/description/"
==================================================
Input:
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
Explanation:
    ● Top-left block of 1s → Island 1
    ● Single 1 in middle → Island 2
    ● Bottom-right connected 1s → Island 3
Output: 3
==================================================
*/

/*
Algorithm:
    An island is a connected component of land cells ('1') considering 8-directional connectivity.
    We use Breadth First Search (BFS).
    1. Create a visited matrix to mark visited cells.
    2. Traverse the entire grid.
    3. Whenever an unvisited land cell ('1') is found:
        ○ Increment island count.
        ○ Start BFS from that cell.
    4. BFS will:
        ○ Visit all land cells connected in 8 directions.
        ○ Mark them as visited.
    5. Continue scanning the grid.
    6. The number of BFS calls equals the number of islands.

    this code consider all 8 diretections but leetcode question consist only 4 directions
    ↖  ↑  ↗
    ←  X  →
    ↙  ↓  ↘

    4-directions
        ↑
    ←   X   →
        ↓
*/

/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        //create queue
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traversing through the neighbour
            //considering all 8 directions 
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow = row+delrow;
                    int ncol = col+delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});

                    }
                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //n->rows && m->col
        int n = grid.size();
        int m = grid[0].size();

        //create 2d matrix of visited
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
    };
    Solution obj;
    cout << obj.numIslands(grid);
    return 0;
}
*/

//Leetcode soln
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        //create queue
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // considering only four directions for leetcode soln 
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});

                }
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //n->rows && m->col
        int n = grid.size();
        int m = grid[0].size();

        //create 2d matrix of visited
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;

        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row,col,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
    };
    Solution obj;
    cout << obj.numIslands(grid);
    return 0;
}

/*
==================================================
Time Complexity: O(N × M)
    Reason: Every cell is visited at most once.
Space Complexity: O(N × M)
    Reason: Visited matrix and BFS queue in the worst case
==================================================
*/

