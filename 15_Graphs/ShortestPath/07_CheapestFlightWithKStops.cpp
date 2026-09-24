/*
Problem:  787. Cheapest Flight with K stops
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/cheapest-flights-within-k-stops/description/"
==================================================
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
==================================================
*/

/*
Algorithm:
    This approach uses BFS with stop control.
    1. Create an adjacency list from the flights array.
    2. Use a queue that stores {stops, {node, cost}}.
    3. Create a distance array initialized with a very large value.
    4. Push the source node with 0 stops and 0 cost into the queue.
    5. While the queue is not empty:
        ○ Pop the front element.
        ○ If the number of stops is greater than k, skip it.
        ○ Traverse all adjacent nodes.
        ○ If a cheaper cost is found and stops are within limit:
            ■ Update the distance.
            ■ Push the adjacent node with incremented stop count.
    6. After traversal:
        ○ If destination cost is still infinite, return -1.
        ○ Otherwise return the stored minimum cost.
    This works because BFS ensures we explore paths level by level based on stops
*/

//Solution 1: Using Priority Queue
//This is using the priority queue 
//but in this question there is no need of using priority queue as we are just adding
//only 1 into next 1 stop
//so only queue will work here and therefore this is not optimal solution
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create a adj list
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            adj[u].push_back({v,price});
        }

        //create a priority queue
        //{stops,{node,price}}
        //priority_queue< DATA_TYPE, CONTAINER, COMPARATOR >
        priority_queue<
        pair<int,pair<int,int>>,   //Data Type
        vector<pair<int,pair<int,int>>>,  //vector<DATA_TYPE> vector container
        greater<pair<int,pair<int,int>>> //Comparator<DATA_TYPE> normally pq is max heap so we need to addd greater
        >pq;

        vector<int> dist(n,1e9);
        dist[src] = 0;
        //{stops,{node,price}}
        pq.push({0,{src,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;

            if(stops>k) continue;
            for(auto iter:adj[node]){
                int adjnode = iter.first;
                int edgewt = iter.second;
                if(price+edgewt < dist[adjnode] && stops<=k){
                    dist[adjnode] = price+edgewt;
                    pq.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];

    }
};

int main(){
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100},{1,3,600},{2,3,200}};
    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;
    Solution obj;
    cout << obj.findCheapestPrice(n,flights,src,dst,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(E*log(Q))
    Each flight edge is processed at most once during BFS traversal.
    logQ is extra for priority queue becuase each insertion and deletion takes logQ time 
    but in normal queue it is done in O(1) times
    Q-> no of elements currently in priority queue
Space Complexity: O(E + V)
    Adjacency list stores all flights, and the distance array stores minimum cost for each city.
==================================================
*/

//Solution 2: Optimal
//this is the optimal solution as only queue is used
//time is reduced by logn times
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create a adj list
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            adj[u].push_back({v,price});
        }

        //crete a queue
        queue<pair<int,pair<int,int>>> q;

        vector<int> dist(n,1e9);
        dist[src] = 0;
        //{stops,{node,price}}
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;

            if(stops>k) continue;
            for(auto iter:adj[node]){
                int adjnode = iter.first;
                int edgewt = iter.second;
                if(price+edgewt < dist[adjnode] && stops<=k){
                    dist[adjnode] = price+edgewt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];

    }
};

int main(){
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100},{1,3,600},{2,3,200}};
    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;
    Solution obj;
    cout << obj.findCheapestPrice(n,flights,src,dst,k);
    return 0;
}

/*
==================================================
Time Complexity: O(E)
Each flight edge is processed at most once during BFS traversal.
Space Complexity: O(E + V)
Adjacency list stores all flights, and the distance array stores minimum cost for each city.
==================================================
*/