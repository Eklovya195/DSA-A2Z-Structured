/*
Problem:  206: Reverse a Linked List
Problem Statement: Given the head of a singly linked list, reverse the list, and return the reversed list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/reverse-linked-list/description/"
==================================================
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
==================================================
*/

//Brute Force Approach
/*

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data2){
        data = data2;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
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
    Node* head = convertArr2LL(arr);
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

//Ooptimal Approach (Iterative Approach)
//Idea:Reverse links by changing next pointers using three pointers.

/*
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data2){
        data = data2;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
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
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = ReverseLL(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/

//Recursive Approach
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data2){
        data = data2;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
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
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = new reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = ReverseLL(head);
    print(head);
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(N) recursive stack 
==================================================
*/