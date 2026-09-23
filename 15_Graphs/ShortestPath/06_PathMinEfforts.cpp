/*
Problem:  1631.Path with Minimum Efforts
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/path-with-minimum-effort/description/"
==================================================
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
==================================================
*/


/*
Algorithm:
    This problem is solved using Dijkstra’s algorithm because we want to minimize the maximum edge cost along a path.
    1. Use a priority queue that stores {effort, {row, col}}.
    2. Create a distance matrix and initialize all values with a large number.
    3. Set distance of source cell (0,0) as 0 and push it into the priority queue.
    4. While the priority queue is not empty:
        ○ Pop the cell with the minimum effort.
        ○ If the destination cell is reached, return the effort.
        ○ For all 4 directions:
            ■ Check if the new cell is inside the grid.
            ■ Compute new effort as max(current effort, absolute height difference)
            ■ If this effort is smaller than the stored value, update it and push into the queue.
    5. If destination is not reached, return 0.
    This works because the priority queue always processes the path with the least current effort first.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        //create a dist matrix
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        //create a priority queue
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> >,
        greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int pathdiff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Ignore stale entry
            if (pathdiff > dist[row][col]) continue;
            if(row==n-1 && col == m-1) return pathdiff;

            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newdiff = abs(heights[nrow][ncol]-heights[row][col]);
                    int newEfforts = max(newdiff,pathdiff);
                    if(newEfforts<dist[nrow][ncol]){
                        dist[nrow][ncol] = newEfforts;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return 0; //unreachable
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2}, {3,8,2}, {5,3,5}};
    Solution obj;
    cout << obj.minimumEffortPath(heights);
    return 0;
}



/*
==================================================
Time Complexity: O(N * M * log(N * M))
    Each cell can be inserted into the priority queue, and each insertion or deletion takes log(N*M) time.
Space Complexity: O(N * M)
    Used for the distance matrix and the priority queue in the worst case.
==================================================
*/