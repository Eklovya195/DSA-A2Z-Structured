/*
Problem: 162.Find Peak Element
Problem Statement: A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/find-peak-element/description/"
==================================================
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
==================================================
*/

//Brute Force
/*
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        if((i==0 || arr[i]>arr[i-1])&&(i==n-1 || arr[i]>arr[i+1])){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    int n = arr.size();
    cout << findPeakElement(arr,n) << "\n";
    return 0;
}
*/

/*
==================================================
Complexity:
    Time: O(N)
    Space: O(1)
==================================================
*/

//Optimal Approach (using Binary Search)
/*
Think of the array like mountains—if you are going uphill, a peak must exist somewhere ahead.
Let’s analyze:
Case A: arr[mid] < arr[mid + 1]
    This means:
    mid → mid+1 → increasing slope
    So the peak lies to the right.
    We move:
    low = mid + 1
Case B: arr[mid] > arr[mid + 1]
    This means:
    mid → mid+1 → decreasing slope
    So we are in the right half of a mountain,
    and the peak lies at mid OR left side.
    We move:
    high = mid
❗ What guarantees correctness?
Every array with finite ends must have at least 1 peak.
Also:
● Left of peak: strictly increasing region
● Right of peak: strictly decreasing region
Binary search always moves toward a peak.
*/
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr,int n){
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    int n = arr.size();
    cout << findPeakElement(arr,n) << "\n";
    return 0;
}

/*
==================================================
Complexity:
    Time: O(logN)
    Space: O(1)
==================================================
*/