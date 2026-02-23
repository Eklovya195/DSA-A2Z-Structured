/*
Problem:Reverse an array
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/reverse-an-array/1"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. Use two pointers: start and end.
2. If start >= end, stop.
3. Swap arr[start] and arr[end].
4. Call recursion with start+1 and end-1.

==================================================

*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr,int start,int end){
        if(start>=end) return;
        
        swap(arr[start],arr[end]);
        reverseArray(arr,start+1,end-1);
    }

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin >> arr[i];
    }
    reverseArray(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}
