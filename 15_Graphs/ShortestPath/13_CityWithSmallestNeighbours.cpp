/*
Problem: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/"
==================================================
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
==================================================
*/

/*
Problem Statement: 
    You are given n cities numbered from 0 to n-1. The cities are connected by bidirectional weighted edges.
    Each edge [u, v, w] means the distance between city u and city v is w.
    You are also given an integer distanceThreshold.
    For every city, count how many cities (including itself) are reachable with shortest distance ≤
    distanceThreshold.
    You must return the city that has the smallest number of reachable cities.
    If multiple cities have the same minimum count, return the city with the largest city number.
    Example:
        If city 0 and city 3 both can reach only 2 cities within the threshold, the answer is city 3.
*/

/*
Algorithm:
    This problem is solved using the Floyd Warshall Algorithm to compute all-pairs shortest paths.
    1. Create a distance matrix dist of size n x n.
    2. Initialize all distances as INT_MAX(1e9).
    3. For every edge [u, v, w]:
        ○ Set dist[u][v] = w
        ○ Set dist[v][u] = w (because the graph is bidirectional)
    4. Set dist[i][i] = 0 for all cities.
    5. Apply Floyd Warshall:
        ○ For every intermediate city k
        ○ For every pair (i, j)
        ○ Update
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    6. For each city:
        ○ Count how many cities have distance ≤ distanceThreshold.
    7. Keep track of the minimum count.
        ○ If the count is smaller or equal, update the answer city.
        ○ Equal is allowed because we want the largest city number in case of a tie.
    8. Return the city number
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
Time Complexity: O(V^3)
    Three nested loops are used in Floyd Warshall, where V is the number of cities.
Space Complexity: O(V^2)
    The distance matrix of size V x V is used to store shortest paths
==================================================
*/