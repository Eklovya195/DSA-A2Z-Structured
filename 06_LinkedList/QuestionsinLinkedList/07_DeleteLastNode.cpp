/*
Problem:   Delete Last Node of a Doubly Linked List
Problem Statement:
    A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
    Given a doubly-linked list, delete the node at the end of the doubly linked list.
    Note:
    You need not print anything. You’re given the head of the linked list, just return the head of the modified list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469?leftPanelTabValue=SUBMISSION"
==================================================
Input: Linked List:  4 <-> 10 <-> 3 <-> 5 <-> 20
Output: Modified Linked List: 4 <-> 10 <-> 3 <-> 5
Explanation: The last node having ‘data’ = 20 is removed from the linked list.
==================================================
*/

/*
Idea:
If the list is empty, nothing to delete.
If the list has only one node, delete it and return NULL.
Otherwise, traverse to the last node using next.
Use the prev pointer to reach the second last node.
Update the second last node’s next to NULL and delete the tail.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
Node* deleteLastNode(Node* head) {
    if (head == nullptr)
    return nullptr;
    if (head->next == nullptr) {
    delete head;
    return nullptr;
    }
    Node* tail = head;
    while (tail->next != nullptr) {
    tail = tail->next;
    }
    Node* secondLast = tail->prev;
    secondLast->next = nullptr;
    delete tail;
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
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(1);
    head->next->next->next->prev = head->next->next;
    head = deleteLastNode(head);
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