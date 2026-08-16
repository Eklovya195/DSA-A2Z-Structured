/*
Problem:  540.Single Element in a Sorted Array
Problem Statement: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    Return the single element that appears only once.
    Your solution must run in O(log n) time and O(1) space.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/single-element-in-a-sorted-array/description/"
==================================================
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
==================================================
*/

//My Intution for first time i saw this question
/*
#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int> &arr,int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        if(it.second == 1){
            return it.first;
        }
    }
    return 0;
}

int main(){
    vector<int> arr = {3,3,7,7,10,11,11};
    int n = arr.size();
    cout << findSingleElement(arr,n) << "\n";
    return 0;
}
*/

//Brute Force – Approach 1 (Neighbor checking)
/*
#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int> &arr,int n){
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    else{
        for(int i=1;i<n-1;i++){
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
                return arr[i];
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int n = arr.size();
    cout << findSingleElement(arr,n) << "\n";
    return 0;
}
*/

/*
==================================================
Complexity
    Time: O(N)
    Space: O(1)
==================================================
*/

//Optimal approach (Using Binary Search)
#include <bits/stdc++.h>
using namespace std;

int findSingleElement(vector<int> &arr,int n){
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        //if mid is single element
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }

        //if element is in left half 
        if((mid%2==1 && arr[mid] == arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])){
            low = mid+1;
        }else{  //element is in right half
            high = mid-1;
        }
    }
    return -1; //never run
}

int main(){
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    int n = arr.size();
    cout << findSingleElement(arr,n) << "\n";
    return 0;
}

/*
==================================================
Complexity
    Time: O(logN)
    Space: O(1)
==================================================
*/
