/*
Problem:  61. Rotate List
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/rotate-list/description/?utm=codolio"
==================================================
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* tail = head;
        int len = 1;
        //O(n)
        while(tail->next!=NULL){
            tail = tail->next;
            len++;
        }
        if(k%len == 0) return head;
        tail->next = head;
        //if k>len reduce k
        k = k%len;
        int move = len-k;
        //O(n)
        for(int i=1;i<move;i++){
            head = head->next;
        }
        ListNode* newHead = head->next;
        head->next = NULL;
        return newHead;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 2;
    ListNode* head = convertArr2LL(arr);
    Solution obj;
    head = obj.rotateRight(head,k);
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