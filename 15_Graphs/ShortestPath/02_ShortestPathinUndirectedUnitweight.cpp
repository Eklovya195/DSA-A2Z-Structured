/*
Problem:  Shortest Path in UnDirected Graph with unit weight
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1"
==================================================
Input: V = 9, edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0, dest = 8
Output: 4
Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.
==================================================
*/

/*
Approach:
    Why BFS?
        ● The graph is undirected
        ● All edges have unit weight (1)
        ● Breadth First Search (BFS) always explores nodes level by level
        → guarantees the shortest path in terms of edges
        So BFS is optimal here (no need for Dijkstra).

Algorithm:
    1. Convert edge list into an adjacency list
    2. Create a dist[] array initialized with a large value (1e9)
    3. Set dist[src] = 0
    4. Push src into a queue
    5. Perform BFS:
        ○ For each popped node, explore its neighbors
        ○ If dist[node] + 1 < dist[neighbor]
            ■ Update distance
            ■ Push neighbor into queue
    6. After BFS:
        ○ If distance is still 1e9, mark it as -1

*/

//This solved the question with all edge weight as 1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        //create adj list
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //create a queue
        queue<int> q;
        q.push(src);

        //create a dist array
        vector<int> dist(V,1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it] = dist[node]+1;
                    q.push(it);
                }
            }
        }

        //if any node is unreachable
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist[dest];
    }
};


int main(){
    vector<vector<int>> edges = {{0,1}, {0,3}, {1,2}, {3,4}, {4,5}, {2,6},{5,6},{6,7},{6,8},{7,8}};
    int src = 0;
    int dest = 8;
    int V = 9;
    Solution obj;
    cout << obj.shortestPath(V,edges,src,dest);
    return 0;
}


/*
==================================================
Time Complexity:O(N + M)
    BFS visits every node once → O(N)
    Traverses every edge once → O(M)
Space Complexity:O(N + M)
    Adjacency list
    Distance array
    BFS queue
==================================================
*/

