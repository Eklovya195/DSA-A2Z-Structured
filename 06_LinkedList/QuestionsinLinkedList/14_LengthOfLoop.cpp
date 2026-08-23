/*
Problem:  Cycle Length in Linked List
Problem Statement:Given the head of a linked list. A linked list contains a cycle if its last node is connected to a previous node. If the given list contains a cycle, return the length of the cycle. Otherwise, return 0.
    Note: Internally, the driver code uses an integer x to represent the position (1-based indexing) of the node to which the last node is connected. If x = 0, it means last node points to null which indicating there is no loop.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/find-length-of-loop/1"
==================================================
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 4
Explanation: There exists a loop in the linked list 2 -> 3 -> 4 -> 5, the length of the loop is 4.
==================================================
*/

//Brute Force (using Hashing)
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
int DetectLoopLength(Node* head){
    //here Node* is pointing toval and int is pointed to timer
    unordered_map<Node*,int> visited;
    Node* temp = head;
    int timer = 1;
    while(temp!=NULL){
        if(visited.find(temp)!=visited.end()) return timer-visited[temp];
        visited[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
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
    cout << DetectLoopLength(head);
    return 0;
}
*/


/*
==================================================
Time Complexity: O(N)*timeComplexity of map (O(1)orO(logn))
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
int DetectLoopLength(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            int cnt = 1;
            fast = fast->next;
            while(slow!=fast){
                cnt++;
                fast = fast->next;
            }
            return cnt;
        }
    }
    return 0;
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
    cout << DetectLoopLength(head);
    return 0;
}

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/