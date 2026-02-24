/*
Problem: Selection Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/selection-sort/1"

==================================================
(Select Min and Swap)
Selection sort works by repeatedly finding the minimum element from the unsorted part of
the array and placing it at the beginning.
At every step, the array is divided into two parts:
● Left part → already sorted
● Right part → unsorted
We select the smallest element from the unsorted part and swap it with the first unsorted
position

==================================================
Complexity Analysis:
Time Complexity: O(n²)
    Two nested loops always run, regardless of input.
Space Complexity: O(1)
    Sorting is done in-place.

Approach(Algorithm):
1. Loop from index 0 to n-2.
2. Assume the current index is the minimum.
3. Traverse the remaining array to find the actual minimum element.
4. Swap the minimum element with the current index.
5. Repeat until the array is sorted.

==================================================
Example:
Array: [64, 25, 12, 22, 11]
Pass 1: minimum = 11 → swap with 64 → [11, 25, 12, 22, 64]
Pass 2: minimum = 12 → [11, 12, 25, 22, 64]
Pass 3: minimum = 22 → [11, 12, 22, 25, 64]

*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
            minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
