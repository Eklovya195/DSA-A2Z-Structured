/*
Problem:  Floor and Ceil
Problem Statement: Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equal to x. This element is called the floor of x. If such an element does not exist, return -1.
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1"
==================================================
Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.
==================================================
*/

/* 
Explanation:
Given a sorted array arr of size n and a value x, find:
● Floor(x): largest value ≤ x
● Ceil(x): smallest value ≥ x
If floor or ceil does not exist → return -1.
Binary Search works perfectly because:
● Floor is the rightmost value ≤ x
● Ceil is the leftmost value ≥ x
So both can be found by slightly modifying binary search.
*/ 

//Floor Algorithm (Simple Explanation)
/*
Goal → largest element ≤ x
Steps:
1. low = 0, high = n-1, ans = -1
2. Find mid
3. If arr[mid] ≤ x:
    → it is a valid floor → update ans = arr[mid]
    → but maybe a larger valid floor exists → go right (low = mid + 1)
4. Else (arr[mid] > x):
    → too big → go left (high = mid - 1)
5. Continue until low > high
6. Return ans
*/

//Ceil Algorithm (Simple Explanation)
/*
Goal → smallest element ≥ x
Steps:
1. low = 0, high = n-1, ans = -1
2. Find mid
3. If arr[mid] ≥ x:
    → valid ceil → update ans = arr[mid]
    → try to find smaller ceil → go left (high = mid - 1)
4. Else (arr[mid] < x):
    → too small → go right (low = mid + 1)
5. Return ans
*/

//Floor program
/*
#include <bits/stdc++.h>
using namespace std;

class FloorCeilFinder {
public:
int findFloor(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            ans = arr[mid]; // potential floor
            low = mid + 1; // try to find a larger floor
        } else {
            high = mid - 1; // go left
        }
    }
    return ans;
}
*/

//ceil program
/*
int findCeil(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = arr[mid]; // potential ceil
            high = mid - 1; // try to find smaller ceil
        } else {
            low = mid + 1; // go right
        }
    }
    return ans;
}
*/

/*
pair<int, int> getFloorAndCeil(const vector<int>& arr, int x) {
    int floorVal = findFloor(arr, x);
    int ceilVal = findCeil(arr, x);
    return {floorVal, ceilVal};
}

int main() {
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;
    FloorCeilFinder finder;
    auto ans = finder.getFloorAndCeil(arr, x);
    cout << "Floor and Ceil: " << ans.first << " " << ans.second << "\n";
    return 0;
}
*/


/*
==================================================
Time Complexity: O(log N)
    Because both floor and ceil use binary search:
    ● Search space halves every iteration
    ● Steps required ≈ log₂(N)
    Even two searches → O(log N) + O(log N) = O(log N).
Space Complexity: O(1)
    ● Only a few variables: low, high, mid, ans
    ● No recursion, no extra arrays
    ● Constant memory usage.
==================================================
*/



