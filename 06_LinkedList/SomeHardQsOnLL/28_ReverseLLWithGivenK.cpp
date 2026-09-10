/*
Problem:  25: Reverse node in k Groups 
Platform: Linked List / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/reverse-nodes-in-k-group/description/"
==================================================
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int val1,ListNode* next1){
        val = val1;
        next = next1;
    }

    ListNode(int val2){
        val = val2;
        next = nullptr;
    }
};

ListNode* convertArr2LL(vector<int> &arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++){
        ListNode* newNode = new ListNode(arr[i],nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void print(ListNode* head){
    while(head!=nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* findKthNode(ListNode* temp,int k){
    k = k-1;
    while(temp!=nullptr && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseLL(ListNode* temp){
    ListNode* prev = NULL;
    while(temp!=NULL){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head,int k){
    ListNode* temp = head;
    ListNode* prevLast = NULL;

    while(temp!=nullptr){
        ListNode* KthNode = findKthNode(temp,k);
        //if no more k size group is present in linked list
        if(KthNode==NULL){
            if(prevLast) prevLast->next = temp;
            break;
        }

        //create a nextNode
        ListNode* nextNode = KthNode->next;
        //break individual k size group linkedlist
        KthNode->next = NULL;

        //reverse the k sized linked list 
        reverseLL(temp);

        //this is just after first k size group reversal
        if(temp==head){
            head = KthNode;
        }else{
            prevLast->next = KthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 3;
    ListNode* head = convertArr2LL(arr);
    head = reverseKGroup(head,k);
    print(head);
    return 0;
}

/*
==================================================
Complexity:
    Time: O(N)   //basically 2*N
    Space: O(1)
==================================================
*/