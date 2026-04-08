/*
Problem:  Implementing Lower Bound
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/implement-lower-bound/1"
==================================================
Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[] 
where element (arr[3] = 10) is greater than or equal to 9.
==================================================
*/

//Approach 1 : Brute Force Approach
/*
#include <bits/stdc++.h>
using namespace std;

int LowerBound(vector<int> &arr,int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i] >= target){
            return i;
        }
    }
    return n;
}

int main(){
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int n = arr.size();
    int target = 11;
    int ans = LowerBound(arr,n,target);
    cout << ans;
    return 0;
}
*/
/*
==================================================
Time complexity. O(N)
Space Complexity: 0(1), no extra space being used
==================================================
*/

//Optimal Approach: Binary Search
/*
#include <bits/stdc++.h>
using namespace std;

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

int main(){
    vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    int n = arr.size();
    int target = 11;
    int ans = LowerBound(arr,n,target);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time complexity. O(logN)
Space Complexity: 0(1), no extra space being used
==================================================
*/