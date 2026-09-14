/*
Problem:  Shortest Path in Directed Acyclic Graph
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1"
==================================================
Input: V = 4, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
==================================================
*/

/*
Why Topological Sort Works Here?
    ● The graph is a DAG → no cycles
    ● In a DAG, topological order guarantees that when we process a node,all nodes that can reach it have already been processed.
    ● This allows us to relax edges only once, unlike Dijkstra.
    👉 Dijkstra is required only when cycles may exist.
Approach:
    If we already know the shortest distances to all nodes that come before a node in topological
    order, we can easily compute the shortest distance for the current node.
*/

/*
Algorithm:
    Build adjacency list
    Store graph as:
    adj[u] = { (v, weight) }
    1. Topological Sort using DFS
        ○ Maintain a visited[] array
        ○ Push nodes into a stack after DFS completion
    2.Initialize distance array
        dist[i] = INF
        dist[0] = 0
    3. Process nodes in topological order
        ○ Pop nodes from stack
        For each edge u → v (wt):
        if dist[u] + wt < dist[v]
            dist[v] = dist[u] + wt
    4. Convert unreachable nodes
        ○ Replace INF with -1

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        //create adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        //create visited array
        vector<int> vis(V,0);
        stack<int> st;
        
        //step1:do a topo sort on the graph
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }

        //step2:do the distance things
        vector<int> dist(V,1e9);
        dist[0] = 0; //make source node distance as 0
        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it:adj[node]){
                //v is adj node and wt is weight of edge
                int v = it.first;
                int wt = it.second;

                if(dist[node]+wt<dist[v]){
                    dist[v] = dist[node]+wt;
                }
            }
        }
        // Convert unreachable nodes to -1
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }

    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int> &vis,stack<int> &st){
        vis[node] = 1;
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                dfs(v,adj,vis,st);
            }
        }
        //add node into stack after all of its neighbour travelled
        st.push(node);
    }
};


int main(){
    vector<vector<int>> edges = {{0,1,2}, {0,4,1}, {4,5,4}, {4,2,2}, {1,2,3}, {2,3,6}, {5,3,1}};
    int V = 6;
    Solution obj;
    vector<int> ans = obj.shortestPath(V,edges);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity:O(N + M)
    Topological sort → O(N + M)
    Edge relaxation → O(N + M)
Space Complexity:O(N + M)
    Adjacency list
    Stack for topo sort
    Distance & visited arrays
==================================================
*/