/*
Problem: Quick Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: ""

==================================================
Quick Sort is a divide and conquer sorting algorithm.
It works by selecting a pivot element, placing it at its correct position, and then recursively
sorting the elements on the left and right of the pivot.
Unlike merge sort, quick sort sorts the array in-place.

==================================================
Complexity Analysis:
Time Complexity:
    ○ Best Case: O(n log n) (balanced partitions)
    ○ Average Case: O(n log n)
    ○ Worst Case: O(n²) (already sorted array with bad pivot choice)
    Worst case happens because the pivot always ends up at one extreme, leading to highly
    unbalanced partitions.
Space Complexity: O(log n)
    Due to recursion stack in the average case.

Approach(Algorithm):
 Hoare’s Partition Scheme (with pivot as first element)
1.Base Condition
    If low < high, continue; otherwise return.
2.Select Pivot & Partition
    Take arr[low] as pivot.
    Use two pointers i = low and j = high:
    Move i right while arr[i] <= pivot
    Move j left while arr[j] > pivot
    If i < j, swap arr[i] and arr[j]
    After loop, swap arr[low] with arr[j].
    Return j as pivot index.
3.Sort Left Part
    Call qs(arr, low, pIndex - 1).
4.Sort Right Part
    Call qs(arr, pIndex + 1, high).

==================================================
Example:
Array: [10, 7, 8, 9, 1, 5]
Pivot = 10
After partition → [5, 7, 8, 9, 1, 10]
Pivot = 5
After partition → [1, 5, 8, 9, 7, 10]
Pivot = 8
After partition → [1, 5, 7, 8, 9, 10]
we got fully sorted array.

*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    qs(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
   return 0;
}