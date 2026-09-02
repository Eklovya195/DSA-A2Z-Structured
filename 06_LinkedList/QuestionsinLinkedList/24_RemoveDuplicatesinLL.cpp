/*
Problem:  83. Remove Duplicates from Linked List
Problem Statement:  Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/"
==================================================
Input: head = [1,1,2]
Output: [1,2]
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int val1,Node* next1){
        val = val1;
        next = next1;
    }
    
    Node(int val2){
        val = val2;
        next = nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrToLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//function to remove duplicates
Node* removeDuplicates(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    Node* temp = head;
    Node* front = temp->next;
    while(front!=NULL){
        if(front->val == temp->val){
            front = front->next;
            temp->next = front; 
        }else{
            temp = front;
            front = front->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {1};
    Node* head = convertArrToLL(arr);
    head = removeDuplicates(head);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/