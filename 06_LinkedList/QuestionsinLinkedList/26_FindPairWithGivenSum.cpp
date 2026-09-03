/*
Problem:  Find pairs with given sum in doubly linked list
Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.
    You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.
    Find out all the pairs in the doubly linked list with sum equal to 'k'.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172"
==================================================
Input: Linked List: 1 <-> 2 <-> 3 <-> 4 <-> 9 and 'k' = 5
Output: (1, 4) and (2, 3)
Explanation: There are 2 pairs in the linked list having sum 'k' = 5.
==================================================
*/

//Brute Force Approach
/*
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

//function for finding pairs
vector<pair<int,int>> FindPairs(Node* head,int k){
    vector<pair<int,int>> ans;
    if(head == NULL) return ans;
    Node* temp1 = head;

    while(temp1!=NULL){
            Node* temp2 = temp1->next;
            while(temp2!=NULL && temp1->val+temp2->val<=k){
                if(temp1->val+temp2->val==k){
                    ans.push_back({temp1->val,temp2->val});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,9};
    int k = 5;
    Node* head = convertArrToDLL(arr);
    vector<pair<int,int>> ans = FindPairs(head,k);
    for(int i=0;i<ans.size();i++){
        cout << "(" << ans[i].first << ans[i].second << ")";
    }
    return 0;
}
*/


/*
==================================================
Time Complexity: O(N^2)
Space Complexity: O(1)
==================================================
*/

//Optimal Approach

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

//function for finding pairs
vector<pair<int,int>> FindPairs(Node* head,int k){
    vector<pair<int,int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = head;
    //find tail (O(N))
    while(right->next!=NULL){
        right = right->next;
    }

    //O(N)
    while(left->val<right->val){
       if(left->val+right->val==k){
            ans.push_back({left->val,right->val});
            left = left->next;
            right = right->prev;
        }
        else if(left->val+right->val<k){
            left = left->next;
        }else{
            right = right->prev;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,9};
    int k = 5;
    Node* head = convertArrToDLL(arr);
    vector<pair<int,int>> ans = FindPairs(head,k);
    for(int i=0;i<ans.size();i++){
        cout << "(" << ans[i].first << ans[i].second << ")";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(2*N)
Space Complexity: O(1)
==================================================
*/