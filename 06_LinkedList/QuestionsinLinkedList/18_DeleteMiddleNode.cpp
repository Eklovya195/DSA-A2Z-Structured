/*
Problem:  2095. Delete Middle Node of Linked List
Problem Statement: You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
    The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/"
==================================================
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
    The above figure represents the given linked list. The indices of the nodes are written below.
    Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
    We return the new list after removing this node.
==================================================
*/

//Brute Force Approach
/*
Idea:
    Find the length of the list first.
    Middle index = n / 2 (0-based logic → this deletes second middle in even case).
    Traverse again and delete that node.
*/
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

//here is the real solution exist
Node* DeleteMiddleElement(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp!=NULL){  O(N)
        cnt++;
        temp=temp->next;
    }
    temp = head;
    cnt = (cnt/2)-1;
    while(cnt--){       O(N/2)
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1,3,4,7,1,2,6};
    Node* head = convertArr2LL(arr);
    head = DeleteMiddleElement(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N+N/2) approx O(N)
Space Complexity: O(1)
Problem is that this is a 2 pass solution
==================================================
*/

//Optimal Approach (Tortoise & Hare)
/*
Idea:
Use two pointers.
fast moves two steps, slow moves one step.
We stop slow one node before the middle, then delete slow->next.
This automatically deletes:
    ● exact middle for odd length
    ● second middle for even length

Steps:
1. Handle 0 or 1 node case.
2. Initialize slow = head, fast = head->next->next.
    why fast = head->next->next?
    beacuse i want slow one step before middle 
    so skip one step of slow and just move fast first time
3. Move slow by 1 and fast by 2.
4. Delete slow->next.
*/
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

//here is the real solution exist
//one pass solution
Node* DeleteMiddleElement(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1,3,4,7,1,2,6};
    Node* head = convertArr2LL(arr);
    head = DeleteMiddleElement(head);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N/2)
Space Complexity: O(1)
==================================================
*/