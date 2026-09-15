/*
Problem:  1020. No of Enclave
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/number-of-enclaves/description/"
==================================================
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
==================================================
*/

/*
Algorithm:
    The key observation is:
        Any land cell connected to the boundary cannot be an enclave
    Steps:
    1. Create a visited matrix to track visited land cells.
    2. Traverse all boundary cells:
        ○ If a boundary cell is land (1), mark it visited and push it into a queue.
    3. Perform BFS from these boundary land cells:
        ○ Move in 4 directions
        ○ Mark all reachable land cells as visited
    4. After BFS:
        ○ Traverse the grid
        ○ Count land cells (1) that are not visited
    5. Return the count
    Unvisited land cells are exactly the enclaves.
*/

/*
#include<bits/stdc++.h>
using namespace std;

//Using BFS Approach 
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        //traverse through all corner and find corner 1's
        //and push them in the queue
        //visit first and last row
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                vis[0][j] = 1;
                q.push({0,j});
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                vis[n-1][j] = 1;
                q.push({n-1,j});
            }
        }

        //visit first and last col
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                vis[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                vis[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                   }
            }
        }

        //last check if there is any 1 left 
        // which is not directly connected to corner one
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    vector<vector<int>> grid = {
                {0,1,1,0},
                {0,0,1,0},
                {0,0,1,0},
                {0,0,0,0}
    };
    Solution obj;
    cout << obj.numEnclaves(grid);
    return 0;
}
*/

//Approach 2: Using DFS Approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        vector<vector<int>> vis(n,vector<int>(m,0));

        //traverse through all corner and find corner 1's
        //and push them in the queue
        //visit first and last row
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0,j,grid,vis,drow,dcol);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis,drow,dcol);
            }
        }

        //visit first and last col
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i,0,grid,vis,drow,dcol);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis,drow,dcol);
            }
        }

        //last check if there is any 1 left 
        // which is not directly connected to corner one
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }

    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis,int drow[],int dcol[]){
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
               grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    dfs(nrow,ncol,grid,vis,drow,dcol);
            }
        }
    }
};

int main(){
    vector<vector<int>> grid = {
                {0,1,1,0},
                {0,0,1,0},
                {0,0,1,0},
                {0,0,0,0}
    };
    Solution obj;
    cout << obj.numEnclaves(grid);
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