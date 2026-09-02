/*
Problem:  Remove Duplicates from sorted Doubly Linked list
Problem Statement:  Given a doubly linked list of n nodes sorted by values, remove duplicate nodes present in the linked list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1"
==================================================
Input: head: 1<->1<->1<->2<->3<->4
Output: 1<->2<->3<->4
Explanation: Only the first occurance of node with value 1 is retained along with other distinct values. 
==================================================
*/

//This was my approach and this is also solved question but striver write clear approach 
/*
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val1,Node* next1,Node* prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }
    
    Node(int val2){
        val = val2;
        next = nullptr;
        prev = nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrToDLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//function to delete all occurrences
Node* RemoveDuplicates(Node* head){
    Node* temp = head->next;
    Node* back = head;

    while(temp!=NULL){
        Node* front = temp->next;
        if(temp->val == back->val){    
            back->next = front;
            if(front) front->prev = back;
            delete temp;
            temp = front;
        }
        else{
            back = temp;
            temp = front;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,2,3,3,4,4};
    Node* head = convertArrToDLL(arr);
    head = RemoveDuplicates(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/

//Striver Approach of cleaner code and simple way 
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val1,Node* next1,Node* prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }
    
    Node(int val2){
        val = val2;
        next = nullptr;
        prev = nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrToDLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//function to delete all occurrences
Node* RemoveDuplicates(Node* head){
    Node* temp = head;
    
    while(temp!=NULL && temp->next!=NULL){
        Node* nextNode = temp->next;
        while(nextNode!=NULL && nextNode->val == temp->val){
            Node* delNode = nextNode;
            nextNode = nextNode->next;
            delete delNode;
        }
        temp->next = nextNode;
        if(nextNode) nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,2,3,3,4,4};
    Node* head = convertArrToDLL(arr);
    head = RemoveDuplicates(head);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N) if x it goes for outer loop then n-x for inner loop
Space Complexity: O(1)
==================================================
*/