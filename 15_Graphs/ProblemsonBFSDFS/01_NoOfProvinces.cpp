/*
Problem:  547. Number of Provinces
problem Statement:There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
    A province is a group of directly or indirectly connected cities and no other cities outside of the group.
    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
    Return the total number of provinces.
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/number-of-provinces/description/"
==================================================
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
==================================================
*/

/*
Algorithm:
    A province contains all cities that can be reached from one city using traversal.
    1. Create a visited array to track visited cities.
    2. Convert the adjacency matrix into an adjacency list for easy traversal.
    3. Loop through all cities from 0 to V-1.
    4. If a city is not visited:
        ○ It means we found a new province.
        ○ Increase the province counter.
        ○ Run DFS from that city to mark all cities in this province as visited.
    5. The number of times DFS is started gives the number of provinces.
DFS ensures that all directly or indirectly connected cities are visited in one call
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],int vis[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int main(){
    int V,E;
    cin >> V >> E;

    //building adjacency matrix
    vector<vector<int>> isConnected(V, vector<int>(V, 0));
    for(int i=0;i<E;i++){
        int v,u;
        cin >> v >> u;
        isConnected[u][v] = 1;
        isConnected[v][u] = 1;    
    }

    //convert matrix into list
    vector<int> adj[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(isConnected[i][j] == 1 && i!=j){
                adj[j].push_back(i);
                // adj[i].push_back(j);
            }
        }
    }

    //create visited list
    int vis[V] = {0};
    int cnt = 0;
    //count connected component
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adj,vis);
        }
    }
    cout << cnt;
    return 0;
}

/*
==================================================
Time Complexity: O(V+E)
Reason: Each vertex is visited once, and all its edges are traversed during DFS
Space Complexity: O(V)
Reason: Space used for visited array and recursion stack
==================================================
*/