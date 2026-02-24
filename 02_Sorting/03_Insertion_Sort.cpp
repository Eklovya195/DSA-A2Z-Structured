/*
Problem: Insertion Sort
Platform: Sorting / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/insertion-sort/1"

==================================================
(take an element and place it in its correct order)
Insertion sort builds the sorted array one element at a time, similar to how we sort playing
cards in our hand.
The current element is inserted into its correct position in the already sorted part

==================================================
Complexity Analysis:
Time Complexity:
    ○ Worst / Average: O(n²)
    ○ Best (already sorted): O(n)
Space Complexity: O(1)
    Sorting is done in-place

Approach(Algorithm):
1. Start from the second element.
2. Compare it with elements before it.
3. Shift larger elements one position to the right.
4. Insert the current element at the correct position.
5. Repeat for all elements.


==================================================
Example:
Array: [8, 3, 5, 2]
Insert 3 → [3, 8, 5, 2]
Insert 5 → [3, 5, 8, 2]
Insert 2 → [2, 3, 5, 8]

*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {8, 3, 5, 2};
    insertionSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
