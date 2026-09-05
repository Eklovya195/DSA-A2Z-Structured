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
    This approach is based on in-degrees of vertices.
    1. Create an indegree array of size V, initialized to 0.
    2. For every edge u → v, increment indegree[v].
    3. Push all vertices with indegree = 0 into a queue.
    4. While the queue is not empty:
        ○ Pop a node and add it to the result.
        ○ For all its adjacent nodes:
        ■ Decrease their in-degree by 1.
        ■ If in-degree becomes 0, push into the queue.
    5. The order in which nodes are removed from the queue gives a topological sort.
    This works because nodes with zero in-degree have no dependencies
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
        
        //create indegree vector array
        vector<int> indegree(V);

        //calculate indegree of all vertex
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        // create queue
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        //while queue is not empty add it into queue
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            //because node is in our ans
            //so lets decrease its indegree
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
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
    Reason: Each vertex is processed once
    Each edge is processed once while reducing in-degrees
Space Complexity: O(V)
    Reason: In-degree array and queue can store up to V nodes
==================================================
*/