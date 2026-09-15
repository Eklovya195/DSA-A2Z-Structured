/*
Problem:  Bipartite Graph using DFS
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/bipartite-graph/1"
  Leetcode: "https://leetcode.com/problems/is-graph-bipartite/description/"
==================================================
Input: V = 3, edges[][] = [[0, 1], [1,2]]
Output: true
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
==================================================
*/

/*
Some Things to remember:
    Graph is always Bipartite if:
        1.If graph is linear + No cycle
        2.If graph has even length cycle
    Graph is not Bipartite if:
        Graph has odd length cycle
*/

/*
Algorithm:
    We use Depth First Search (DFS) with coloring.
    1. Create a color array of size V, initialize all values to -1 (uncolored).
    2. Since the graph can have multiple connected components, iterate over all vertices.
    3. For every uncolored vertex:
        ○ Start DFS and assign it color 0.
    4. In DFS:
        ○ Assign the current node the given color.
        ○ Traverse all adjacent nodes:
            ■ If an adjacent node is uncolored, assign it the opposite color and continue DFS.
    ■ If an adjacent node is already colored with the same color, return false.
    5. If DFS completes successfully for all components, return true.
    DFS ensures we try to color the graph consistently. Any conflict means the graph is not bipartite. 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        //create a adjacent vector array
        vector<int> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //create a colored array
        //-1 means not colored
        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(dfscheck(i,0,adj,color) == false) return false;
            }
        }
        return true;
    }
    
    //we are using this because there are more than one connected components
    bool dfscheck(int node,int col,vector<int> adj[],vector<int> &color){
        
        color[node] = col;

        for(auto it :  adj[node]){
            //if adjnode is not colored
            if(color[it] == -1){
                if(dfscheck(it,!col,adj,color)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> edges = {{0,3},{1,2},{3,2},{0,2}};
    int V = 3;
    Solution obj;
    bool ans =  obj.isBipartite(V, edges);
    if(ans) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is not Bipartite" << endl;
    return 0;
}

/*
==================================================
Time Complexity: O(V+2*E)
    Reason: Each vertex and each edge is visited once during DFS.
Space Complexity: O(3*V) = O(V) 
    Reason: Space used by color array and recursion stack.
==================================================
*/