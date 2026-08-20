#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data2){
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};

void print(Node* head){
    while(head != NULL){
        cout << head->data << " " ;
        head = head->next;
    }
    cout << endl;
}

Node* convertArr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//deletion
/*
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    free(prev);
    return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    temp->back = nullptr;
    prev->next = nullptr;
    free(temp);
    return head;
}
Node* deleteKth(Node* head,int k){
    if(head == NULL) return NULL;
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev==NULL && front==NULL){
        return NULL;
    }else if(prev==NULL){
        return deleteHead(head);
    }else if(front==NULL){
        return deleteTail(head);
    }else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    return head;
}
void deleteEl(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
}
*/


//Insertion Before
/*
Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}
Node* insertionBeforeTail(Node* head,int val){
    if(head->next == NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newNode = new Node(val,tail,tail->back);
    tail->back->next = newNode;
    tail->back = newNode;
    return head;
}
Node* insertBeforeKth(Node* head,int k,int val){
    Node* temp = head;
    if(k==1){
        Node* newNode = new Node(val,head,nullptr);
        head->back = newNode;
        return newNode;
        //or just use insertbeforehead() function
    }
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            Node* prev = temp->back;
            Node* newNode = new Node(val,temp,prev);
            temp->back = newNode;
            prev->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}
void insertBeforeNode(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    node->back = newNode;
    prev->next = newNode;
}
*/



int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    //deletion
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKth(head,4);
    //never asked about head
    // deleteEl(head->next);

    //Insertion Before
    // head = insertBeforeHead(head,15);
    // head = insertionBeforeTail(head,15);
    // head = insertBeforeKth(head,4,15);
    //never given head otherwise head will change
    insertBeforeNode(head->next->next,15);
    print(head);
    return 0;
}