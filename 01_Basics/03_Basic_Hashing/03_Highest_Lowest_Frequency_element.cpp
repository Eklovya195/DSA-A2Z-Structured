/*
Problem:Finding Highest and lowest frequency element in array
Platform: Basic Hashing / Striver A2Z
Difficulty: Easy
Practice Link:" https://www.geeksforgeeks.org/problems/most-frequent-element-in-an-array/1"
Medium Level:
    Practice Link:"https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/"

==================================================
Given an array, find:
● The element with the highest frequency
● The element with the lowest frequency
If multiple answers exist, any one is acceptable unless specified.

==================================================
Complexity Analysis:
Time Complexity: O(N)
    One pass for frequency counting
    One pass over hash map
Space Complexity: O(N)
    Hash map stores frequencies of elements

Approach(Algorithm):
1. Count frequencies using hashing.
2. Initialize:
    ○ maxFreq = -∞
    ○ minFreq = +∞
3. Traverse the hash map:
    ○ Update max frequency and corresponding element.
    ○ Update min frequency and corresponding element.
4. Print both elements.

==================================================
Example
Input: [1, 1, 2, 2, 2, 3]
Highest frequency → 2
Lowest frequency → 3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3};
    int n = 6;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElement = -1, minElement = -1;
    
    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElement = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }
    cout << "Highest frequency element: " << maxElement << endl;
    cout << "Lowest frequency element: " << minElement << endl;

    return 0;
}
