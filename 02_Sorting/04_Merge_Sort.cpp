/*
Problem: Merge Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/merge-sort_920442"
GFG Practice Link:"https://www.geeksforgeeks.org/problems/merge-sort/1"

==================================================
Merge Sort is a divide and conquer algorithm.
It divides the array into two halves, sorts each half recursively, and then merges the two sorted
halves into one sorted array.

==================================================
Complexity Analysis:
Time Complexity: O(n log n)
    Array is divided into halves and merged at each level.
Space Complexity: O(n)
    Extra space is used for temporary arrays during merging.

Approach(Algorithm):
1.Check Base Condition
    If low >= high, return because a single element (or empty part) is already sorted.
2.Divide the Array
    Calculate mid = (low + high) / 2 to split the array into two halves:
    Left half → low to mid
    Right half → mid + 1 to high
3.Recursively Sort Both Halves
    Call ms(arr, low, mid) to sort the left half.
    Call ms(arr, mid + 1, high) to sort the right half.
4.Merge the Two Sorted Halves
    In merge():
    Use two pointers (left = low, right = mid + 1)
    Compare elements from both halves
    Insert the smaller element into a temporary array
    Continue until one half is exhausted
5.Copy Back to Original Array
    After merging, copy all elements from the temporary array back into arr[low … high].

==================================================
Example:
Array: [5, 2, 4, 6, 1, 3]
Divide → [5,2,4] and [6,1,3]
Sort left → [2,4,5]
Sort right → [1,3,6]
Merge → [1,2,3,4,5,6]

*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr,int low,int mid,int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;
    //merge the two halves 
    while(left<=mid && right<=high){
        if(arr[right] <= arr[left]){
            temp.push_back(arr[right]);
            right++;
        }
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }


    //remaining elements
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //copy back to original array
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }

}

void ms(vector <int> &arr,int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    //taking array input
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
   ms(arr,0,n-1);

   //printing the output array
   for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}