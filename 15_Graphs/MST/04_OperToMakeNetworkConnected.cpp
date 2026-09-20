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
Algorithm (Little bit modification):
    To make a graph connected:
        If a graph has components connected components, then we need at least components - 1 edges to connect them.
        We are not allowed to add new edges freely; we can only reuse extra (redundant) edges.
    Steps:
    1. Initialize a Disjoint Set Union (DSU) to track connected components.
    2. If total edges < n - 1, it is impossible to connect the graph, return -1
    3. Traverse all edges:
        ○ If an edge connects two nodes already in the same component, leave it.
        ○ Otherwise, union the two components.
    4. After processing all edges, count the number of connected components.
        to count no of connected components find out no of parent[i] = i 
    5. To connect all components, we need (connectedComponents - 1) edges
        which will be our answer
*/

/*
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size,parent;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Not enough cables
        if(connections.size() < n - 1) return -1;
        int e = connections.size();
        DisjointSet ds(n);
        for(int i=0;i<e;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionBySize(u,v);
        }

        //concept is that find no of disconnected components 
        //and because we already checked n-1 cables are present or not
        //so answer will be disconnected components-1
        int discnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                discnt++;

            }
        }
        return discnt-1;
    }
};

int main(){
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
    int V = 6;
    Solution obj;
    cout << obj.makeConnected(V,connections);
    return 0;
}
*/

/*
Algorithm(Striver One):
    To make a graph connected:
        If a graph has components connected components, then we need at least components - 1 edges to connect them.
        We are not allowed to add new edges freely; we can only reuse extra (redundant) edges.
    Steps:
    1. Initialize a Disjoint Set Union (DSU) to track connected components.
    2. Traverse all edges:
        ○ If an edge connects two nodes already in the same component, it is an extra edge.
        ○ Otherwise, union the two components.
    3. After processing all edges, count the number of connected components.
    4. To connect all components, we need (components - 1) edges.
    5. If the number of extra edges is at least (components - 1), return (components -1).
    6. Otherwise, return -1.
    Important check:
    ● If total edges < n - 1, it is impossible to connect the graph.
*/


#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> size,parent;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        DisjointSet ds(n);
        int cntExtras = 0;
        for(int i=0;i<e;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtras++;
            }else{
                ds.unionBySize(u,v);
            }
        }
        
        int discnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                discnt++;

            }
        }
        int ans = discnt-1;
        if(cntExtras>=ans) return ans;
        return -1;
    }
};

int main(){
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
    int V = 6;
    Solution obj;
    cout << obj.makeConnected(V,connections);
    return 0;
}


/*
==================================================
Time Complexity: O(N + M × α(N))
    Each DSU operation is almost constant time, and we process all nodes and edges once.
Space Complexity: O(N)
    Used for DSU parent and size arrays.
==================================================E
*/