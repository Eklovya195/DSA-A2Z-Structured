/*
Problem:  110. Balanced Binary Tree
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
Problem Link: "https://leetcode.com/problems/balanced-binary-tree/description/?utm=codolio"
==================================================
Given a binary tree, determine if it is height-balanced.
==================================================
*/

/*
Algorithm:
This approach avoids repeated height calculations by combining height computation and balance checking in a single postorder traversal.
Steps:
    ● Traverse the tree using postorder (Left → Right → Root).
    ● For each node:
        ○ Get height of left subtree.
        ○ Get height of right subtree.
    ● If any subtree is already unbalanced, return -1.
    ● If abs(leftHeight - rightHeight) > 1, return -1.
    ● Otherwise, return max(leftHeight, rightHeight) + 1.
    ● If final result is not -1, the tree is balanced.
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
    bool isBalanced(TreeNode* root) {
        return dfsheight(root) != -1;
    }

    int dfsheight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfsheight(root->left);
        int rh = dfsheight(root->right);
        //these two line of code is to check if balanced or not
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    Solution obj;
    bool ans = obj.isBalanced(root);
    cout << ans;
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Each node of the binary tree is visited exactly once.
Space Complexity: O(h)
    only recursion stack is used
==================================================
*/