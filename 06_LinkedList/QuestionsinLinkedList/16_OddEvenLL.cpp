/*
Problem: 328. Odd Even Linked List
Problem Statement:Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
    The first node is considered odd, and the second node is even, and so on.
    Note that the relative order inside both the even and odd groups should remain as it was in the input.
    You must solve the problem in O(1) extra space complexity and O(n) time complexity.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/odd-even-linked-list/description/"
==================================================
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
==================================================
*/

//brute force (Using list array)
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

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node* convertArrtoLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* OddEvenList(Node* head){
    if(head == NULL || head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;
    //for odd indexes
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    //for even indexes
    temp = head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    //changing linked list values
    int i = 0;
    temp = head;
    while(temp!=NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArrtoLL(arr);
    head = OddEvenList(head);
    print(head);
    return 0;
}
*/


/*
==================================================
Time Complexity: O(2*N)
Space Complexity: O(N) //using array as external data space
==================================================
*/

//optimal (single pass ,pointer based)

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

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node* convertArrtoLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//this is the code for finding answer
Node* OddEvenList(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while(even!=NULL && even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArrtoLL(arr);
    head = OddEvenList(head);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N) //O(N/2)*2 
Space Complexity: O(1) //(only pointer manipulation, no extra data structures)
==================================================
*/