/*
Problem:  Iterative Tree Traversals
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
Practice Link: Preorder: "https://leetcode.com/problems/binary-tree-preorder-traversal/description/?utm=codolio"
                Inorder: "https://leetcode.com/problems/binary-tree-inorder-traversal/?utm=codolio"
                Postorder: "https://leetcode.com/problems/binary-tree-postorder-traversal/description/?utm=codolio"
==================================================
Algorithm(Inorder):In inorder traversal, we visit the left subtree first, then the root, and then the right subtree.
    Using a stack, we keep moving left until we reach NULL, then process nodes while backtracking
    ● Create an empty stack.
    ● Set current node as root.
    ● While current is not NULL or stack is not empty:
        ○ Push current node and move to left child.
        ○ When NULL is reached, pop from stack.
        ○ Visit the node.
        ○ Move to right child.
Algorithm(Preorder):In preorder traversal, we visit the root first, then left subtree, then right subtree.
We use a stack and always process the current node before pushing its children.
    ● If root is NULL, return.
    ● Push root into stack.
    ● While stack is not empty:
        ○ Pop top node and visit it.
        ○ Push right child first.
        ○ Push left child next.

==================================================
*/

//All are Iterative approaches
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    public:
    Node(int val1){
        val = val1;
        left = right = nullptr;
    }
};

//left->root->right (DFS)
void inorder(Node* root){
    if(root == NULL) return;

    Node* node = root;
    stack<Node*> st;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout << node->val << " ";
            node = node->right;
        }
    }
}

//root->left->right (DFS)
void preorder(Node* root){
    if(root == NULL) return;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        cout << root->val << " ";
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
}

//left->right->root (DFS)
// void postorder(Node* root){
//     if(root == NULL) return;

//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    // cout << "\nPostorder: ";
    // postorder(root);
    return 0;
}

/*
==================================================
Time complexity: O(n)
Space Complexity:O(h) in worst case o(n) for skew tree else h = logn 
   beacuse recursive uses stack space
==================================================
*/