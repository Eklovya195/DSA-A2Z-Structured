/*
Problem:  Dijkstra's Algorithm
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1"
==================================================
Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
==================================================
*/

/*
Problem Statement:
    You are given a weighted, undirected, and connected graph with
        ● V vertices
        ● An adjacency list adj, where each entry contains {neighbor, weight}
        ● A source vertex S
    Your task is to find the shortest distance from the source vertex S to every other vertex.
    If a vertex is unreachable (not possible here since graph is connected), its distance would
    remain infinity.
    Note:
        ● The graph does not contain negative weight edges
        ● Dijkstra’s Algorithm fails if negative weights exist
*/

// Approach1: Using Priority queue
/*
Intuition:
    Dijkstra’s Algorithm is a greedy algorithm:
        ● Always expand the closest unprocessed node
        ● Once a node is popped with minimum distance, that distance is final
        ● Works only when all edge weights are non-negative
    Using a Priority Queue (Min-Heap) helps us:
        ● Efficiently extract the node with the minimum distance
        ● Avoid scanning all vertices repeatedly

*/

/*
Algorithm:
    1. Create a dist[] array initialized with a very large value (INF)
    2. Set dist[source] = 0
    3. Use a min-heap priority queue storing {distance, node}
    4. Push {0, source} into the queue
    5. While the queue is not empty:
        ○ Pop the node with the smallest distance
        ○ If this distance is greater than the stored distance, skip it
        ○ For each adjacent node:
            ■ If dist[curr] + weight < dist[adj]
            ■ Update dist[adj]
            ■ Push {dist[adj], adj} into the queue
    6. After completion, dist[] contains shortest distances from the source
*/

/*
//Uisng Min-Heap Priority Queue
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //create a adj list
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //create a min-heap priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //create a dist vector
        vector<int> dist(V,1e9);

        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()){
            int dis= pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int edgeweight = it.second;
                int adjNode = it.first;

                if(edgeweight+dis<dist[adjNode]){
                    dist[adjNode] = dis+edgeweight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int src = 2;
    int V = 3;
    Solution obj;
    vector<int> ans = obj.dijkstra(V, edges, src);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}

*/

/*
==================================================
Time Complexity:O(E log V)
     Each edge relaxation may push into heap → log V
Space Complexity:O(V + E)
     Distance array + adjacency list + priority queue
==================================================
*/



// Approach2: Using Set
/*
Intuition:
    Dijkstra’s Algorithm is a greedy algorithm:
    ● Always pick the node with the smallest known distance
    ● Try to improve (relax) distances of its neighbors
    ● Once a node is picked with minimum distance, that distance is final
    Using a set:
    ● Keeps {distance, node} pairs in sorted order
    ● Allows deleting outdated entries, unlike priority queue
*/

/*
Algorithm:
    1. Initialize:
        ○ dist[i] = INF for all nodes
        ○ dist[S] = 0
        ○ Insert {0, S} into the set
    2. While the set is not empty:
        ○ Extract the node with minimum distance
        ○ For each adjacent node:
            ■ If currentDist + edgeWeight < dist[adjNode]
            ■ Remove old {dist[adjNode], adjNode} from set (if exists)
            ■ Update dist[adjNode]
            ■ Insert updated pair into set
    3. Return the distance array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //create a adj list
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //create a set Data Structure
        set<pair<int,int>> st;
        //create a dist vector
        vector<int> dist(V,1e9);

        dist[src] = 0;
        st.insert({0,src});

        while(!st.empty()){
            auto it = *(st.begin());
            int dis= it.first;
            int node =it.second;
            st.erase(it);

            for(auto it:adj[node]){
                int edgeweight = it.second;
                int adjNode = it.first;

                if(edgeweight+dis<dist[adjNode]){
                    //erase if already exist
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis+edgeweight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};

int main(){
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    int src = 2;
    int V = 3;
    Solution obj;
    vector<int> ans = obj.dijkstra(V, edges, src);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity:O(E log V)
     Each edge may cause insertion/deletion in set → log V
Space Complexity:O(V + E)
    Distance array + adjacency list + set
==================================================
*/



//Note : Why using priority queue instead of queue?
// answer you will get with queue is also correct
// -> queue is also able to give answer but with queue you are doing brute force approach and 
// traversing through all paths and then finding minimal path 
// unnecessary traversal happens a lots of time