/*
Problem: Bubble Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/bubble-sort/1"

==================================================
(Push the max to the last by adjacent swaps)
Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong
order.
After each pass, the largest element moves to the end, like a bubble rising up.

==================================================
Complexity Analysis:
Time Complexity:
    ○ Worst / Average: O(n²)
    ○ Best (already sorted): O(n)
Space Complexity: O(1)
    In-place sorting

Approach(Algorithm):
1. Repeat passes over the array.
2. Compare adjacent elements.
3. Swap if left element is greater than right.
4. After each pass, the largest element settles at the end.
5. Stop early if no swaps occur in a pass

==================================================
Example:
Array: [5, 1, 4, 2, 8]
Pass 1: [1, 4, 2, 5, 8]
Pass 2: [1, 2, 4, 5, 8]
Array becomes sorted.

*/

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i >= 1; i--) {
        bool swapped = false; //optimised here for (O(n))
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    bubbleSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
