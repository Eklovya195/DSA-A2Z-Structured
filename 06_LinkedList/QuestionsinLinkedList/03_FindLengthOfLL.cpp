/*
Problem: Find Length of Linked List
Problem Statement: Given head of a singly linked list. Find the length of the linked list, where length is defined as the number of nodes in the linked list
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1"
==================================================
Input: head: 1 -> 2 -> 3 -> 4 -> 5
Output: 5
==================================================
*/

/*
Key Idea
A linked list is made up of nodes connected using next pointers.
To find its length:
● Start from the head
● Move node by node using next
● Count how many nodes you visit until you reach NULL

Algorithm (Step-by-Step)
1. Initialize a counter count = 0
2. Create a temporary pointer temp and point it to head
3. Traverse the list while temp is not NULL
○ Increment count
○ Move temp to temp->next
4. When traversal ends, return count

Dry Run
Linked List
head → 10 → 20 → 30 → NULL
Traversal
temp points
to
coun
10 1
20 2
30 3
NULL stop
*/

#include <bits/stdc++.h>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Solution class containing the method to find length
class Solution {
public:
    // Function to find the length of the linked list
    int lengthOfLinkedList(Node* head) {
        // Initialize counter to 0
        int count = 0;

        // Initialize a temporary pointer to head
        Node* temp = head;

        // Traverse the linked list
        while (temp != nullptr) {
            // Increment count for each node
            count++;

            // Move to the next node
            temp = temp->next;
        }

        // Return the total count
        return count;
    }
};

int main() {
    // Creating a sample linked list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Create Solution object
    Solution obj;

    // Find and print the length of linked list
    cout << "Length of Linked List: "
         << obj.lengthOfLinkedList(head) << endl;

    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/