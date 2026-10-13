/*
Problem:  Level Order Tree Traversals
Platform: Binary Tree / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/binary-tree-level-order-traversal/description/?utm=codolio"
==================================================
Level order traversal visits nodes level by level from left to right.
Example explanation:
For the tree, level order traversal will visit: 1 → 2 → 3
Algorithm:
    ● If root is NULL, return.
    ● Create a queue and push the root node.
    ● While the queue is not empty:
        ○ Pop the front node and visit it.
        ○ Push its left child if it exists.
        ○ Push its right child if it exists.
==================================================
*/

//level order is (BFS) approach
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(int val1){
        val = val1;
        left = right = nullptr;
    }
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    Solution obj;
    vector<vector<int>> ans = obj.levelOrder(root);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    return 0;
}


/*
==================================================
Time Complexity: O(N)
    Each node is visited once.
Space Complexity: O(N)
    Queue can store up to one full level of the tree.
==================================================
*/


