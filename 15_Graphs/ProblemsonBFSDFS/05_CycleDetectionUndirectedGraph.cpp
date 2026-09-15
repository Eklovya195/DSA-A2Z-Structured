/*
Problem:  Undirected Graph Cycle
problem Statement:Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], 
    where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1"
==================================================
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
==================================================
*/

/*
Algorithm:
    We use Breadth First Search (BFS) with parent tracking.
    1. Create a visited array of size V and initialize all values to 0.
    2. Since the graph can have multiple connected components, loop through all vertices.
    3. For every unvisited vertex, start a BFS:
        ○ Push a pair (node, parent) into the queue.
        ○ Mark the node as visited.
    4. While the queue is not empty:
        ○ Pop the front element (node, parent).
        ○ Traverse all adjacent nodes of node.
        ○ If an adjacent node is not visited:
        ■ Mark it visited.
        ■ Push (adjacentNode, node) into the queue.
            ○ Else if the adjacent node is visited and it is not the parent:
        ■ A cycle is detected, return true.
    5. If BFS finishes for all components and no cycle is found, return false
*/

#include<bits/stdc++.h>
using namespace std;

bool isdetected(int src,vector<vector<int>> &adj,vector<int> &vis){
    vis[src] = 1;

    //create qeueue
    queue<pair<int,int>> q;

    //push first node in queue
    q.push({src,-1});

    while(!q.empty()){
        //take node and its parent and pop out
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode] = 1;
                q.push({adjacentNode,node});
            }
            else if(parent != adjacentNode){
                return true;
            }
        }
    }
    return false;
}

bool iscycle(vector<vector<int>> &adj,int V){
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){  //if multiple connected componenets
            if(isdetected(i,adj,vis)) return true;
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
Time Complexity: O(N + 2E) + O(N)
    Reason: BFS traverses all nodes and edges, and an extra loop handles disconnected components.
Space Complexity: O(N)
    Reason: Space used by visited array and queue.
==================================================
*/