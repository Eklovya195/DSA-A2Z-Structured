/*
Problem:  733. Flood Fill
Platform: Graph / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/flood-fill/description/"
==================================================
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
==================================================
*/

/*
Algorithm:
    
*/


//BFS Approach
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        //create queue
        queue<pair<int,int>> q;

        //create visited matrix and assigned its value same as image matrix
        vector<vector<int>> vis = image;

        int scolor = image[sr][sc];

        //if scolor == color return image
        if(scolor == color) return image;

        //initial shell
        q.push({sr,sc});
        vis[sr][sc] = color;

        //create all neighbour nodes in 4 directions
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == scolor){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = color;
                   }
            }
        }
        return vis;
    }
};
      

int main() {
    vector<vector<int>> image = {
    {0,0,0},
    {0,0,0}
    };
    int sr = 0;
    int sc = 0;
    int color = 0;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image,sr,sc,color);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    return 0;
}
*/

/*
==================================================
Time: O(n × m) — each cell is processed at most once.
Space: O(n × m) — queue + vis matrix.
    if you want also store answer in given image and not need of new vis matrix
==================================================
*/

/*
Algorithm:
    1. Store the initial color of the starting pixel (sr, sc).
    2. Create a copy of the image so the original image is not modified directly.
    3. Use DFS traversal starting from (sr, sc).
    4. At each pixel:
        ○ Change its color to newColor.
        ○ Explore its 4 neighbors (up, right, down, left).
    5. For each neighbor:
        ○ Check if it is inside the grid.
        ○ Check if it has the same initial color.
        ○ Check if it is not already colored with newColor.
    6. Recursively apply DFS on valid neighbors.
    7. Continue until all connected p
*/

//DFS Approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>> &vis,int color,int drow[],int dcol[],int scolor){
        vis[row][col] = color;

        //size of row and col of image
        int n = image.size();
        int m = image[0].size();

        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];

           if(nrow >= 0 && nrow < n &&
              ncol >= 0 && ncol < m &&
              vis[nrow][ncol] == scolor){
                    dfs(nrow,ncol,image,vis,color,drow,dcol,scolor);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //create visited matrix and assigned its value same as image matrix
        vector<vector<int>> vis = image;

        int scolor = image[sr][sc];

        //if scolor == color return image
        if(scolor == color) return image;

        //create all neighbour nodes in 4 directions
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(sr,sc,image,vis,color,drow,dcol,scolor);
        return vis;
    }
};
      

int main() {
    vector<vector<int>> image = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
    };
    int sr = 1;
    int sc = 1;
    int color = 2;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image,sr,sc,color);
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
Time: O(n × m) — each cell is processed at most once.
Space: O(n × m) — queue + vis matrix.
    if you want also store answer in given image and not need of new vis matrix
==================================================
*/