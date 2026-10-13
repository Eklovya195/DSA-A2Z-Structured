/*
Problem:  Tree Traversals
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
Practice Link: Preorder: "https://leetcode.com/problems/binary-tree-preorder-traversal/description/?utm=codolio"
                Inorder: "https://leetcode.com/problems/binary-tree-inorder-traversal/?utm=codolio"
                Postorder: "https://leetcode.com/problems/binary-tree-postorder-traversal/description/?utm=codolio"
==================================================
This one is showing recursive approach for all kind of binary tree traversals 
==================================================
*/

//All are recursive approaches
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

//left->root->right (DFS)
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//root->left->right (DFS)
void preorder(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//left->right->root (DFS)
void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}

/*
==================================================
Time complexity: O(n)
Space Complexity:O(h) in worst case O(n) in skew tree else h = logn
   beacuse recursive uses stack space
==================================================
*/