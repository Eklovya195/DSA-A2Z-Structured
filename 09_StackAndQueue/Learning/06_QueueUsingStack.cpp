/*
Problem:  232. Implement Queue Using Stack 
Platform: Stack & Queue / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/implement-queue-using-stacks/description/"
==================================================
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
==================================================
*/


//Approach 1: (Use 2*n for push,if we have more push operation then this is costly)
/*
Algorithm:
   1.Use Two Stacks: Maintain two stacks, stack1 and stack2.
    2.Push Operation:
        Transfer all elements from stack1 to stack2.
        Add the new element to stack1.
        Transfer all elements back from stack2 to stack1.
        This ensures the new element is always at the front for the next pop operation.
    2.Pop Operation: Remove and return the top element from stack1.
    3.Top Operation: Return the top element of stack1 without removing it.
    4.Size Operation: Return the size of stack1.
*/

/*
#include<bits/stdc++.h>
using namespace std;

class StackQueue{
    stack<int> st1,st2;

    public:
    // Empty Constructor
    StackQueue () {
        
    }

    //pushes element to stack
    void push(int x){         //O(2*N)
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
         // Insert the desired element
        st1.push(x);

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    // Method to pop element from the queue
    int pop(){
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }

        // Get the top element
        int value = st1.top();
        st1.pop();  // Perform the pop operation
        return value;  // Return the popped value
    }

    //Return top element
    int peek(){
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }

        // Return the top element
        return st1.top();
    }

    //Returns true if the stack is empty, false otherwise
   bool isEmpty(){
    return st1.empty();
   }
};

int main(){
    StackQueue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.peek() << " ";
    cout << queue.pop() << " ";
    cout << (queue.isEmpty() ? "true" : "false");
    return 0;
}
*/

/*
==================================================================
Time Complexity: O(2*n) for push operation, O(1) for pop and peek operations.
Space Complexity: O(n) for storing elements in the stacks.
==================================================================
*/


//Approach 2: (optimising push operation and taking pop and top much time)
/*
Algorithm:
    1.Use Two Stacks: Maintain two stacks, inputStack and outputStack.
    2.Push Operation:
        Add the element to inputStack. This operation is efficient and always takes O(1) time.
    3.Pop Operation:
        If the outputStack is empty, move all elements from inputStack to outputStack. This reversal of order ensures that the oldest element is on top of the outputStack.
        Remove and return the top element from outputStack. This represents the oldest element in the queue.
    4.Top Operation:
        If the outputStack is empty, move all elements from inputStack to outputStack to access the oldest element.
        Return the top element of outputStack without removing it. This gives the element that has been in the queue the longest.
    5.Size Operation:
    Return the sum of the sizes of both stacks. This total gives the number of elements currently in the queue.
*/

#include<bits/stdc++.h>
using namespace std;

class StackQueue{
    stack<int> input,output;

    public:
    // Empty Constructor
    StackQueue () {
        
    }

    //pushes element to stack
    void push(int x){         
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop(){
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    int peek(){
        // Shift input to output if output is empty
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

   // Returns true if the queue is empty, false otherwise
   bool isEmpty(){
    return input.empty() && output.empty();
   }
};

int main(){
    StackQueue queue;
    queue.push(5);
    queue.push(10);
    cout << queue.peek() << " ";
    cout << queue.pop() << " ";
    cout << (queue.isEmpty() ? "true" : "false");
    return 0;
}

/*
==================================================================
Time Complexity: O(1) for push operation, 
    O(n) for pop and peek operations in the worst case when elements need to be shifted.
Space Complexity: O(n) for storing elements in the two stacks.
==================================================================
*/