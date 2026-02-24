/*
Problem: Linear Search in Array
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/linear-search_6922070"

==================================================
Example:
Input: ‘n’ = 5, ‘num’ = 4 
'arr' =  [6,7,8,4,1] 
Output : 3
*/

#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[],int n,int num){
    for(int i=0;i<n;i++){
        if(arr[i] == num) return i;
    }
    return -1;
}

int main(){
    int arr[] ={6,7,8,4,1};
    int num = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = LinearSearch(arr,n,num);
    cout << ans;
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1) 
==================================================
*/