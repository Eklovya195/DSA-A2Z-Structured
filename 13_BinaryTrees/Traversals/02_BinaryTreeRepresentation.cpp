/*
Problem:  Tree Traversals
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
==================================================
Algorithm:
We represent a binary tree using a Node class.
Each node contains:
    ● an integer value (data)
    ● a pointer to the left child
    ● a pointer to the right child
Steps:
    ● Define a Node class with data, left pointer, and right pointer.
    ● Use a constructor to initialize the node value and set child pointers to NULL.
    ● Create nodes dynamically using new.
    ● Connect nodes by assigning the left and right pointers of a parent node.
Example explanation:
    ● Create a root node with value 1.
    ● Assign its left child as a node with value 2.
    ● Assign its right child as a node with value 3.
    ● Assign a left child to node 3 with value 5.
This forms the binary tree structure using pointers.
==================================================
*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;   // Value stored in the node
    Node* left; // Pointer to left child
    Node* right; // Pointer to right child

    //constructor
    public:
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

// Class to create a Binary Tree
class Solution {
    public:
    Node* createBinaryTree() {
        // Create root node
        Node* root = new Node(1);
        // Create left and right children
        root->left = new Node(2);
        root->right = new Node(3);
        // Create further child
        root->right->left = new Node(5);
        return root;
    }
};

// Driver code
int main(){
    Solution sol;
    Node* root = sol.createBinaryTree();
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(N)
    Creating N nodes takes linear time.
Space Complexity: O(N)
    Memory is used to store N nodes of the binary tree.
==================================================
*/
