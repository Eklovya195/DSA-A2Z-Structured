/*
Problem:  Bipartite Graph using BFS
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
Approach:
    1. Create an color array of size V, initialized to -1.
    2. For every vertex,if not colored(-1):
        run check fxn:
            if check fxn return false -> not a bipartite graph
            else bipartite graph
    3.In check fxn:
        1.create a queue and push start element into queue
        2.color satrting element as 0
        3.check while queue is not empty
            check node adjacent elements
            case 1: if adjacent is not colored
                color them opposite color of node
            case 2: if adjacent is colored and
                if color[adj] == color[node] 
                    return false;
            else return true;
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
                if(check(i,V,adj,color) == false) return false;
            }
        }
        return true;
    }
    
    //we are using this because there are more than one connected components
    bool check(int start,int V,vector<int> adj[],vector<int> &color){
        //create a queue 
        queue<int> q;
        //push starting element in queue and colored it as 0
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //iterate through each adjacaent nodes
            for(auto it:adj[node]){
                //if not colored
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }else if(color[it]==color[node]){
                    return false;
                }
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
Time Complexity: O(V) + O(2*E)
Space Complexity: O(3*V) = O(V) //we are using queue data structure here
==================================================
*/