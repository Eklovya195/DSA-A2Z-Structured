/*
Problem:  Add one to a number represented as Linked List
Problem Statement: You're given a positive integer represented in the form of a singly linked-list of digits. The length of the number is 'n'.
    Add 1 to the number, i.e., increment the given number by one.
    The digits are stored such that the most significant digit is at the head of the linked list and the least significant digit is at the tail of the linked list.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557"
==================================================
Input: 9->9
Output: 1->0->0
==================================================
*/

//Brute Force Approach (Iterative approach)
/*
Algorithm:
    ● Reverse the linked list.
    ● Add 1 starting from the head (least significant digit).
    ● Propagate carry if needed.
    ● If carry remains at the end, create a new node.
    ● Reverse the list again and return head.
*/

/*
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

//Printing the final linked list
void print(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//convert array to linked list
Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; 
    }
    return head;
}

//Reversing the linked list
Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
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

//this function gives final linked list
Node* FinalList(Node* head){
    head = reverseLL(head);  //O(N)
    int carry = 1;
    Node* temp = head;
    while(temp!=NULL){       //O(N)
        temp->val = temp->val+carry;
        if(temp->val < 10){
            carry = 0;
            break;
        }else{
            temp->val = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry==1){
        Node* newNode = new Node(carry);
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    head = reverseLL(head); //O(N)
    return head;
}

int main(){
    vector<int> a = {9,9,9};
    Node* head1 = convertArr2LL(a);
    Node* head = FinalList(head1);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(3*N)
Space Complexity: O(1)
==================================================
*/

//Recursive Approach (Because recursion has backtracking)
/*
Algorithm:
    ● Recursively go to the last node.
    ● Add 1 and propagate carry backwards(Back Propagation).
    ● If carry remains after head, create a new node at front.
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

//Printing the final linked list
void print(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

//convert array to linked list
Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; 
    }
    return head;
}

int helper(Node* temp){
    if(temp==NULL) return 1;
    int carry = helper(temp->next);
    //backtracking starts here
    temp->val = temp->val+carry;
    if(temp->val < 10){
        return 0;
    }
    temp->val = 0;
    return 1;
}

//this function gives final linked list
Node* FinalList(Node* head){
    Node* temp = head;
    //this is final carry if need to add new node
    int carry = helper(temp);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main(){
    vector<int> a = {8,9,9};
    Node* head1 = convertArr2LL(a);
    Node* head = FinalList(head1);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(N) recursive stack
==================================================
*/

/*
    Recrsive takes less time but take space of N
    while iterative approach takes more time but less space
*/