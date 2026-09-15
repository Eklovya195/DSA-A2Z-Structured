/*
Problem:  Directed Graph Cycle Detection using DFS
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
Approach:
    To detect a cycle in a directed graph, we use DFS with two visited arrays.
    1. Create two arrays:
        ○ vis[] → marks nodes that are completely visited
        ○ pathVis[] → marks nodes visited in the current DFS path
    2. Traverse the graph component-wise using DFS.
    3. In DFS for a node:
        ○ Mark it as visited in both vis and pathVis.
    4. For every adjacent node:
        ○ Case 1: If the node is not visited, call DFS recursively.
        ○ Case 2: If the node is visited and also marked in pathVis, a cycle exists → return true.
        ○ Case 3: If the node is visited but not in pathVis, ignore it.
    5. After exploring all neighbors:
        ○ Unmark the node from pathVis (backtracking).
    6. If no cycle is found in any DFS call, return false.
    The key idea is:
    👉 Cycle exists only if a node is revisited on the same DFS path.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis)) return true;
            }
            else if(pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> adj[11] = {
    {}, {2}, {3}, {4,7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);
    if(ans) cout << "True\n";
    else cout << "False\n";
    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
    Reason: Each node and edge is visited once during DFS.
Space Complexity: O(V)
    Reason: Two visited arrays and recursion stack space.
==================================================
*/