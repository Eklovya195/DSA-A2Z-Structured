//study from this link
//link:- "https://takeuforward.org/linked-list/linked-list-introduction"

//creating a linkedlist
/*
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node

    // Constructor with data and next
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    // Create first node
    Node* y = new Node(arr[0]);

    // Print memory location of node
    cout << y << '\n';

    // Print data stored in node
    cout << y->data << '\n';

    return 0;
}
*/

//Array to linkedlist
#include <bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    } 
    return head;
}

int checkifPresent(Node* head,int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrtoLL(arr);

    //returning the head of linkedlist
    // cout << head->data;


    //traversal in linkedlist(O(n))
    /*
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    */

    // length of linkedlist (O(n))
    /*
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    cout << cnt;
    */

    //search an element in linked list (O(n) in worst,O(1) in best,O(n/2) in avg)
    /*
    if(checkifPresent(head,3)) cout << "YES";
    else cout << "NO";
    */

    return 0;
}



