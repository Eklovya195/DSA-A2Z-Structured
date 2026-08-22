/*
Problem: 237. Delete a Node in Linked List
Problem Statement: There is a singly-linked list head and we want to delete a node node in it.
    You are given the node to be deleted node. You will not be given access to the first node of head.
    All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
    Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.
    Custom testing:
    For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
    We will build the linked list and pass the node to your function.
    The output will be the entire list after calling your function.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/delete-node-in-a-linked-list/"
==================================================
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
==================================================
*/

/*
Here the catch is tha we are not given head and
we are just given node pointing to the value which we need to delete
and we don't need to return anything
*/


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
