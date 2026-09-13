/*
Problem:  802. Find Eventual Safe State
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/find-eventual-safe-states/description/"
==================================================
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

==================================================
*/

/*
Algorithmm (BFS + Topological Sort):
    The idea is to eliminate all nodes that are part of cycles or lead to cycles.
    Key observations:
    ● Terminal nodes (outdegree = 0) are always safe.
    ● If a node points only to safe nodes, it is also safe.
    ● Nodes in cycles will never become terminal.
    To use topological sort logic, we do the following:
    1. Reverse the graph:
        ○ Original edge: u → v
        ○ Reversed edge: v → u
    2. In the reversed graph:
        ○ Terminal nodes become nodes with indegree = 0.
    3. Create an indegree[] array based on the reversed graph.
    4. Push all nodes with indegree = 0 into a queue.
    5. Perform BFS:
        ○ Pop a node → it is safe.
        ○ For each neighbor in the reversed graph:
            ■ Decrease its indegree.
            ■ If indegree becomes 0, push it into the queue.
    6. All nodes processed by BFS are safe nodes.
    7. Sort the result as required.
Nodes that are part of cycles will never reach indegree 0, so they are excluded automatically.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        //create a reverse graph and store every vertex indegree
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};

int main(){
    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    Solution obj;
    vector<int> ans = obj.eventualSafeNodes(graph);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(V + E) + O(N log N)
    O(V + E) for BFS traversal
    O(N log N) for sorting safe nodes
Space Complexity: O(V + E)
    Reversed adjacency list
    Indegree array
    Queue for BFS
==================================================
*/