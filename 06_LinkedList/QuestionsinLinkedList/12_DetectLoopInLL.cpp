/*
Problem:  141. Linked List Cycle
Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.
    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
    Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    Return true if there is a cycle in the linked list. Otherwise, return false.
Platform: Linked List / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/linked-list-cycle/description/"
==================================================
Input: head = [3,2,0,-4], pos = 1
     3->2->0->-4->2
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
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

bool DetectLoopInLL(Node* head){
    unordered_map<Node*,int> visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited.find(temp)!= visited.end()) return true;
        visited[temp] = 1;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle
    cout << DetectLoopInLL(head);
    return 0;
}
*/

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(N)
==================================================
*/

// Optimal Approach (Tortoise & Hare)
/*
Idea:
Use two pointers:
● slow moves one step
● fast moves two steps
If they meet, a cycle exists.
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

bool DetectLoopInLL(Node* head){
    Node* slow;
    Node* fast;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle
    cout << DetectLoopInLL(head);
    return 0;
}
/*
==================================================
Complexity:
    Time: O(N) approximately
    Space: O(1)
==================================================
*/