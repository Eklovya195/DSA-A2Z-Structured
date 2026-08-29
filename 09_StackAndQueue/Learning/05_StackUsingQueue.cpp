/*
Problem:  225. Implement Stack Using Queue
Platform: Stack & Queue / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/implement-stack-using-queues/description/"
==================================================
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
==================================================
*/

//queue doesn't have inbuilt fxn as top or peek, it has front()
/*
Algorithm:
    1.Data Structure Used: A single queue will be used to store the elements.
    2.Push(x): Insert the element x into the queue. To maintain the stack order:
        Run a loop that iterates size() - 1 times, where size() is the current number of elements in the queue.
        In each iteration, remove the front element and add it back to the rear of the queue. This ensures that the most recently added element is always at the front of the queue.
    3.Pop(): Remove and return the front element of the queue, which corresponds to the top of the stack.
    4.isEmpty(): Return true if the queue is empty, and false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class QueueStack{
    queue<int> q;

    public:
    //pushes element to stack
    void push(int x){         //O(N)
        //get size
        int n = q.size();
        //Add Element
        q.push(x);

        //first add top elements at the back and then pop out all elements before that
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        }
    }

    // Removes and returns top element
    int pop(){
        int value = q.front();
        q.pop();
        return value;

    }

    //Return top element
    int top(){
        return q.front();
    }

    /* Returns true if the 
   stack is empty, false otherwise*/
   bool isEmpty(){
    return q.empty();
   }
};

int main(){
    QueueStack stack;
    stack.push(5);
    stack.push(10);
    cout << stack.top() << " ";
    cout << stack.pop() << " ";
    cout << (stack.isEmpty() ? "true" : "false");
    return 0;
}

/*
==================================================================
Time Complexity:
    Push operation: O(n) (where n is the number of elements in the queue at that time) because every time an element is pushed, all the elements in the queue are popped from the front and pushed in the back again.
    Pop operation: O(1) as constant operations are performed.
    Top operation: O(1) as constant operations are performed.
    IsEmpty operation: O(1) as constant operations are performed.

Space Complexity: O(k) for storing k elements in the queue.
==================================================================
*/