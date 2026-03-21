/*
Problem: Move all zeroes in array at the end(in-place)
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/move-zeroes/description/"
GFG Practice:"https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1"
==================================================
Example:
Input: [1, 2, 0, 4, 3, 0, 5, 0] 
Output: [1, 2, 4, 3, 5, 0, 0, 0]
*/


/*
//Approach 1 (Brute Force)(Using temp array space)
#include<bits/stdc++.h>
using namespace std;

void moveZero(int arr[],int n){
    vector<int> temp;

    //copy non-zero elements
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int k = temp.size(); //size of temp array

    // copy non-zero elements back
    for(int i=0;i<k;i++){
        arr[i] = temp[i];
    }

    //fill remaining with zeros
    for(int i=k;i<n;i++){
        arr[i] = 0;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[] ={1,2,0,4,3,0,5,0};
     int n = sizeof(arr)/sizeof(arr[0]);
    moveZero(arr,n);
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n), we can move all zeroes to end in linear time.
Space Complexity: O(n), additional space used for temporary array 
==================================================
*/

// APPROACH 2 — Optimal Two-Pointer / Swapping (O(1) space)
#include <bits/stdc++.h>
using namespace std;

void moveZero(int arr[],int n){
    int j = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }

    if(j==-1) return;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    int arr[] ={1,2,0,4,3,0,5,0};
     int n = sizeof(arr)/sizeof(arr[0]);
    moveZero(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
/*
==================================================
Complexity Analysis:
Time Complexity: O(n), we can move all zeroes to end in linear time.
Space Complexity: O(1) 
==================================================
*/