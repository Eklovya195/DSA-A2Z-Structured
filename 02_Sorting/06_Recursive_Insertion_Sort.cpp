/*
Problem: Recursive Insertion Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: ""

==================================================
Recursive Insertion Sort sorts the array by recursively sorting the first n-1 elements and
then inserting the last element into its correct position.

==================================================
Complexity Analysis:
Time Complexity:
    ○ Worst / Average: O(n²)
    ○ Best (already sorted): O(n)
Space Complexity: O(n)
    Due to recursive call stack.

Approach(Algorithm):
1. If the size of the array is 1, stop.
2. Recursively sort the first n-1 elements.
3. Insert the last element into the sorted part by shifting elements.

==================================================
Example:
Array: [5, 3, 4, 1]
Sort [5,3,4] → [3,4,5]
Insert 1 → [1,3,4,5]

*/

#include <bits/stdc++.h>
using namespace std;

void recursiveInsertionSort(vector<int>& arr, int n) {
    if (n <= 1) return;
    recursiveInsertionSort(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
int main() {
    vector<int> arr = {5, 3, 4, 1};
    recursiveInsertionSort(arr, arr.size());
    for (int x : arr) cout << x << " ";
    return 0;
}