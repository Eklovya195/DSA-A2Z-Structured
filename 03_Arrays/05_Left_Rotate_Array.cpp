/*
Problem: left Rotate Array by one
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278"
Right Rotate Link:"https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1"

==================================================
Example:
Input: [1, 2, 3, 4, 5]
Output: [2, 3, 4, 5, 1]

*/

/*
//Approach 1 (Using Extra Array)
#include <bits/stdc++.h>
using namespace std;

void RotateByOne(int arr[],int n){
    int temp[n];

    for(int i=1;i<n;i++){
       temp[i-1] = arr[i];
    }
    temp[n-1] = arr[0];
    for(int i=0;i<n;i++){
        cout << temp[i] << " ";
    }
}

int main(){
    int n = 5;
    int arr[] ={1,2,3,4,5};
    RotateByOne(arr,n);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N), as we iterate through the array only once.
Space Complexity: O(N), as we are using another array of size, same as the given array
==================================================
*/

//Approach 2 (Optimal) (In-place Rotation)
#include <bits/stdc++.h>
using namespace std;

void LeftRotateByOne(int arr[],int n){
    int temp = arr[0];

    for(int i=0;i<n-1;i++){
       arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 5;
    int arr[] ={1,2,3,4,5};
    LeftRotateByOne(arr,n);
    return 0;
}

/*
====================================================================================================
Complexity Analysis:
Time Complexity: O(N), as we iterate through the array only once.
Space Complexity: O(1), as we are using same array.
====================================================================================================
*/