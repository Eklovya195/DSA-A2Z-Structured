/*
Problem:  994. Rotten Orages
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/rotting-oranges/description/"
==================================================
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
==================================================
*/

/*
Algorithm:
    The problem is solved using Breadth First Search (BFS) because rotting happens level by level (minute by minute).
    1. Create a queue to store positions of all initially rotten oranges.
    2. Traverse the grid:
        ○ Count total number of oranges (tot) (fresh + rotten).
        ○ Push all rotten oranges into the queue.
    3. Maintain:
        ○ cnt → number of oranges that become rotten during BFS
        ○ days → total minutes taken
    4. Perform BFS:
        ○ For each level (one minute), process all currently rotten oranges.
        ○ For every rotten orange, check its 4 directions.
        ○ If a fresh orange is found, mark it rotten and push it into the queue.
        ○ Increase the rotten count.
    5. After processing one level, if the queue is not empty, increment days.
    6. After BFS ends:
        ○ If cnt == tot, return days
        ○ Otherwise, return -1 (some fresh oranges are unreachable)

    Note:- here in this only we had not maintain the cnt of fresh oranges and 
    we are just checking at the end that if there is any unrotten left in matrix so -1 
    else return tm
*/

#include<bits/stdc++.h>
using namespace std;

//using bfs beacuse we need to traverse levelwise
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //n->row && m->col
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        //traverse through grid and find all rotten oranges and add them
        //in queue and visited matrix
        for(int row = 0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col] == 2){
                    q.push({{row,col},0});
                    vis[row][col] = 2;
                }else{
                    vis[row][col] = 0;
                }
            }
        }

        //change all neighbour(4-directions only not 8) unrotten into rotten
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm,t);
            q.pop();
            //create all neighbour nodes in 4 directions
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                //check if vis == 0 && grid == 1
                if(nrow>=0 && nrow<n && 
                    ncol>=0 && ncol<m && 
                    vis[nrow][ncol] == 0 && 
                    grid[nrow][ncol] == 1){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol] = 2;
                }
            }
        }

        //check if all unrotten changes into rotten or not
        for(int row = 0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col] != 2 && grid[row][col]==1){
                    return -1;
                }
            }
        }
     return tm;   
    }
};
      

int main() {
    vector<vector<int>> grid = {
    {2,1,1},
    {0,1,1},
    {1,0,1}
    };
    Solution obj;
    int ans = obj.orangesRotting(grid);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(n × m × 4) 
    In the worst case, every cell in the grid may contain an orange, 
    and for each rotten orange we explore 4 directions (up, down, left, right). 
    So we iterate through all cells (n × m) and perform 4 operations per orange. 
    Hence, the complexity becomes O(n × m × 4), which simplifies to O(n²).
Space Complexity: O(n × m) 
    In the worst case, all the oranges might be rotten and 
    will be stored in the queue simultaneously. 
    The maximum size of the queue can be equal to the total number of oranges in the grid, 
    i.e., n × m. Therefore, the space complexity is O(n²).
==================================================
*/