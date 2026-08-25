/*
Problem:  Depth First Search
problem Statement:Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, 
    visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.
    Note: Do traverse in the same order as they are in the given adjacency list
Platform: Graph / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1"
==================================================
Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
==================================================
*/

/*
Algorithm:
    1. Use a visited array to keep track of visited nodes.
    2. Start DFS from a given node.
    3. Mark the current node as visited and store it in the result vector.
    4. Traverse all adjacent nodes of the current node using the adjacency list.
    5. For each adjacent node that is not visited:
        ○ Recursively apply DFS on that node.
    6. When a node has no unvisited neighbors, backtrack to the previous node.
    7. Repeat until all reachable nodes are visited.
DFS uses recursion and backtracking to explore the graph fully.
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    //traverse all neighbour
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int> dfsofGraph(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        int start = 0;

        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
}

int main(){
    //No of edges and vertices
    int n,m;
    cin >> n >> m;

    //graph here
    vector<vector<int>> adj(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    //printing of graph
    vector<int> result = dfsofGraph(adj);
    cout << "DFS Traversal: ";
    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N) + O(2*E) //for undirected graph
                 O(N) + O(E) //for directed graph
Space Complexity: O(3*N) = O(N)
==================================================
*/