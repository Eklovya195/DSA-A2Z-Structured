/*
Problem: Bellman Ford Algorithm
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm=codolio"
==================================================
Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 -> 1
For 0 to 2 minimum distance will be 6. By following path 0 -> 1 -> 2
For 0 to 3 minimum distance will be 6. By following path 0 -> 1 -> 2 -> 4 -> 3 
For 0 to 4 minimum distance will be 7. By following path 0 -> 1 -> 2 -> 4
==================================================
*/

/*
Bellman Ford Works on directed Edges if undirected graph is given then create directed edge between both vertices 
and then implement Bellman Ford Algo
Problem Statement: 
    You are given a directed weighted graph with V vertices and a list of edges. Each edge is of
    the form [u, v, w], meaning there is a directed edge from u to v with weight w.
    You are also given a source vertex S.
    Your task is to find the shortest distance from the source S to all other vertices.
    If the graph contains a negative weight cycle, return an array containing only -1
*/

/*
Algorithm:
    Bellman-Ford algorithm is used to find shortest paths from a single source even when negative edge weights are present.
    1. Create a distance array dist of size V.
    2. Initialize all distances as infinity except the source S, which is set to 0.
    3. Repeat the following process V-1 times:
        ○ For every edge (u, v, wt):
            ■ If dist[u] is not infinity and dist[u] + wt < dist[v], update dist[v].
    4. After V-1 relaxations, perform one more iteration over all edges: //this is done to detect neagtive cycle
        ○ If any distance can still be reduced, a negative cycle exists.
        ○ In that case, return {-1}.
    5. If no negative cycle is found, return the distance array.
    
    Why V-1 times?
        The shortest path between two vertices can have at most V-1 edges. More relaxations are only needed to detect negative cycles
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
        //Nth relaxation to check neagtive cycle
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

int main(){
    int V = 5;
    int src = 0;
    vector<vector<int>> edges = {{1, 3, 2},{4, 3, -1},{2, 4, 1},{1, 2, 1},{0, 1, 5}};
    Solution obj;
    vector<int> ans = obj.bellmanFord(V,edges,src);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}


/*
==================================================
Time Complexity: O(VE), V = no of vertices
                        E = no of edges
Space Complexity: O(V) as we are using dist vector of V size.
==================================================
*/