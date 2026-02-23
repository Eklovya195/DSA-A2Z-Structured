/*
Problem:Counting Frequency of Array Elements
Platform: Basic Hashing / Striver A2Z
Difficulty: Easy
Similar Practice Link:"https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1"
Practice Link2:"https://www.naukri.com/code360/problems/sort-elements-by-frequency_1280138"

==================================================
Complexity Analysis:
Time Complexity: O(N) 
Space Complexity: O(N) 
Reason:
● We traverse the array once.
● Hash map stores at most N elements.

Approach(Algorithm):
1. Create an unordered_map to store element → frequency.
2. Traverse the array.
3. For each element, increment its count in the map.
4. Print the stored frequencies.

==================================================
Example:
Input: [10, 5, 10, 15, 10, 5]
Output:
● 10 → 3
● 5 → 2
● 15 → 1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = 6;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto it : freq) {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }
    return 0;
}