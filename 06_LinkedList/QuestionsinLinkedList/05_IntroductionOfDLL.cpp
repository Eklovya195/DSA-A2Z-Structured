/*
Problem: Introduction to Doubly Linked List
Problem Statement: You are given an array ‘Arr’ of size ‘N’ consisting of positive integers.
    Your task is to make a doubly linked list from the array and return the head of the linked list.
    Here, the head of the doubly linked list is the first element of the array, and the tail of the doubly linked list is the last element.
    Note:
    A doubly linked list is one in which it is possible to access the next and the previous nodes from a node in the linked list (if they exist).
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413?leftPanelTabValue=PROBLEM"
==================================================
Input: ‘N’ = 4, ‘Arr’ = [4, 2, 5, 1]
Output: 4 2 5 1
Explanation: Doubly Linked List for the array ‘Arr’ = [4, 2, 5, 1] is 4 <-> 2 <-> 5 <-> 1.
==================================================
*/

/*
Before a doubly linked list, recall a singly linked list.
In a singly linked list, each node stores:
● data
● a pointer to the next node
Traversal is possible only in the forward direction. Moving backward is not possible because
there is no reference to the previous node.


Singly Linked List Node Structure
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = new Node(arr[0]);
    cout << head << endl;
    cout << head->data << endl;
    return 0;
}
*/

/*
Doubly Linked List
A doubly linked list improves upon a singly linked list by allowing two-way traversal.
Each node stores:
● data
● pointer to the next node
● pointer to the previous node
Because of the prev pointer, traversal is possible both forward and backward.
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
int main() {
vector<int> arr = {2, 5, 8, 7};
    Node* head = new Node(arr[0]);
    cout << head << endl;
    cout << head->data << endl;
    return 0;
}

/*
Key Difference:
Singly Linked List → only next pointer
Doubly Linked List → both next and prev pointers
*/