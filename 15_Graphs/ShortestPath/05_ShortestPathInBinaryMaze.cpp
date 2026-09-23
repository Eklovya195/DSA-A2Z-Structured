/*
Problem:  1091. Shortest Path in Binary Maze
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/shortest-path-in-binary-matrix/description/"
==================================================
Input: grid = [[0,1],[1,0]]
Output: 2
==================================================
*/


/*
Algorithm:
    We use Breadth First Search because each move has equal cost and BFS always gives the shortest path.
    1. If source and destination are the same and its value is 0, return 1.
    2. If either source(0,0) or destination(n-1,n-1) is not 0, return -1.
    3. Create a queue using tuple that stores {distance, row, col}.
    4. Create a distance matrix and initialize all values to a very large number.
    5. Set the source distance as 0 and push it into the queue.
    6. Define direction arrays for all 8 directions.
    7. While the queue is not empty:
        ○ Pop the front element.
        ○ For each of the 8 directions:
            ■ Check boundary conditions.
            ■ Check if the cell value is 0.
            ■ Check if the new distance is smaller than the stored distance.
            ■ Update distance and push the cell into the queue.
            ■ If destination(n-1,n-1) is reached, return the distance.
    8. If BFS ends and destination is not reached, return -1
*/


//Uisng Queue
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //if only one element is present
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0] != 0 || grid[n-1][n-1]!=0) return -1;
        //create a distance matrix of grid size
        vector<vector<int>> dis(n,vector<int>(n,1e9));

        //create a queue and push first element 
        queue<tuple<int,int,int>> q;
        //{dist,row,col}
        q.push({0,0,0});

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto curr = q.front();
            int dist = get<0>(curr);
            int row = get<1>(curr);
            int col = get<2>(curr);
            q.pop();

            for(int i=0;i<8;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n
                  && grid[nrow][ncol]== 0 && dist+1<dis[nrow][ncol]){
                    dis[nrow][ncol] = dist+1;
                    if(nrow == n-1 && ncol == n-1) return dis[nrow][ncol]+1;
                    q.push({dist+1,nrow,ncol});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,0}, {1, 1, 0}, {1, 1, 0}};
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid);
    return 0;
}



/*
==================================================
Time Complexity: O(N × M)
    Each cell is visited at most once, and for every cell we check 8 directions.
Space Complexity: O(N × M)
    Distance matrix and queue together take space proportional to the number of cells.
==================================================
*/