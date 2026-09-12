/*
Problem:  210. Course Schedule ||
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/course-schedule-ii/description/"
==================================================
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
==================================================
*/

/*
Algorithm:
    This is an extension of Course Schedule I.
    Instead of only checking feasibility, we store the topological order.
    Steps are the same as Kahn’s Algorithm:
    1. Build graph and inDegree array.
    2. Push all nodes with inDegree = 0 into queue.
    3. While queue is not empty:
        ○ Pop node and add it to order.
        ○ Reduce inDegree of neighbors.
    4. If order size == N, return order.
    5. Otherwise, return empty array (cycle exists).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        //run bfs in directed graph
        //create indegree vector array
        vector<int> indegree(numCourses,0);

        //calculate indegree of all vertex
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        // create queue
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

       vector<int> topo;
        //while queue is not empty add it into queue
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            //because node is in our ans
            //so lets decrease its indegree
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        // If all vertices were processed, graph is acyclic
        if(topo.size()==numCourses) return topo;
        return {};
    }
};

int main(){
    vector<vector<int>> prerequisites = {{0,1}};
    int numCourses = 2;
    Solution obj;
    vector<int> ans = obj.findOrder(numCourses,prerequisites);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
    Each task and dependency is processed once.
Space Complexity: O(V + E)
    Adjacency list, inDegree array, queue,topo.
==================================================
*/