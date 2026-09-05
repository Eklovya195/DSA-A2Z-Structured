/*
Problem:  Undirected Graph Cycle Detection using DFS
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670"
==================================================
Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes
==================================================
*/

/*
Algorithm:
    1. Create a visited array to mark visited vertices.
    2. Since the graph can have multiple connected components, iterate over all vertices.
    3. For every unvisited vertex:
        ○ Start a DFS with its parent as -1.
    4. In DFS:
        ○ Mark the current node as visited.
        ○ Traverse all its adjacent nodes.
        ○ If an adjacent node is not visited, recursively call DFS with current node as parent.
        ○ If an adjacent node is already visited and is not the parent, a cycle exists.
    5. If DFS finishes without detecting such a case, no cycle exists.
    6. If any DFS call detects a cycle, return true. Otherwise, return false.
*/

#include<bits/stdc++.h>
using namespace std;

bool isdetected(int node,vector<vector<int>> &adj,vector<int> &vis,int parent){
    vis[node] = 1;

    for(auto adjacentNode:adj[node]){
        if(!vis[adjacentNode]){
            if(isdetected(adjacentNode,adj,vis,node)){
                return true;
            }
        }else if(parent!=adjacentNode){
                return true;
        }
    }
    return false;
}

bool iscycle(vector<vector<int>> &adj,int V){
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){  //if multiple connected componenets
            if(isdetected(i,adj,vis,-1)) return true;
        }
    }
    return false;
}

int main(){
    int V,E;
    cin >> V >> E;

    //create adjacency list
    vector<vector<int>> adj(V);

    //made graph by adding edges
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = iscycle(adj,V);
    cout << boolalpha << ans;

    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
    Reason: Each vertex is visited once and each edge is explored during DFS.
Space Complexity: O(V + E)
    Reason: Space used for adjacency list, visited array, and recursion stack.
==================================================
*/