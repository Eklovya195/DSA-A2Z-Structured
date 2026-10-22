/*
Problem:  543. Diameter of Binary Tree
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
Problem Link: "https://leetcode.com/problems/diameter-of-binary-tree/description/?utm=codolio"
==================================================
The diameter of a Binary Tree is defined as the longest distance between any two nodes in the tree.
This distance is measured as the number of edges on the longest path.
The path may or may not pass through the root.

Diameter = tree ke kisi bhi do nodes ke beech ka longest path (edges count)
==================================================
*/

// Approach 1: Brute Force Approach
// In this approach, we consider every node as a turning point of the diameter
/*
Algorithm:
    ● Initialize a variable diameter to store the maximum diameter.
    ● Define a recursive function to calculate height.
    ● For each node:
        ○ Recursively compute left subtree height.
        ○ Recursively compute right subtree height.
        ○ Update diameter as max(diameter, leftHeight + rightHeight).
    ● Return the diameter
*/

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
    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        // Diameter passing through the current node
        int lh = height(root->left);
        int rh = height(root->right);

        int currentDiameter = lh + rh;

        // Diameter entirely inside the left or right subtree
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return max({currentDiameter, leftDiameter, rightDiameter});
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution obj;
    int ans = obj.diameterOfBinaryTree(root);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N²)
    Height is recomputed for each node.
Space Complexity: O(H)
    Due to recursion stack, where H is the height of the tree.
==================================================
*/

//Approach 2: Optimal Approach (Single Traversal)
/*
The brute force approach is inefficient because heights are recalculated many times.
We can optimize this by calculating height and diameter together in a single postorder traversal.
At each node:
    ● Get left subtree height.
    ● Get right subtree height.
    ● Update diameter.
    ● Return the height to the parent.
This avoids repeated height calculations.
*/

/*
Algorithm:
    ● Initialize diameter as 0.
    ● Use a recursive postorder function.
    ● For each node:
        ○ Compute left height.
        ○ Compute right height.
        ○ Update diameter as max(diameter, leftHeight + rightHeight).
        ○ Return 1 + max(leftHeight, rightHeight).
    ● After traversal, return diameter
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
    int height(TreeNode* root,int &diameter){
        if(root==NULL) return 0;
        int lh = height(root->left,diameter);
        int rh = height(root->right,diameter);
        diameter = max(lh+rh,diameter);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution obj;
    int ans = obj.diameterOfBinaryTree(root);
    cout << ans;
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    each node is visited exactly once
Space Complexity: O(H)
    Due to recursion stack, where H is the height of the tree.
==================================================
*/