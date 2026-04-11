/*
Problem:  Search Insert Position
Problem Statement: Given a sorted array of distinct integers and a target value,
    return the index if the target is found.
    If not, return the index where it would be if it were inserted in order.
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/search-insert-position/description/"
==================================================
Input: nums = [1,3,5,6], target = 2
Output: 1
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int SearchInsert(vector<int> &arr,int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    vector<int> arr = {1,3,5,6};
    int n = arr.size();
    int target = 4;
    int ans = SearchInsert(arr,n,target);
    cout << ans;
    return 0;
}

/*
==================================================
Time complexity. O(logN)
Space Complexity: 0(1), no extra space being used
==================================================
*/