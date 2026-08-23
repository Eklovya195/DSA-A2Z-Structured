/*
Problem: 234. Palindrome Linked List
Problem Statement: Given the head of a singly linked list, return true if it is a palindrome or false otherwise
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/palindrome-linked-list/description/"
==================================================
Input: head = [1,2,2,1]
Output: true
==================================================
*/

//brute force (Using Stack)
/*
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    public:
    Node(int data2,Node* next2){
        data = data2;
        next = next2;
    }
};

//check if palindrome or not
bool CheckPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        temp=temp->next;
        st.pop();
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(2);
    Node* n4 = new Node(0);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL; // cycle
    cout << boolalpha << CheckPalindrome(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*N)
Space Complexity: O(N) //using stack as extra space
==================================================
*/

//Optimal Approach (Reverse the second half)
//Tortoise & Hare Approach
/*
Idea:
    Find the middle using slow and fast pointers.
    Reverse the second half of the list.
    Compare first half and second half node by node.
    Restore the list by reversing back.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    public:
    Node(int data2,Node* next2){
        data = data2;
        next = next2;
    }
};

Node* reverse(Node* newHead){
    if(newHead==NULL || newHead->next == NULL) return newHead;
    Node* temp = newHead;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//check if palindrome or not
bool CheckPalindrome(Node* head){
    if(head==NULL || head->next == NULL) return true;
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverse(slow->next);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(slow->next);
    return true;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(2);
    Node* n4 = new Node(0);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL; // cycle
    cout << boolalpha << CheckPalindrome(head);
    return 0;
}

/*
==================================================
Time Complexity: O(2*N) beacuse of 4*O(n/2)
Space Complexity: O(1) 
==================================================
*/