/*
Problem: Floyd Warshall Algorithm
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm=codolio"
==================================================
Input: dist[][] = [[0, 4, 108, 5, 108], [108, 0, 1, 108, 6], [2, 108, 0, 3, 108], [108, 108, 1, 0, 2], [1, 108, 108, 4, 0]]
Output: [[0, 4, 5, 5, 7], [3, 0, 1, 4, 6], [2, 6, 0, 3, 5], [3, 7, 1, 0, 2], [1, 5, 5, 4, 0]]

==================================================
*/

/*
FloydWarshall Works on directed Edges if undirected graph is given then create directed edge between both vertices 
and then implement Floyd Warshall Algo
Problem Statement: 
    You are given a directed weighted graph with V vertices numbered from 0 to V-1.
    The graph is represented using an adjacency matrix matrix, where matrix[i][j] is the
    weight of the edge from vertex i to vertex j.
    If matrix[i][j] = -1, it means there is no direct edge between i and j.
    Your task is to find the shortest distance between every pair of vertices.
    If a vertex is unreachable from another vertex, the value should remain -1
*/

/*
Algorithm:
    Floyd Warshall is an all-pairs shortest path algorithm.
    1. Treat the given adjacency matrix as the distance matrix.
    2. Use three nested loops:
        ○ Outer loop picks an intermediate node k.
        ○ Inner loops try to improve the path from i to j using node k.
    3. For every pair (i, j):
        ○ If there is no path from i to k or k to j, skip.
        ○ If there is no direct edge from i to j, update it using i → k → j.
        ○ Otherwise, take the minimum of the current distance and the new distance via k.
    4. After processing all intermediate nodes, the matrix contains the shortest distances.
    This works because every shortest path can be built by gradually allowing more intermediate vertices.

    To find out neagtive cycle?
    if cost of any node to same node < 0 that means neagtive cycle is present

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        //to check if any neagtive cycle is present or not
        // for(int i=0;i<n;i++){
        //     if(dist[i][i]<0) cout << "Neagtive Cycle Present";
        // }
    }
};

int main(){
vector<vector<int>> dist = {{0, 2, -1, -1},{1, 0, 3, -1},{-1, -1, 0, 1},{3, 5, 4, 0}};
    Solution sol;
    sol.floydWarshall(dist);
    for(int i = 0; i < dist.size(); i++){
        for(int j = 0; j < dist.size(); j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
==================================================
Time Complexity: O(V^3), V = no of vertices
    Three nested loops over all vertices
Space Complexity: O(V^2)
    The dist matrix itself stores distances for all vertex pairs.
==================================================
*/