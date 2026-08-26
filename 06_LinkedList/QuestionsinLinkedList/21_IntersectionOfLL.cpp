/*
Problem:  160. Intersection of two linked list
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
Platform: Linked List / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/intersection-of-two-linked-lists/description/"
==================================================
Input:listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
Output: Intersected at '8'
==================================================
*/

//Brute Force (Using hashing)
/*
Idea:
Store node addresses of list1, then search while traversing list2.
Algorithm:
● Traverse list1, store each node in hash map.
● Traverse list2, if node exists in set → intersection
*/

/*
Node* intersectionPresent(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    map<Node*,int> mp;
    Node* temp = head1;
    while(temp!=NULL){
        mp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;
    while(temp!=NULL){
        if(mp.find(temp) != mp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
*/

/*
==================================================
Time Complexity: O(N1*(O(hashing)))+O(N2*O(hashing))
Space Complexity: O(N1) or O(N2)
  //depends on which list you store in map
==================================================
*/

//Better Approach(Length Difference)
/*
Idea:
Align both lists at same remaining length, then move together.

Algorithm:
● Find lengths of both lists.
● Move longer list by |len1 - len2|.
● Move both pointers together until they meet.
*/

/*
Node* intersectionPresent(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int n1= 0;
    int n2 = 0;

    while(temp1!=NULL){   //O(N1)
        n1++;
        temp1 = temp1->next;
    }

    while(temp2!=NULL){  //O(N2)
        n2++;
        temp2 = temp2->next;
    }

    temp1 = head1;
    temp2 = head2;

    if(n1>n2){  //O(N1-N2)
        for(int i=0;i<n1-n2;i++){
            temp1 = temp1->next;
        }
    }else{
        for(int i=0;i<n2-n1;i++){
            temp2 = temp2->next;
        }
    }

    //either //O(N1)
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp->next;
    }
    return temp1;
}
*/

/*
==================================================
Time Complexity: O(N1+2*N2)
Space Complexity: O(1)
==================================================
*/


//Optimal Approach
Node* intersectionPresent(Node* head1,Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1=head2;
        if(temp2 == NULL) temp2=head1;
    }
    return temp1;
}

/*
==================================================
Time Complexity: O(N1+N2)
Space Complexity: O(1)
==================================================
*/