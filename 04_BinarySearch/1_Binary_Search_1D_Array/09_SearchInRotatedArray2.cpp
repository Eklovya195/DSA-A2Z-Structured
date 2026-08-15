/*
Problem:  Search in Rotated Sorted Array (not necessary Distinct Element)
Problem Statement: There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/"
==================================================
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
==================================================
*/

//Brute force (Scan array linearly, return i when arr[i] == target, else -1.)
/*
==================================================
Time: O(N)
Space: O(1)
==================================================
*/

//Optimal approach (binary search on rotated array)
/*
==================================================
Algorithm:-
Sorted + rotated + duplicates.
Why this is harder than “Rotated Sorted Array I”? (Distinct Version)
In the distinct version:
👉 One half is ALWAYS sorted
(either left or right)
But in duplicates version this strict rule sometimes breaks.
Example:
[3, 3, 3, 3, 3]
Here:
arr[low] = arr[mid] = arr[high] -> 3 = 3 = 3
Now, can you say left is sorted? right is sorted?
NO.
Both look identical.
The algorithm cannot determine the sorted half.
This is the ONLY reason why duplicates break the clean logic.
How do we fix the problem?
When you see:
arr[low] == arr[mid] == arr[high]
You cannot decide which half is sorted.
So the trick is:
👉 just shrink the array
low++
high--
This safely removes duplicate boundary noise
without affecting correctness.
After shrinking, one half will again become detectable.
This trick is the heart of the algorithm.
Full Intuition
At every step:
✔ Step 1: Check mid
If arr[mid] == target → found → return true
✔ Step 2: Handle the duplicate ambiguity
If
arr[low] == arr[mid] && arr[mid] == arr[high]
then:
👉 We cannot know which half is sorted
👉 So shrink:
low++
high--
continue
✔ Step 3: Identify which half is sorted (once duplicates are handled)
Case A: Left half sorted
arr[low] <= arr[mid]
Check if target lies in that left sorted range.
Case B: Right half sorted
Else → right half sorted
Check if target lies in that right sorted range.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool findElement(vector<int> arr,int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return true;


        //first check if all low,mid,high are same or not
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low+1;
            high = high-1;
            continue;
        }

        //check which half is sorted
        //if left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && arr[mid] >= target) high = mid-1;
            else low = mid+1;
        }
        else{ //if right half is sorted
            if(arr[mid] <= target && arr[high] >= target) low = mid+1;
            else high = mid-1;
        }
    }
    return false;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = arr.size();
    int target = 3;
    bool ans = findElement(arr,n,target);
    cout << boolalpha << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(logN)
Space Complexity: O(1)
==================================================
*/