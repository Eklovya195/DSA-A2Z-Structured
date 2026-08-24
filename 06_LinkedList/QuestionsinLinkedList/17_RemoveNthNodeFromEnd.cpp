/*
Problem:  19. Remove Nth node from End
Problem Statement: Given the head of a linked list, remove the nth node from the end of the list and return its head.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/"
==================================================
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
==================================================
*/

//My tought process goes like this after seeing this question for first time
//But there are some edge cases problem
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

//Remove Nth element from end
Node* RemoveNthElementFromEnd(Node* head,int n){
    if(head==NULL) return NULL;
    Node* temp = ReverseLL(head);
    // Remove first node from reversed list
    if (n == 1) {
        Node* newHead = temp->next;
        delete temp;

        return ReverseLL(newHead);
    }
    Node* prev = NULL;
    int k = 1;
    while(k!=n){
        prev = temp;
        temp = temp->next;
        k++;
    }
    prev->next = temp->next;
    delete temp;
    ReverseLL(prev);
    return head;
}

int main(){
    vector<int> arr = {1,2};
    int n = 2;
    Node* head = convertArr2LL(arr);
    head = RemoveNthElementFromEnd(head,n);
    print(head);
    return 0;
}
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

//Remove Nth element from end
Node* RemoveNthElementFromEnd(Node* head,int n){
    int lengthOfLL = 0;
    Node* temp = head;
    while(temp!=NULL){
        lengthOfLL++;
        temp = temp->next;
    }
    if(lengthOfLL==n){
        Node* newHead = head->next;
        free(head);
        return newHead;
    }
    int ans = lengthOfLL-n;
    temp = head;
    while(temp!=NULL){
        ans--;
        if(ans==0) break;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
    return head; 
}

int main(){
    vector<int> arr = {1,2,3};
    int n = 2;
    Node* head = convertArr2LL(arr);
    head = RemoveNthElementFromEnd(head,n);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*lenOfLL)
Space Complexity: O(1)
==================================================
*/


//Optimal Approach(Using 2 pointers)
/*
Instead of counting length, use two pointers.
Keep a gap of N nodes between fast and slow.
● Move fast ahead by N steps
● Move both fast and slow together
● When fast reaches NULL, slow is just before the node to delete
● Bypass that node
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

//Remove Nth element from end
Node* RemoveNthElementFromEnd(Node* head,int n){
    Node* slow = head;
    Node* fast = head;
    for(int i=0;i<n;i++) fast = fast->next;
    if(fast==NULL) return head->next;
    while(fast->next!=NULL){
        slow=slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main(){
    vector<int> arr = {1,2,3};
    int n = 2;
    Node* head = convertArr2LL(arr);
    head = RemoveNthElementFromEnd(head,n);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N) == O(lengthofLL)
Space Complexity: O(1)
==================================================
*/