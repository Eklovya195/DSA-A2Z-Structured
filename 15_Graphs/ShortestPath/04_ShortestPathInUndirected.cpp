/*
Problem:  Shortest Path in UnDirected Weighted Graph 
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1"
==================================================
Input: V = 5, edges[][] = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]], src = 1, dest = 5
Output: [1, 4, 3, 5]
Explanation: The shortest path from vertex 1 to vertex 5 is 1 -> 4 -> 3 -> 5 with a total weight of 5.
==================================================
*/

//Use Dijkstra Algorithm
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        //create adj list of V+1 because it is 1 indexed 
        vector<vector<pair<int,int>>> adj(V+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        //create a priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //create a dist vector
        vector<int> dist(V+1,1e9);
        //create a parent vector
        vector<int> parent(V+1);

        //inititlaise parent vector array
        for(int i=1;i<=V;i++){
            parent[i] = i;
        }

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeweight = it.second;
                if(dis+edgeweight<dist[adjNode]){
                    dist[adjNode] = dis+edgeweight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        //if destination is unrechable
        if(dist[dest] == 1e9) return {-1};
        vector<int> path;
        int node = dest;
        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(),path.end());
        return path;
    }
};

int main(){
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int src = 1;
    int dest = 5;
    int V = 5;
    Solution obj;
    vector<int> ans =  obj.shortestPath(V,edges,src,dest);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}


/*
==================================================
Time Complexity: O(ElogV)
Space Complexity: O(V+E)
==================================================
*/

