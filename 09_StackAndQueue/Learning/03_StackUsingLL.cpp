//These implementation might be asked in interview
//Here using Linked List we can define dynamic memory allocation
//this will tell you how inbuilt functions work from inside

/*
Implement the LinkedListStack class: LIFO(Last In first out )
push(int x): Pushes element x onto the stack. 
pop(): Removes and returns the top element of the stack. 
top(): Returns the top element of the stack without removing it. 
isEmpty(): Returns true if the stack is empty, false otherwise.
*/

/*
Algorithm:
    1.Node Structure:
        Define a node with:
        An integer to store data.
        A pointer to the next node.
        A constructor to initialize the data and the next pointer.
    2.Stack Structure:
        Define a stack with:
        A pointer to the top node.
        An integer to keep track of the size.
        A constructor to initialize the top pointer and size.
    3.Push Operation:
        Create a new node with the given data and set the new node's next pointer to the current top node.
        Update the top pointer to the new node and increment the size.
    4.Pop Operation:
        Check if the stack is empty. If it is, return an error value (e.g., -1).
        Store the data of the top node and update the top pointer to the next node.
        Delete the old top node and decrement the size. Return the stored data.
    5.Peek Operation:
        Check if the stack is empty. If it is, return an error value (e.g., -1).
        Otherwise, return the data of the top node.
    6.Is Empty Operation:
        Check if the top pointer is null. Return true if it is, otherwise false.
    7.Size Operation:
        Return the size of the stack.
    8.Print Stack:
        Traverse from the top node and print each node's data until reaching the end of the list.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int val;

    Node(int val1,Node* next1){
        next = next1;
        val = val1;
    }

    Node(int val2){
        val = val2;
        next = nullptr;
    }
};

class LinkedListStack{
    private:
    Node* head; //top of stack
    int size; //size of linked list

    public:
    // Constructor
    LinkedListStack() {
        head = NULL;
        size = 0; 
    }

    //pushes element to stack
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size = size+1;
    }

    // Removes and returns top element
    int pop(){
        //if stack is empty
        if(head==NULL) return -1; // Pop operation cannot be performed
        int value = head->val; // Get the top value
        Node* temp = head; // Store the top temporarily
        head = head->next; // Update top to next node
        delete temp;      // Delete old top node
        size = size-1;   // Decrement size

        return value;  //return value
    }

    //Return top element
    int top(){
        //if stack is empty
        if(head==NULL) return -1; // Pop operation cannot be performed
        return head->val; //return top value

    }

    /* Returns true if the 
   stack is empty, false otherwise*/
   bool isEmpty(){
    return size==0;
   }
};

int main(){
    LinkedListStack stack;
    stack.push(5);
    stack.push(10);
    cout << stack.top() << " ";
    cout << stack.pop() << " ";
    cout << (stack.isEmpty() ? "true" : "false");
    return 0;
}

/*
==================================================================
Time Complexity: O(1) for push, pop, top, and isEmpty operations.
Space Complexity: O(N), where N is the capacity of the stack array.
 In array implmentation space is fixed and lot of space is wasted but 
 in linked list only required space is taken 
==================================================================
*/