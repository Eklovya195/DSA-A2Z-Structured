//These implementation might be asked in interview
//Here using array we can only define static memory allocation of fixed sized
//this will tell you how inbuilt functions work from inside

/*
Implement the ArrayStack class: LIFO(Last In first out )
push(int x): Pushes element x onto the stack. 
pop(): Removes and returns the top element of the stack. 
top(): Returns the top element of the stack without removing it. 
isEmpty(): Returns true if the stack is empty, false otherwise.
*/

/*
Algorithm:
    1.Declare an Array of Particular Size: Initialize an array that will hold the elements of the stack. The size of the array is defined when the stack is created.
    2.Define a Variable “Top” and Initialize It as -1: The "top" variable keeps track of the index of the last added element in the stack. Initializing it to -1 indicates that the stack is empty.
    3.Push Operation (push(int x)): To push an element onto the stack:
        Increment the top index by one and insert the element at this position in the array.
        If the stack is full (top is equal to the last index of the array), throw a stack overflow exception.
    4.Pop Operation (pop()): To pop an element from the stack:
        Check if the stack is not empty by ensuring top is not equal to -1. If the stack is empty, throw a stack underflow exception.
        If the stack is not empty, return the element at the top index and then decrement the top index by one.
    5.Top Operation (top()): To get the top element without removing it:
        Check if the stack is not empty. If it is empty, throw an exception.
        If the stack is not empty, return the element at the top index.
    6.IsEmpty Operation (isEmpty()): To check if the stack is empty:
        Check if the top index is -1.
    7.Size Operation (size()): To get the current size of the stack:
        Return top + 1.
*/

#include<bits/stdc++.h>
using namespace std;

class ArrayStack{
    private:
    // Array to hold elements
    int* stackArray;
    // Maximum capacity
    int capacity; 
     // Index of top element  
    int topIndex;

    public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    //pushes element to stack
    void push(int x){
        if(topIndex > capacity-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            //return invalid value
            return -1;
        }
        return stackArray[topIndex--];
    }

    //Return top element
    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            //return invalid value
            return -1;
        }
        return stackArray[topIndex];
    }

    /* Returns true if the 
   stack is empty, false otherwise*/
   bool isEmpty(){
    return topIndex == -1;
   }
};

int main(){
    ArrayStack stack;
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
==================================================================
*/