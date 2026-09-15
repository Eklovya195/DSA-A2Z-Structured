/*
Problem:  MST using Prims Algorithm
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
    Prim’s Algorithm builds the MST greedily, starting from any node and always choosing the
    minimum weight edge that connects a visited node to an unvisited node.
    Steps:
    1. Use a visited array to mark nodes that are already part of the MST.
    2. Use a priority queue (min-heap) that stores pairs {edgeWeight, node}.
    3. Start from node 0 by pushing {0, 0} into the priority queue.
    4. Initialize sum = 0 to store the total weight of the MST.
    5. While the priority queue is not empty:
        ○ Pop the element with the minimum edge weight.
        ○ If the node is already visited, skip it.
        ○ Otherwise:
            ■ Mark the node as visited.
            ■ Add the edge weight to sum.
            ■ Push all adjacent unvisited nodes into the priority queue with their edge weights.
    6. When all nodes are visited, sum contains the total weight of the MST
    This works because at every step we greedily pick the smallest edge that expands the current tree without forming a cycle.
*/

//Just giving sum of MST
/*
#include<bits/stdc++.h>
using namespace std;

//Prims Algorithm
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //create adj list
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        //step1: create priority queue and visited array
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);

        //step2: push first element in pq
        //{wt,node}
        pq.push({0,0});

        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;
            if(vis[node]==1) continue;

            //add it to the map
            vis[node] = 1;
            sum += weight;

            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeweight = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeweight,adjNode});
                }
            }
        }
        return sum;
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

*/
/*
==================================================
Time Complexity: O(E log E)
    Each edge can be pushed into the priority queue, and push/pop operations take log E time.
Space Complexity: O(E + V)
    O(E) for the priority queue and adjacency list, and O(V) for the visited array.
==================================================
*/

//IN this i am also printing the mst path along with sum
#include<bits/stdc++.h>
using namespace std;

//Prims Algorithm
class Solution {
  public:
    vector<pair<int,int>> spanningTree(int V, vector<vector<int>>& edges) {
        //create adj list
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        //step1: create priority queue and visited array
        //for priority queue {Data Type,Container,Comparator}
        //{weight,node,parent}
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<int> vis(V,0);

        //step2: push first element in pq
        //{wt,node,parent}
        pq.push({0,0,-1});

        // int sum = 0;
        vector<pair<int,int>> mst;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int weight = get<0>(it);
            int node = get<1>(it);
            int parent = get<2>(it);
            if(vis[node]==1) continue;

            //add it to the map
            vis[node] = 1;
             // Don't add starting node
            if(parent != -1) {
                mst.push_back({node, parent});
            }
            // sum += weight;

            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgeweight = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeweight,adjNode,node});
                }
            }
        }
        return mst;
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
    vector<pair<int,int>> ans = obj.spanningTree(V,edges);
    for(int i=0;i<ans.size();i++){
        cout << "{";
        cout << ans[i].first << "," << ans[i].second;
        cout << "}";
    }
    return 0;
}
