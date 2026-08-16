/*
Problem:  Find Kth rotation
Problem Statement: Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
    Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
    After 1st Rotation : [9, 2, 4, 6]
    After 2nd Rotation : [6, 9, 2, 4]
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/rotation4723/1"
==================================================
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
==================================================
*/

//Approach
/*
Sorted array (distinct values) ko unknown pivot par rotate kiya gaya hai. Hume pata karna hai
kitni baar array rotate hua — yani original sorted array ke mukable current array ka smallest
element ka index. Woh index hi rotation count hota hai.
Examples:
● [4,5,6,7,0,1,2,3] → smallest 0 at index 4 → rotated 4 times
● [3,4,5,1,2] → smallest 1 at index 3 → rotated 3 times
(Assumption: distinct values — agar duplicates ho to algo thoda modify karna padega.)
Rotation cut point pe order break hota hai. Smallest element wahi hota hai jahan break hua. So
find index of minimum
*/

// Approach A — Brute force
// Scan full array, track minimum value and its index.
// Return index.
/*
int findRotationsBrute(const vector<int>& a) {
    int n = a.size();
    int minIdx = 0;
    for (int i = 1; i < n; ++i)
    if (a[i] < a[minIdx]) minIdx = i;
    return minIdx;
}
*/

/*
==================================================
Complexities: Time O(N), Space O(1)
==================================================
*/


// Approach B — Optimal (Binary Search) — O(log N)
/*
Key idea: Use same trick as findMin in rotated sorted array:
● Compare a[mid] with a[high].
○ If a[mid] > a[high] → min is in right half → low = mid + 1.
○ Else → min is at mid or left → high = mid.
● Loop while low < high. When ends low == high → index of minimum → rotation
count.
Why this works: In rotated sorted array the smaller half containing the minimum will be
identified by a[mid] <= a[high].
*/

#include <bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> &arr){
    int ans = INT_MAX;
    int idx = -1;
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[low]<=arr[high]){
            if(arr[low]<ans){
                idx = low;
                ans = arr[low];
            }
            break;
        }

        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                idx = low;
                ans = arr[low];
            }
            low = mid+1;
        }else{
            if(arr[mid]<ans){
                idx = mid;
                ans = arr[mid];
            }
            high = mid-1;
        }
    }
    return idx;
}

int main(){
    vector<int> arr = {5, 1, 2, 3, 4};
    cout << findRotationCount(arr) << "\n";
    return 0;
}

/*
==================================================
Complexities: Time O(logN), Space O(1)
==================================================
*/