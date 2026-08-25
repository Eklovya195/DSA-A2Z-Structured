/*
Problem:  148. Sort List
Problem Statement: Given the head of a linked list, return the list after sorting it in ascending order.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/sort-list/description/"
==================================================
Input: head = [4,2,1,3]
Output: [1,2,3,4]
==================================================
*/

//Brute Force Approach(Bubble Sort Solution type) Don't use this
//first approach came into my mind
/*
Idea:
    1.find the length of linked list
    2.traverse each time through each data in linkedlist 
    3.swap if next->data < current->data
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
Node* SortLL(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;

    Node* temp = head;
    int lengthofll = 0;
    while(temp!=NULL){
        lengthofll++;
        temp = temp->next;
    }

    for(int i=0;i<lengthofll;i++){
        temp = head;
        while(temp->next!=NULL){
            if(temp->next->data<temp->data){
                int some = temp->data;
                temp->data = temp->next->data;
                temp->next->data = some;
            }
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr = {4,2,1,3};
    Node* head = convertArr2LL(arr);
    head = SortLL(head);
    print(head);
    return 0;
}
*/


/*
==================================================
Time Complexity: O(N^2)
Space Complexity: O(1)
==================================================
*/

//Brute Force approach 2
/*
Idea:
    Store all node values in an array, sort the array,
    then overwrite the linked list with sorted values.
Steps:
1. Traverse the linked list and store values in an array.
2. Sort the array
3. Traverse the linked list again and replace node values from the sorted array
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
Node* SortLL(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    vector<int> arr;
    Node* temp = head;

    //O(N)
    while(temp!=NULL){    
        arr.push_back(temp->data);
        temp = temp->next;
    }
    //sort the array using Merge or Quick O(NlogN)
    sort(arr.begin(),arr.end());

    temp = head;
    int i =0;
    //O(N)
    while(temp!=NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {4,2,1,3};
    Node* head = convertArr2LL(arr);
    head = SortLL(head);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) + O(NologN) + O(N) == O(NlogN)
Space Complexity: O(N) 
space is used as array
==================================================
*/

//Optimal Approach (Merge Sort on Linked List)
/*
Idea:
Linked lists are best sorted using Merge Sort because it does not require random access.

Steps:
1. If list has 0 or 1 node, it is already sorted.
2. Find the middle using slow & fast pointers.
3. Split the list into two halves.
4. Recursively sort both halves.
5. Merge the two sorted halves.
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

//Merging 2 sorted linked list
Node* mergeTwoLists(Node* list1,Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1 != NULL && list2!=NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummyNode->next;
}

//finding the middle element of linkedlist
Node* findMiddle(Node* head){
    Node* slow = head;
    //i want middle to stop at middle 1
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

//sorting of linked list
Node* SortLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddle(head); //O(N/2)
    Node* lefthead = head;
    Node* righthead = middle->next;
    middle->next = NULL;

    lefthead = SortLL(lefthead);
    righthead = SortLL(righthead);
    
    return mergeTwoLists(lefthead,righthead); //O(N)
}

int main(){
    vector<int> arr = {4,2,1,3};
    Node* head = convertArr2LL(arr);
    head = SortLL(head);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: logN*O(N/2+N) == O(NlogN)
Space Complexity: O(1) (excluding recursion stack)
==================================================
*/