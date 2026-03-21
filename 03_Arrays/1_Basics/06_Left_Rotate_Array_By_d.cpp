/*
Problem: left Rotate Array by d positions
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1"
Right Rotate Leetcode: "https://leetcode.com/problems/rotate-array/description/"

==================================================
Example:
Input: [1, 2, 3, 4, 5] , d=2
Output:  [3, 4, 5, 1, 2]

*/


/*
//Approach 1 (Using Extra Array)
#include <bits/stdc++.h>
using namespace std;

void leftRotateByD(int arr[],int n,int d){
    d = d%n;
    int temp[d];

    //store first d elements
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }

    //Shifting in original array
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    
    //adding temp array at last
    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }

    //Printing original updated array
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 5;
    int d = 2;
    int arr[] ={1,2,3,4,5};
    leftRotateByD(arr,n,d);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n+d),
Space Complexity: O(d), as we are using another array of size d
==================================================
*/

/*
====================================================================================================
Idea(Approach):
1. Reverse the first k elements.
2. Reverse the remaining n-k elements.
3. Reverse the whole array.
That results in a left rotation.
====================================================================================================
*/

// Approach 2 (Optimal)
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[],int start,int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void LeftRotateByd(int arr[],int n,int d){
    reverse(arr,arr+d); //reverse(arr,0,d-1)
    reverse(arr+d,arr+n); //reverse(arr,d,n-1)
    reverse(arr,arr+n);   //reverse(arr,0,n-1)
}

int main(){
    int d = 2;
    int n = 5;
    int arr[] ={1,2,3,4,5};
    LeftRotateByd(arr,n,d);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
====================================================================================================
Complexity Analysis:
Time Complexity: O(N) (2N time is used actually)
Space Complexity: O(1), as we are using same array.
====================================================================================================
*/


/*
====================================================================================================
For Right Rotation(Idea):
1. Reverse the whole array.
2. Reverse the first k elements.
3. Reverse the remaining n-k elements.
====================================================================================================
*/
