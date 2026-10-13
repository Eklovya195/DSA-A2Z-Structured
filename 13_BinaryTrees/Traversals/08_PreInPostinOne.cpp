/*
Problem:  Pre Post and In in single Traversals
Platform: Binary Tree / Striver A2Z
Difficulty: Easy
==================================================
Algorithm:(This is solved all using single stack)
Steps:
    ● If the tree is empty, return empty traversals.
    ● Create three arrays: pre, in, and post.
    ● Use a stack that stores {node, state}.
    ● Push the root node with state 1 onto the stack.
    ● While the stack is not empty:
        ○ Pop the top element.
        ○ If state is 1:
            ■ Add node value to preorder.
            ■ Change state to 2 and push it back.
            ■ Push left child with state 1 if it exists.
        ○ If state is 2:
            ■ Add node value to inorder.
            ■ Change state to 3 and push it back.
            ■ Push right child with state 1 if it exists.
        ○ If state is 3:
            ■ Add node value to postorder.
    ● Return all three traversal arrays.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};


class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
            if(root == NULL) return {};
			vector<vector<int>> ans;
            vector<int> pre,in,post;
            stack<pair<TreeNode*,int>> st;
            st.push({root,1});
            if(root == NULL) return ans;
            while(!st.empty()){
                auto it = st.top();
                st.pop();

                //first time pushing 
                //incrementing from 1 to 2
                //push in stack left part
                if(it.second == 1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->left != NULL){
                        st.push({it.first->left,1});
                    }
                }
                //this is for second time 
                //push right side one
                else if(it.second == 2){
                    in.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->right != NULL){
                        st.push({it.first->right,1});
                    }
                }
                else{
                    post.push_back(it.first->data);
                }
            }
            ans.push_back(in);
            ans.push_back(pre);
            ans.push_back(post);
            return ans;
		}
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    Solution obj;
    vector<vector<int>> ans = obj.treeTraversal(root);
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
Complexity Analysis:
Time Complexity: O(3*N)
    Creating N nodes takes linear time.
Space Complexity: O(4*N)
    Memory is used to store N nodes of the binary tree.
==================================================
*/