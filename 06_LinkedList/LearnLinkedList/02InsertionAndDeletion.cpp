#include<bits/stdc++.h>
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
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
};

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* convertArrtoLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//remove head
/*
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
*/

/*
Node* removetail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){ 
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
*/

/*
Node* removekthelement(Node* head,int k){
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
*/

/*
Node* removeEle(Node* head,int ele){
    if(head == NULL) return head;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
*/


/*
Node* InsertAtStart(Node* head,int x){
    Node* temp = new Node(x,head);
    return temp;
}
*/

/*
Node* InsertTail(Node* head,int k){
    if(head == NULL){
        return new Node(k);
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(k);
    temp->next = newNode;
    return head;
}
*/

/*
Node* InsertAtKth(Node* head,int k,int value){
    //edge case
    if(head == NULL){
        if(k==1) return new Node(value);
        else return head;
    }
    if(k==1){
        return new Node(value,head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode = new Node(value,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
*/

Node* InsertBeforeValue(Node* head,int k,int value){
    //edge case
    if(head == NULL){
        return NULL;
    }
    if(head->data == value){
        return new Node(k,head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data==value){
            Node* newNode = new Node(k,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrtoLL(arr);

    //dDeletion
    // head = removeHead(head);
    // head = removetail(head);
    // head = removekthelement(head,1); //O(k)
    // head = removeEle(head,15);

    //Insertion
    // head = InsertAtStart(head,6);
    // head = InsertTail(head,6);
    // head = InsertAtKth(head,1,10); (O(n) in worst case,O(1) in best case)
    head = InsertBeforeValue(head,10,7);
    print(head);
    return 0;
}