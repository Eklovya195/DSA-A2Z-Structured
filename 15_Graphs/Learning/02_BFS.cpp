/*
Problem:  Breadth First Search
problem Statement:Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], 
    where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.
    Note: Do traverse in the same order as they are in the given adjacency list.
Platform: Graph / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1"
==================================================
Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
Output: [0, 2, 3, 1, 4]
    Explanation: Starting from 0, the BFS traversal will follow these steps: 
    Visit 0 → Output: 0 
    Visit 2 (first neighbor of 0) → Output: 0, 2 
    Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
    Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 1
    Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
==================================================
*/

/*
Algorithm:
1. Create a visited array of size V and initialize all values to 0.
2. Create a queue data structure.
3. Mark the starting node 0 as visited and push it into the queue.
4. While the queue is not empty:
    ○ Take the front element of the queue and remove it.
    ○ Add this node to the BFS result vector.
    ○ Traverse all adjacent nodes of this node.
    ○ If an adjacent node is not visited:
        ■ Mark it as visited.
        ■ Push it into the queue.
5. Continue until the queue becomes empty.
6. Return the BFS traversal vector.
This ensures nodes are visited in breadthwise (level order) manner.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
        //no of vertices
        int V = adj.size();
        int vis[V] = {0};
        //putting 0 vertex 0 as 1 because graph is 0 indexed
        vis[0] = 1;
        queue<int> q;
        //pushing 0 index in queue
        q.push(0);
        
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector<int> result = bfs(adj);
    cout << "BFS Traversal: ";
    for (auto it : result) {
        cout << it << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N) + O(2*E)  //for undirected graph
                 O(N) + O(E)    //for directed graph
Space Complexity: O(3*N) = O(N)
==================================================
*/