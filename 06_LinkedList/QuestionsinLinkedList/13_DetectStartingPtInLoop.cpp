/*
Problem:  142. Linked List Cycle ||
Problem Statement:Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle.
    Note that pos is not passed as a parameter.
    Do not modify the linked list.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/linked-list-cycle-ii/description/"
==================================================
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
==================================================
*/

//hashing used solution
//Idea:Keep track of visited nodes.
// If a node is visited again, a cycle exists.
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

//the first node that is visited again during trversal is the starting node of loop
Node* DetectLoopInLL(Node* head){
    unordered_map<Node*,int> visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited.find(temp)!=visited.end()) return temp;
        visited[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* head = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(0);
    Node* n4 = new Node(-4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle
    Node* ans =  DetectLoopInLL(head);
    if(ans) cout << ans->data;
    else cout << NULL;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(N)
==================================================
*/

//optimal Approach(Tortoise & Hare)
/*
Idea:
First detect the cycle using slow and fast pointers.
After they meet, reset one pointer to head.
Move both one step at a time — the meeting point is the start of the loop.
*/
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

//the first node that is visited again during trversal is the starting node of loop
Node* DetectLoopInLL(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    Node* head = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(0);
    Node* n4 = new Node(-4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle
    Node* ans =  DetectLoopInLL(head);
    if(ans) cout << ans->data;
    else cout << NULL;
    return 0;
}

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/