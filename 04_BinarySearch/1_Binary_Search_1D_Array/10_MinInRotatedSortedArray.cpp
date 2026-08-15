/*
Problem:  Min in Rotated Sorted Array (Distinct Element)
Problem Statement: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
    Given the sorted rotated array nums of unique elements, return the minimum element of this array.
    You must write an algorithm that runs in O(log n) time.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/"
==================================================
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
==================================================
*/

//Brute Force
/*
==================================================
A rotated sorted array looks like this:
Original: [1,2,3,4,5]
Rotated : [4,5,1,2,3]
Notice:
👉 The array is split into two sorted parts.
👉 The minimum element is the rotation point.
👉 It is the only element that is smaller than its previous element.
This makes the problem perfect for binary search.
==================================================
*/

/*
==================================================
Traverse the entire array and keep track of the smallest element.
● Time: O(N)
● Space: O(1)
==================================================
*/

//Optimal Approach (Binary Search)
/*
==================================================
Even after rotation:
● Right half is sorted when nums[mid] <= nums[high]
● Left half is sorted when nums[mid] >= nums[low]
But we don’t care which half is sorted.
We only care:
👉 Is the minimum on the right or left?
The Rule (Very Easy)
Compare nums[mid] with nums[high]:
Case 1: nums[mid] > nums[high]
This means mid is in the left sorted part,
so the minimum must be on the right side:
[4,5,6,7, 0,1,2]
↑ ↑
mid high
mid > high → go right
So:
low = mid + 1
Case 2: nums[mid] < nums[high]
This means the right part is sorted,
so the minimum is either at mid or in the left segment:
[4,5,6, 1,2]
↑ mid
nums[mid] < nums[high] → min is left side
So:
high = mid
✔ Loop ends when low == high
The index of minimum is found.
==================================================
*/
#include <bits/stdc++.h>
using namespace std;

int findMinElement(vector<int> arr,int n){
    int ans = INT_MAX;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[low] <= arr[mid]){ //left half is sorted
            ans = min(ans,arr[low]);
            low = mid+1;
        }else{ //right half is sorted
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {11,13,15,17};
    int n = arr.size();
    int ans = findMinElement(arr,n);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(log N)
Space Complexity: O(1)
==================================================
*/

/*
just add a simple line after finding mid if you want to add 
if(arr[low] <= arr[high]){
    ans = min(ans,arr[low]);
    break;
}
    this will run with slightly better time complexity
*/