/*
Problem:  104. Maximum Depth of Binary Tree
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
Problem Link: "https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?utm=codolio"
==================================================
You are given the root of a Binary Tree.
Your task is to find the height (maximum depth) of the tree.
The height of a binary tree is defined as the number of nodes on the longest path from the
root node to any leaf node
==================================================
*/

/*
Approach 1
Algorithm:
    This approach uses recursion to calculate the height of the tree.
Steps:
    ● If the current node is NULL, return 0 (empty tree has height 0).
    ● Recursively calculate the height of the left subtree.
    ● Recursively calculate the height of the right subtree.
    ● The height of the current node is 1 + max(leftHeight, rightHeight).
    ● Return this value.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh,rh);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution obj;
    int ans = obj.maxDepth(root);
    cout << ans;
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each node of the binary tree is visited exactly once.
Space Complexity: O(h)
    In the worst case (skewed tree) O(N), the recursion stack can go up to N nodes
==================================================
*/

/*
Approach 2
Algorithm:
    This approach uses level order traversal to calculate the height of the tree.
Steps:
    If the current node is NULL, return 0 (empty tree has height 0).
    create a queue and push root in queue
    while q is not empty
        take size of queue and increase depth by 1
        traverse through queue front ke left and right and push them in the queue
        do this repetative 
    return depth as ans
*/
//for skewed tree we might use this approach
/*

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return depth;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    Solution obj;
    int ans = obj.maxDepth(root);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each node of the binary tree is visited exactly once.
Space Complexity: O(N)
==================================================
*/