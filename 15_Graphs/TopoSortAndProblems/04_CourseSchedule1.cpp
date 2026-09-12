/*
Problem:  207. Course Schedule
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/course-schedule/description/"
==================================================
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
==================================================
*/

/*
Algorithm:
    The problem reduces to cycle detection in a directed graph.
    If the graph has a cycle, tasks cannot be finished.
    If the graph is a DAG, tasks can be finished.
    We use Kahn’s Algorithm (BFS Topological Sort):
    1. Treat each task as a node.
    2. Create a directed edge b → a for prerequisite [a, b].
    3. Compute inDegree for every task.
    4. Push all tasks with inDegree = 0 into a queue.
    5. Process the queue:
        ○ Remove a task.
        ○ Reduce inDegree of its neighbors.
        ○ Push neighbors whose inDegree becomes 0.
    6. Count processed tasks.
    7. If processed count == N → possible, else not possible
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        return topo.size() == numCourses;
        
    }
};

int main(){
    vector<vector<int>> prerequisites = {{0,1}};
    int numCourses = 2;
    Solution obj;
    cout << boolalpha << obj.canFinish(numCourses,prerequisites);
    return 0;
}

/*
==================================================
Time Complexity: O(V + E)
    Each task and dependency is processed once.
Space Complexity: O(V + E)
    Adjacency list, inDegree array, queue.
==================================================
*/