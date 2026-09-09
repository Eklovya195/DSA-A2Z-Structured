/*
Problem:  542. 01 Matrix
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/01-matrix/"
==================================================
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
==================================================
*/

/*
Algorithm:
    We use Breadth First Search (BFS) because BFS naturally expands level by level, which directly represents distance.
    1. Create:
        ○ visited matrix to mark visited cells
        ○ dist matrix to store distance of nearest 1
        ○ Queue to store ((row, col), steps)
    2. Traverse the grid:
        ○ If a cell contains 0, push it into the queue with distance 0
        ○ Mark it as visited
    3. Start BFS:
        ○ Pop a cell from the queue
        ○ Store its distance in the dist matrix
        ○ Explore its 4 neighbors
    4. For every valid, unvisited neighbor:
        ○ Mark it visited
        ○ Push it into the queue with dist + 1
    5. Continue until the queue becomes empty.
    6. Return the distance matrix.
    All 1 cells act as multiple BFS sources, ensuring the shortest distance is found
*/

#include<bits/stdc++.h>
using namespace std;

//using bfs 
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        //mark visited for all having value as 0 intially
        //push them in the queue 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        //BFS Starts from here 
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            dis[row][col] = dist;

            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   vis[nrow][ncol]== 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                   }
            }
        }
        return dis;
    }
};

int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    Solution obj;
    vector<vector<int>> ans = obj.updateMatrix(mat);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }

    return 0;
}

/*
==================================================
Time Complexity: O(N × M)
    Reason: Each cell is visited once and each visit checks 4 neighbors.
Space Complexity: O(N × M)
    Reason: Space used for visited matrix, distance matrix, and queue.
==================================================
*/