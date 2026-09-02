/*
Problem:  Delete All Occurrences in DLL
Problem Statement:  You are given the head of a doubly Linked List and a key x . Your task is to delete all occurrences of the given key x if it is present and return the new DLL.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1"
==================================================
Input: 2<->2<->10<->8<->4<->2<->5<->2, x = 2
Output:  10<->8<->4<->5
==================================================
*/

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
Node* DeleteAllOccurrence(Node* head,int x){
    Node* temp = head;
    
    while(temp!=NULL){
        if(temp->val == x){
            if(temp == head){
                head = head->next;
            }
            Node* prevNode = temp->prev;
            Node* frontNode = temp->next;
            //here both if checks are necessary(must)
            //if remove there will be nullpointer exception
            if(prevNode) prevNode->next = frontNode;
            if(frontNode) frontNode->prev = prevNode;
            delete temp;
            temp = frontNode;
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {2,2,10,8,4,2,5,2};
    int x = 2;
    Node* head = convertArrToDLL(arr);
    head = DeleteAllOccurrence(head,x);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/