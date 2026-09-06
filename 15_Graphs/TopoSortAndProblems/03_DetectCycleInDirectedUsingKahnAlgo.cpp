/*
Problem:  Detect Cycle Using Kahn's Algo
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1"
==================================================
Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
Output: true
Explanation: The diagram clearly shows a cycle 0 -> 1 -> 2 -> 0
==================================================
*/

/*
Algorithm (Using BFS – Kahn’s Algorithm):
    A cycle in a directed graph can be detected using Kahn’s Algorithm, which is based on Topological Sorting.
    Key idea:
        A Directed Acyclic Graph (DAG) always has a topological ordering containing all vertices.
        If a graph contains a cycle, some vertices will never get in-degree 0, so they will never be processed.
    Steps:
    1. Create an indegree array to store the number of incoming edges for each vertex.
    2. Traverse the adjacency list and compute indegree of every vertex.
    3. Push all vertices with indegree = 0 into a queue.
    4. Initialize a counter count = 0 to count processed nodes.
    5. While the queue is not empty:
        ○ Pop a node from the queue.
        ○ Increment count.
        ○ For each neighbor of this node:
            ■ Decrease its indegree by 1.
            ■ If indegree becomes 0, push it into the queue.
    6. After BFS:
        ○ If count == V, all nodes were processed → no cycle.
        ○ If count < V, some nodes were not processed → cycle exists.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool DetectCycleUsingKahn(int V, vector<vector<int>>& edges) {
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

        int cnt = 0;
        //while queue is not empty add it into queue
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            //because node is in our ans
            //so lets decrease its indegree
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        // If all vertices were processed, graph is acyclic
        if(cnt == V) return false;
        // Some vertices could not be processed => cycle exists
        return true;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1},{1,3},{3,0},{0,2}};
    int V = 4;
    Solution obj;
    cout << boolalpha <<obj.DetectCycleUsingKahn(V,edges);
    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
    Reason:
        Each vertex is processed once.
        Each edge is considered once while updating indegrees.
Space Complexity: O(V + E)
    Reason:
        Adjacency list stores edges.
        Indegree array and queue take up to O(V) space.
==================================================
*/