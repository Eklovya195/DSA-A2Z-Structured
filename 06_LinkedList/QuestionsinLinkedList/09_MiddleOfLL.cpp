/*
Problem:   Middle of Linked List
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/middle-of-the-linked-list/description/"
==================================================
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
==================================================
*/

//Brute Force(Works on Leetcode)
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

Node* MiddleOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    cnt = (cnt/2) + 1;
    int cnt2 = 1;
    temp = head;
    while(cnt2 != cnt){
        temp = temp->next;
        cnt2++;
    }
    return temp;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArr2DLL(arr);
    head = MiddleOfLL(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Complexity:
    Time: O(N+N/2)
    Space: O(N)
==================================================
*/

//Optimal Approach(Tortoise Hare Method)
/*
Idea:
Use two pointers:
slow moves 1 step, fast moves 2 steps.
When fast reaches the end, slow is at the middle.
For even length, this automatically gives the second middle.

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

Node* MiddleOfLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = convertArr2DLL(arr);
    head = MiddleOfLL(head);
    print(head);
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N/2)
    Space: O(1)
==================================================
*/