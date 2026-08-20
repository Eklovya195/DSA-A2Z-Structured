/*
Problem:  Insert at end of Doubly Linked List
Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
Given a doubly-linked list and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.
Note:
You need not print anything. You’re given the head of the linked list. Return the head of the modified list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464?leftPanelTabValue=PROBLEM"
==================================================
Input: Linked List: 4 <-> 10 <-> 3 <-> 5 and ‘k’ = 20
Output: Modified Linked List: 4 <-> 10 <-> 3 <-> 5 <-> 20
Explanation: A new node having value ‘k’ = 20 is inserted at the end of the linked list.
==================================================
*/

/*
Idea:
If the list is empty, the new node becomes the head.
Otherwise, traverse to the last node (tail).
Link the new node after the tail and update both next and prev pointers.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
Node* insertAtEnd(Node* head, int k) {
    Node* newNode = new Node(k);
    if (head == nullptr)
    return newNode;
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}
void printList(Node* head) {
while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head = insertAtEnd(head, 6);
    printList(head);
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/