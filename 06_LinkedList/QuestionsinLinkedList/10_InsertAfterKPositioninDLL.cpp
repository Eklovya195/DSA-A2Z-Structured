/*
Problem: Insertion in a Doubly Linked List
Problem Statement: Given the head of a doubly-linked list, a position p, and an integer x.
    Insert a new node with value x at the position just after pth node (0-based indexing) in the doubly linked list and return the head of the modified list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1"
==================================================
Input: p = 2, x = 6
        2 <-> 4 <-> 5
Output: 2 <-> 4 <-> 5 <-> 6
Explanation: Insert a node of value 6 after the 2nd node.
==================================================
*/

//* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {
        Node* newNode = new Node(x);
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL){
            if(cnt == p){
                if(temp->next != NULL){
                    Node* front = temp->next;
                    newNode->next = front;
                    newNode->prev = temp;
                    temp->next = newNode;
                    front->prev = newNode;
                }else{
                    temp->next = newNode;
                    newNode->prev = temp;
                    newNode->next = nullptr;
                }
            }
            temp = temp->next;
            cnt++;
        }
        return head;
    }
};

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/