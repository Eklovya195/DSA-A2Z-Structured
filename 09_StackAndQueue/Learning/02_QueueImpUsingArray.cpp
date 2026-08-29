//These implementation might be asked in interview
//Here using array we can only define static memory allocation of fixed sized
/*
Implement the ArrayQueue class: FIFO(First In First Out)
void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise
*/

/*
Algorithm:
    1.Declare an Array of a Particular Size: Declare an array to store the elements of the queue. 
        The size of this array is determined when the queue is initialized.
    2.Define Variables:
        start: Tracks the index of the front element.
        end: Tracks the index of the last element.
        size: Keeps the current number of elements in the queue.
        capacity: The maximum number of elements the queue can hold.
    3.Push Operation (push(int x)):
        Check if the queue is full by comparing size with capacity. If not full:
        Increment the end using modular arithmetic to wrap around if necessary.
        Insert the element at the rear index.
        Increment the size.
    4.Pop Operation (pop()):
        Check if the queue is empty by comparing size with 0. If not empty:
        Return the element at the front index.
        Increment the start using modular arithmetic to wrap around if necessary.
        Decrement the size.
    5.Peek Operation (peek()):
        Check if the queue is empty. If not empty, return the element at the front index.
    6.IsEmpty Operation (isEmpty()):
        Check if size is 0 to determine if the queue is empty.
*/

#include<bits/stdc++.h>
using namespace std;

class ArrayQueue{
    private:
    // Array to store queue elements
    int* arr;
    // Indices for start and end of the queue
    int start, end;
    // Current size and maximum size of the queue
    int currSize, maxSize;

    public:
    // Constructor
    ArrayQueue() {
        maxSize = 10;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    //pushes element to queue
    void push(int x){
        //check if queue is full
        if(currSize == maxSize){
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }

        //if queue is empty
        if(end == -1){
            start = 0;
            end = 0;
        }else{
            // Circular increment of end
            end = (end+1)%maxSize;
        }

        arr[end] = x;
        currSize++;
    }

    // Method to pop an element from the queue
    int pop(){
        //check if queue is empty
        if(start == -1){
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];

        // If the queue has only one element, reset start and end
        if(currSize == 1){
            start = -1;
            end = -1;
        }else{
            // Circular increment of start
            start = (start + 1)%maxSize;
        }

        currSize--;
        return popped;
    }

    //Method to get the front element of the queue
    int peek(){
        if(start == -1){
            cout << "queue is empty" << endl;
            exit(1);
        }
        
        return arr[start];
    }

    /* Returns true if the 
   queue is empty, false otherwise*/
   bool isEmpty(){
    return (currSize == 0);
   }
};

int main(){
    ArrayQueue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.peek() << " ";
    cout << queue.pop() << " ";
    cout << (queue.isEmpty() ? "true" : "false");
    return 0;
}

/*
==================================================================
Time Complexity: O(1) for push, pop, peek, and isEmpty operations.
Space Complexity: O(N), where N is the fixed size of the array used for the queue.
==================================================================
*/