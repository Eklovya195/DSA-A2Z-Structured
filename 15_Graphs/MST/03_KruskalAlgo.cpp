/*
Problem:  MST using Kruskal's Algorithm
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1"
==================================================
Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
Output: 4
==================================================
*/

/*
Algorithm:
    Kruskal’s Algorithm builds the MST by always choosing the smallest available edge that does not form a cycle.
    1. Store all edges in the form (weight, u, v).
    2. Sort all edges in ascending order of weight.
    3. Create a Disjoint Set (Union-Find) to track connected components.
    4. Iterate through the sorted edges:
        ○ If u and v belong to different components:
            ■ Add the edge weight to the MST sum.
            ■ Union the components of u and v.
        ○ Otherwise, skip the edge (it forms a cycle).
    5. After processing all edges, the accumulated sum is the MST weight.
    Cycle detection is efficiently handled using the Disjoint Set data structure
*/

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        //finding the ultimate parent
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;

        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //Using Kruskal Algorithm
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        DisjointSet ds(V);
        int mstwt = 0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};

int main() {
    vector<vector<int>> edges = {
    {0,1,5},
    {1,2,3},
    {0,2,1}
    };
    int V = 3;
    int E = 3;
    Solution obj;
    cout << obj.spanningTree(V,edges);
    return 0;
}

/*
==================================================
Time Complexity:O(E log E)
    Sorting the edges dominates. Disjoint set operations are almost constant time.
Space Complexity:O(E + V)
    Edges array uses O(E) space, and Disjoint Set uses O(V) space.
==================================================E
*/