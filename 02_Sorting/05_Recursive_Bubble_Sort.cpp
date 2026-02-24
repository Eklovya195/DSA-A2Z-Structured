/*
Problem: Recursive Bubble Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: ""

==================================================
Recursive Bubble Sort performs the same operation as normal bubble sort, but instead of using
loops, it uses recursion.
In each recursive call, the largest element moves to the end, and the problem size reduces by
one.

==================================================
Complexity Analysis:
Time Complexity: O(n²)
    Same number of comparisons as iterative bubble sort.
Space Complexity: O(n)
    Recursive call stack uses extra space.

Approach(Algorithm):
1. If the size of the array is 1, stop.
2. Perform one full pass to bubble the largest element to the end.
3. Recursively call bubble sort for the remaining array of size n-1.

==================================================
Example:
Array: [4, 3, 2, 1]
Pass 1 → [3, 2, 1, 4]
Pass 2 → [2, 1, 3, 4]
Pass 3 → [1, 2, 3, 4]

*/

#include <bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(vector<int>& arr, int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
        swap(arr[i], arr[i + 1]);
    }
    recursiveBubbleSort(arr, n - 1);
}
int main() {
    vector<int> arr = {4, 3, 2, 1};
    recursiveBubbleSort(arr, arr.size());
    for (int x : arr) cout << x << " ";
    return 0;
}
