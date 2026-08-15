/*
Problem:  First And Last Occurence
Problem Statement: Given an array of integers nums sorted in non-decreasing order, 
    find the starting and ending position of a given target value.
    If target is not found in the array, return [-1, -1].
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/"
==================================================
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
==================================================
*/

//Brute Force
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> FirstAndLastOccurence(vector<int> v,int n,int key){
    int first = -1;
    int last = -1;
    for(int i=0;i<n;i++){
        if(v[i] == key){
            if(first == -1) first = i;
            last = i;
        }
    }
    return {first,last};
}

int main(){
    vector<int> v = {3,4,13,13,13,20,40};
    int key = 13;
    int n = v.size();

    vector<int> ans = FirstAndLastOccurence(v,n,key);
    for(int x:ans){
        cout << x << " ";
    }
}
*/

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/

//Better One or Optimal (using Upper & Lower Bound)
/*
#include <bits/stdc++.h>
using namespace std;

int UpperBound(vector<int> &arr,int n,int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int LowerBound(vector<int> &arr,int n,int target){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

vector<int> FirstAndLast(vector<int> &arr,int n,int target){
    int lb = LowerBound(arr,n,target);
    int up = UpperBound(arr,n,target);
    if(lb == n || arr[lb] != target) return {-1,-1};
    return {lb,up-1};
}

int main(){
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int n = arr.size();
    int target = 11;
    vector<int> ans = FirstAndLast(arr,n,target);
    for(int x:ans){
        cout << x << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: 2*O(logN)
    2 times logN one for Lower Bound and One for Upper Bound
Space Complexity: O(1)
==================================================
*/

//Optimal(Using Binary Search Directly)
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
    int target = 11;
    int firstIndex = FirstOccurence(arr,n,target);
    int lastIndex = LastOccurence(arr,n,target);
    cout << firstIndex << " " << lastIndex;
    return 0;
}

/*
==================================================
Time Complexity: O(logN)
Space Complexity: O(1)
==================================================
*/