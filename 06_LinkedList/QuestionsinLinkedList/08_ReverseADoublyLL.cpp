/*
Problem:  Reverse a Doubly Linked List
Problem Statement: Given the head of a doubly linked list, reverse the list and return the head of the reversed doubly linked list.
Note: Driver code will print the returned list in both forward and backward directions
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1"
==================================================
Input: Linked List:   3 <-> 4 <-> 5
Output: Modified Linked List: 5 <-> 4 <-> 3
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
==================================================
*/

/*
Idea:
Store all node values in a stack.
Traverse the list again and replace node values using the stack (LIFO gives reverse order).
*/

/*
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data2){
        data = data2;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

//Brute Force (swapping Data)
Node* ReverseLL(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    head = ReverseLL(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Complexity:
    Time: O(2*N)
    Space: O(N)
==================================================
*/

//Optimal Approach
/*
Idea:
Reverse the list by swapping next and prev pointers for every node.
While traversing, keep updating the head to the current node.
At the end, the last processed node becomes the new head.

        //Intution of this comes from 
                temp = a;
                a = b;
                b = temp;
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data2){
        data = data2;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node* ReverseLL(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* current = head;
    Node* last = NULL;
    while(current != NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return last->prev;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    head = ReverseLL(head);
    print(head);
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/