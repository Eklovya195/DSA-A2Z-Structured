/*
Problem:  Sort a linked list of 0s, 1s and 2s
Problem Statement: Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. 
    Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1"
==================================================
Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
==================================================
*/

//Brute Force Approach
/*
Idea:
Count the number of 0s, 1s, and 2s, then rebuild the linked list in sorted order by creating new links.
Steps:
1. Traverse the linked list and count occurrences of 0, 1, and 2.
2. Traverse the list again and overwrite links in order: first 0s, then 1s, then 2s.
3. Do not create new data values, only reuse existing nodes.
*/
/*
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data2){
        data = data2;
        next = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* sortBy012(Node* head){
    Node* temp = head;
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while(temp!=NULL){  //O(N)
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){  //O(N)
        if(cnt0){
            temp->data = 0;
            cnt0--;
            
        }
        else if(cnt1){
            temp->data = 1;
            cnt1--;
        }
        else{
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,2,1,2,0,2,2};
    Node* head = convertArr2LL(arr);
    head = sortBy012(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*N) 2 pass solution
Space Complexity: O(1)
==================================================
*/

//Optimal Approach (Link Rearrangement)
/*
Idea:
Create three separate linked lists for 0, 1, and 2 using dummy nodes.
Traverse once, attach each node to its respective list, then merge all three lists.
Steps:
1. Create dummy heads for lists of 0, 1, and 2.
2. Traverse original list and attach nodes to corresponding list.
3. Connect 0 list → 1 list → 2 list.
4. Update head to the start of sorted list.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data2){
        data = data2;
        next = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//solution for gfg here 
Node* sortBy012(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* dummy0 = new Node(-1);
    Node* zero = dummy0;
    Node* dummy1 = new Node(-1);
    Node* one = dummy1;
    Node* dummy2 = new Node(-1);
    Node* two = dummy2;
    while(temp!=NULL){  //O(N)
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }


        temp = temp->next;
    }

    zero->next = (dummy1->next)?dummy1->next:dummy2->next;
    one->next = (dummy2->next);
    two->next = NULL;
    Node* newHead = dummy0->next;
    delete dummy0;
    delete dummy1;
    delete dummy2;
    return newHead;
}

int main(){
    vector<int> arr = {1,2,2,1,2,0,2,2};
    Node* head = convertArr2LL(arr);
    head = sortBy012(head);
    print(head);
    return 0;
}
/*
==================================================
Time Complexity: O(N) 1 pass solution
Space Complexity: O(1)
==================================================
*/
