/*
Problem: Search in Linked List
Problem Statement: Given a linked list with the head node and a key, the task is to check if the key is present in the linked list or not. 
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1"
==================================================
Input: head: 1 -> 2 -> 3 -> 4 -> 5,key =3
Output: true
==================================================
*/

/*
Idea:
Traverse the linked list from the head node.
At each node, compare its data with the given value.
If a match is found, return true.
If the traversal ends without a match, return false
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
    data = val;
    next = nullptr;
}
};

class Solution {
public:
    bool searchValue(Node* head, int val) {
    Node* temp = head;
    while (temp != nullptr) {
    if (temp->data == val)
    return true;
    temp = temp->next;
    }
    return false;
    }
};

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Solution sol;
    int val = 20;
    cout << (sol.searchValue(head, val) ? "True" : "False");
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/