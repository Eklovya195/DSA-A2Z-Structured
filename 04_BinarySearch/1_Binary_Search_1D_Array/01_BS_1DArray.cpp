/*
Problem:  Binary Seach
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/binary-search/description/"
==================================================
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
==================================================
*/
//Method 1: Iterative Approach
/*
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr,int n,int target){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    int n = arr.size();
    int target = 6;
    int ans = search(arr,n,target);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: In the algorithm, in every step, we are basically dividing the search space into
    2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After
    a certain number of divisions, the size will reduce to such an extent that we will not be able to
    divide that anymore and the process will stop. The number of total divisions will be equal to the
Time complexity. So the overall time complexity is O(logN), where N = size of the given array.
Space Complexity: 0(1), no extra space being used
==================================================
*/

//Approach 2: Recursive
#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr,int low,int high,int target){
    if(low>high) return -1;
    //to avoid overflow
    // mid = low + (high-low)/2;
    int mid = (low+high)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return bs(arr,mid+1,high,target);
    return bs(arr,low,mid-1,target);
}

int search(vector<int> &arr,int n,int target){
    return bs(arr,0,n-1,target);
}

int main(){
    vector<int> arr = {-1,0,3,5,9,12};
    int n = arr.size();
    int target = 6;
    int ans = search(arr,n,target);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: In the algorithm, in every step, we are basically dividing the search space into
    2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After
    a certain number of divisions, the size will reduce to such an extent that we will not be able to
    divide that anymore and the process will stop. The number of total divisions will be equal to the
Time complexity. So the overall time complexity is O(logN), where N = size of the given array.
Space Complexity: 0(1), no extra space being used
==================================================
*/