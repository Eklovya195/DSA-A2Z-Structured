//These implementation might be asked in interview
//Here using linked list we can define dynamic memory allocation
//this will tell you how inbuilt functions work from inside

/*
Algorithm:
    1.Node Structure: Define a node that holds data and a pointer to the next node. This node acts as the building block of the linked list used in the queue.
    2.Queue Initialization: Initialize the queue with pointers to both the front and rear of the queue. Set these pointers to null initially, indicating an empty queue. Also, maintain a counter to track the number of elements in the queue.
    3.Enqueue Operation (Adding an Element):
        Create a new node with the given data.
        If the queue is empty, set both the front and rear pointers to this new node.
        If the queue is not empty, link the current rear node to the new node and update the rear pointer to point to the new node.
    4.Dequeue Operation (Removing an Element):
        Check if the queue is empty. If it is, return an appropriate message or handle the empty condition.
        If the queue is not empty, move the front pointer to the next node and delete the old front node.
        If the queue becomes empty after removal, set the rear pointer to null.
    5.Peek Operation (Accessing the Front Element):
        Check if the queue is empty. If it is, return an appropriate message or handle the empty condition.
        If the queue is not empty, return the data of the front node without removing it.
    6.Size Operation: Return the value of the counter tracking the number of elements in the queue.
        IsEmpty Operation: Check if the front pointer is null. If it is, the queue is empty; otherwise, it is not.
*/

#include<bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int val;
    Node *next;
    Node(int d1,Node* next1) {
        val = d1;
        next = next1;
    }
    Node(int d2) {
        val = d2;
        next = NULL;
    }
};

//Structure to represent stack
class LinkedListQueue{
    private:
    //initialize start and end node
    Node* start; 
    Node* end;
    int size; //size of linked list

    public:
    // Constructor
    LinkedListQueue() {
        start = end = NULL;
        size = 0;
    }

    //pushes element to queue
    void push(int x){
        Node* newNode = new Node(x);
        if(start==NULL){
            start = newNode;
            end = newNode;
        }else{
            end->next = newNode;// Updating the pointers
            end = newNode; // Updating the end
        }
        size++; //increment size of linkedlist
    }

    // Method to pop an element from the queue
    int pop(){
        //if stack is empty
        if(start == NULL) return -1; //pop operation can not be performed

        int popped = start->val; //popped out front element
        Node* temp = start; //take temp delete one
        start = start->next; //move start to next
        delete temp; //delete temp

        return popped; //retunr the popped element
    }

    //Method to get the front element of the queue
    int peek(){
        //if stack is empty
        if(start == NULL) return -1; //Top element can not be accessed
        return start->val;
    }

    /* Returns true if the 
   queue is empty, false otherwise*/
   bool isEmpty(){
    return (size == 0);
   }
};

int main(){
    LinkedListQueue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.peek() << " ";
    cout << queue.pop() << " ";
    cout << (queue.isEmpty() ? "true" : "false");
    return 0;
}

/*
==================================================================
Time Complexity: O(1) for all operations (push, pop, peek, isEmpty) 
since they involve constant time operations like pointer manipulation and value retrieval.
Space Complexity: O(n) where n is the number of elements in the queue, 
as we are using a linked list to store the elements. Each element requires space for a node structure.
==================================================================
*/