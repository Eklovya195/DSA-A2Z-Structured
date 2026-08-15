/*
Problem:  Search in Rotated Sorted Array (Distinct Element)
Problem Statement: There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/search-in-rotated-sorted-array/description/"
==================================================
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
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
Either of one half is sorted
At each step:
● compute mid
● if a[mid] == target → return mid
● else check if left half a[low]..a[mid] is sorted (a[low] <= a[mid])
○ if sorted and a[low] <= target < a[mid] → search left (high = mid - 1)
○ else → search right (low = mid + 1)
● otherwise right half is sorted
○ if a[mid] < target <= a[high] → search right (low = mid + 1)
○ else → search left (high = mid - 1)
Repeat until low > high.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int> arr,int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;

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
    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = arr.size();
    int target = 3;
    int ans = findElement(arr,n,target);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(logN)
Space Complexity: O(1)
==================================================
*/