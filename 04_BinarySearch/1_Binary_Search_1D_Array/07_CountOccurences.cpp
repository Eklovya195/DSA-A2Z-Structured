/*
Problem:  Count Occurence
Problem Statement: Given a sorted array arr[] and a number target, 
    find the number of occurrences of target in given array. 
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1"
==================================================
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
==================================================
*/


#include <bits/stdc++.h>
using namespace std;

int FirstOccurence(vector<int> &arr,int n,int target){
    int first = -1;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return first;
}

int LastOccurence(vector<int> &arr,int n,int target){
    int last = -1;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid+1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return last;
}

int main(){
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int n = arr.size();
    int target = 4;
    int firstIndex = FirstOccurence(arr,n,target);
    int lastIndex = LastOccurence(arr,n,target);
    if(firstIndex == -1) cout << 0;
    else cout << lastIndex - firstIndex + 1;
    return 0;
}

/*
==================================================
Time Complexity: O(logN)
Space Complexity: O(1)
==================================================
*/