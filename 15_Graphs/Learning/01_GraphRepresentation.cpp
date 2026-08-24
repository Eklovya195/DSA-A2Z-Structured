//Using adjacency Matrix (Undirected Graph)
/*
#include<bits./stdc++.h>
using namespace std;

int main(){
    //No of edges and vertices
    int n,m;
    cin >> n >> m;

    //graph
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

//space Complexity = O(N^2)
*/

//Using adjacency List (Undirected Graph)
/*
#include<bits./stdc++.h>
using namespace std;

int main(){
    //No of edges and vertices
    int n,m;
    cin >> n >> m;

    //graph here
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
//Space Complexity: O(2*E)
*/

//Using adjacency List (directed Graph)
#include<bits./stdc++.h>
using namespace std;

int main(){
    //No of edges and vertices
    int n,m;
    cin >> n >> m;

    //graph here
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        //u-->v
        adj[u].push_back(v);
    }
    return 0;
}
//Space Complexity: O(E)