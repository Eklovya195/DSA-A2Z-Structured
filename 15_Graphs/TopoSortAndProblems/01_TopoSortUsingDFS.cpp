/*
Problem:  Topo Sort Problem
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/topological-sort/1"
==================================================
Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
==================================================
*/

/*
Algorithm:
    Topological sorting using DFS works on the idea of finishing times.
    1. Create a visited array of size V, initialized to 0.
    2. Create a stack to store nodes.
    3. For every vertex:
        ○ If it is not visited, call DFS on it.
    4. In DFS:
        ○ Mark the current node as visited.
        ○ For every adjacent node:
       ■ If not visited, call DFS recursively.
        ○ After visiting all adjacent nodes, push the current node into the stack.
    5. After DFS is done for all vertices:
        ○ Pop elements from the stack to get the topological order.
    Pushing a node after exploring all its dependencies ensures correct ordering.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //create adjacency list
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        //create visited array
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        //answer array
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st){
        vis[node] = 1;
        // Visit all neighbours
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis,st);
            }
        }
        // Add node after all its neighbours are processed
        st.push(node);
    }
};

int main(){
    vector<vector<int>> edges = {{3,0},{1,0},{2,0}};
    int V = 4;
    Solution obj;
    vector<int> ans = obj.topoSort(V,edges);
    for(int i=0;i<V;i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
Reason: Each vertex and each edge is visited exactly once during DFS.
Space Complexity: O(V + E)
Reason: Adjacency list, visited array, recursion stack, and result stack.
==================================================
*/