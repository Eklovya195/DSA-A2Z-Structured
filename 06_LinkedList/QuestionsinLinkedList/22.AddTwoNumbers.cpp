/*
Problem:  2.Add Two Numbers
Problem Statement: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/add-two-numbers/description/"
==================================================
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
==================================================
*/

//Brute Force(This was my first approach)
/*
Idea:
    first convert each linked list into a number and reverse the numbers
    add those two numbers
    take rem(which is last element) and add it new linked list 
    create a new linked list
    return head of new linked list
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

//convert linked list into a reverse number
int ConvertToNo(Node* head){
   int ans = 0;
   Node* temp = head;
   while(temp!=NULL){
        ans = (ans*10)+temp->val;
        temp = temp->next;
   }
   int no = 0;
   while(ans!=0){
    int rem = ans%10;
    no = no*10+rem;
    ans = ans/10;
   }
   return no;
}

//this function gives final linked list
Node* FinalList(int sum){
    int rem = sum%10;
    Node* head = new Node(rem);
    Node* temp = head;
    sum = sum/10;
    while(sum!=0){
        rem = sum%10;
        Node* newNode = new Node(rem);
        temp->next = newNode;
        temp = newNode;
        sum = sum / 10;
    }
    return head;
}

int main(){
    vector<int> a1 = {3,5};
    vector<int> a2 = {4,5,9,9};

    Node* head1 = convertArr2LL(a1);
    Node* head2 = convertArr2LL(a2);

    int no1 = ConvertToNo(head1); //O(N1)
    int no2 = ConvertToNo(head2); //O(N2)
    int sum = no1+no2;
    Node* head = FinalList(sum);
    print(head);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N1+N2) //N1 is size of 1st linked list
                          //N2 is size of 2nd Linked list
                          //D is size of finallinked list
Space Complexity: O(N1+N2+D)
                  //but the auxilary space is nothing 
                  so O(1)
==================================================
*/

/*
Algorithm:
    ● Create a dummy node to simplify result list creation.
    ● Use a temporary pointer starting at the dummy.
    ● Maintain a carry initialized to 0.
    ● Traverse both linked lists while at least one list has nodes left or carry is non-zero.
    ● At each step:
    ○ Add current digits from both lists (if present) and the carry.
    ○ Update carry as sum / 10.
    ○ Create a new node with value sum % 10 and attach it.
    ● Return dummy->next as the head of the result list.
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

//this function gives final linked list
Node* FinalList(Node* head1,Node* head2){
    Node* dummyNode = new Node(-1);
    Node* t1 = head1;
    Node* t2 = head2;
    Node* curr = dummyNode;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1) sum = sum+t1->val;
        if(t2) sum = sum+t2->val;

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main(){
    vector<int> a1 = {3,5};
    vector<int> a2 = {4,5,9,9};

    Node* head1 = convertArr2LL(a1);
    Node* head2 = convertArr2LL(a2);
    Node* head = FinalList(head1,head2);
    print(head);
    return 0;
}

/*
==================================================
Time Complexity: O(max(N1,N2)) //N1 is size of 1st linked list
                          //N2 is size of 2nd Linked list
Space Complexity: O(max(N1,N2))
                  //but the auxilary space is nothing 
                  so O(1)
==================================================
*/