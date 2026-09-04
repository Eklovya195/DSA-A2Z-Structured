/*
Problem:  Connected Components in Undirected Graph
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1"
==================================================
Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
==================================================
*/

/*
Algorithm:
    To count connected components, we need to make sure every vertex is visited exactly once and grouped correctly.
    1. Build an adjacency list from the given edge list.
    2. Create a visited array of size V and initialize all values to 0.
    3. Initialize a counter components = 0.
    4. Loop through all vertices from 0 to V-1:
        ○ If a vertex is not visited:
            ■ This means we found a new connected component.
            ■ create component vector
            ■ Perform DFS starting from this vertex.
            ■ During DFS, mark all reachable vertices as visited and put that vertex into component vector.
    5. After all vertices are processed, return the component vector.
    Each DFS traversal covers exactly one connected component
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        //no of edges
        int E = edges.size();
        vector<int> adj[V];
        //changing edges into adj list
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int> component;
                dfs(i,adj,vis,component);
                ans.push_back(component);
            }
        }
        return ans;
    }
    
    void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &component){
        vis[node] = 1;
        component.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,component);
            }
        }
    }
};

int main() {
    vector<vector<int>> edges = {
    {0,1},
    {2,1},
    {3,4}
    };
    int V = 5;
    Solution obj;
    vector<vector<int>> ans = obj.getComponents(V,edges);
    for(int i = 0; i < ans.size(); i++){
        cout << "[ ";        
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }        
        cout << "]\n";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(V+E)
Space Complexity: O(V+E)
==================================================
*/