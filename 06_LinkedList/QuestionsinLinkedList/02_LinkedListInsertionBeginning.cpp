/*
Problem: Linked List Insertion At Beginning
Problem Statement: You are given the head of a Singly Linked List and a value x, insert that value x at the beginning of the LinkedList and return the head of the modified Linked List.
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/linked-list-insertion-at-beginning/1"
==================================================
Input:x = 6
        2 -> 4 -> 5
Output: 6 -> 2 -> 4 -> 5
==================================================
*/

/*
Algorithm (Step-by-Step)
1. Create a new node with data = val
2. Set newNode->next to the current head
3. Return newNode as the updated head
*/

/*
Dry Run
Initial List
head → 2 → 3 → NULL
Insert value 1 at head
Step 1: Create new node
newNode = 1
Step 2: Point new node to old head
1 → 2 → 3 → NULL
Step 3: Update head
head = newNode
Final List:
1 → 2 → 3 → NULL
*/

#include <bits/stdc++.h>
using namespace std;
// Node class to represent each node in the linked list
class Node {
public:
    // Data stored in the node
    int data;
    // Pointer to the next node
    Node* next;
    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
// Solution class to handle linked list operations
class Solution {
public:
    // Function to insert a new node at the head
    Node* insertAtHead(Node* head, int newData) {
    // Create a new node whose next points to current head
    Node* newNode = new Node(newData, head);
    // Return the new node as the head
    return newNode;
    }
    // Function to print the linked list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
Solution sol;
    // Creating a sample linked list: 2 -> 3
    Node* head = new Node(2);
    head->next = new Node(3);
    cout << "Original List: ";
    sol.printList(head);
    // Inserting new node at head
    head = sol.insertAtHead(head, 1);
    cout << "After Insertion at Head: ";
    sol.printList(head);
    return 0;
}

/*
Edge Case: Empty List
If the list is empty (head == NULL):
● The new node’s next will be NULL
● The new node itself becomes the head
Works correctly without any special handling
*/

/*
==================================================
Complexity:
    Time: O(1)
    Space: O(1)
==================================================
*/