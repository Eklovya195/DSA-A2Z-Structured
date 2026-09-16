/*
==================================================
A Disjoint Set (also called Union-Find) is a data structure used to manage a collection of
non-overlapping sets.
It is mainly used to answer questions like:
“Do node u and node v belong to the same connected component?”
This is very useful in graphs that change over time (dynamic graphs), where edges are
added step by step and we need fast connectivity checks.
==================================================
*/

/*
==================================================
Why Disjoint Set is needed?
    Suppose we are given an undirected graph and asked whether node 1 and node 5 belong to the same component.
    ● Using DFS or BFS: O(N + E) time for every query.
    ● Using Disjoint Set: almost constant time per query.
    That is why Disjoint Set is preferred for multiple connectivity queries
==================================================

Dynamic Graph Concept:
    A dynamic graph is a graph where edges are added over time.
    Example edge sequence:
    {(1,2), (2,3), (4,5), (6,7), (5,6), (3,7)}
    ● After adding first 4 edges → node 1 and node 4 are in different components.
    ● After adding all edges → node 1 and node 4 become part of the same component.
    Disjoint Set can answer such queries efficiently after every update.
==================================================

Operations in Disjoint Set
    1. findUPar(node)
        Finds the ultimate parent (root) of a node.
    2. Union(u, v)
        Merges the sets containing u and v.
    Optimizations:
    ● Union by Rank
    ● Union by Size
    ● Path Compression
==================================================
*/

// Method 1: Union By Rank
/*
==================================================
In union by rank:
    ● Each node has a rank value.
    ● While merging two components, attach the component with smaller rank under the one with larger rank.
    ● If ranks are equal, attach any one and increase the rank by 1.
    This helps in keeping the tree shallow
==================================================

Why Ultimate Parent Matters?
    Two nodes may have different immediate parents but still belong to the same component.
    Example:
    ● Node 5 → parent 6
    ● Node 7 → parent 6
    Immediate parents differ, but ultimate parent is same, so they are connected.
    Hence, comparisons are always done using ultimate parents.
==================================================
Study about Path compression
*/

//Union By Rank(Path Compression)
/*
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);

    }
    void unionByRank(int u,int v){
        //finding the ultimate parent
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3)==ds.findUPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    ds.unionByRank(3,7);
    if(ds.findUPar(3)==ds.findUPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    return 0;
}
*/

//Union By Size()
/*
==================================================
Union by size is similar to union by rank, but instead of rank:
● We store the size of each component.
● Attach the smaller component under the larger one.
● Update the size accordingly.
This method is more intuitive because size does not get distorted after path compression.
==================================================

Algorithm:
    1. Find ultimate parents of u and v.
    2. Compare size[pu] and size[pv].
    3. Attach smaller size component to larger size component.
    4. Update the size.
==================================================
*/

//Union By Size code
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
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUPar(3)==ds.findUPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    ds.unionBySize(3,7);
    if(ds.findUPar(3)==ds.findUPar(7))
        cout<<"Same\n";
    else
        cout<<"Not same\n";
    return 0;
}

/*
==================================================
Time Complexity: O(4*α)
    findUPar + union operations: O(α(N))
    α(N) (inverse Ackermann function) is very small
    Practically treated as constant time
==================================================
*/