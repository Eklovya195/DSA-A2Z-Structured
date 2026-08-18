/*
Problem: 410. Split Array Largest Sum
Problem Statement:Given an integer array nums and an integer k,
    split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
    Return the minimized largest sum of the split.
    A subarray is a contiguous part of the array.
Platform: Binary Search / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/split-array-largest-sum/description/"
==================================================
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
==================================================
*/

/*
Example 1
Input:
A = [1, 2, 3, 4, 5]
K = 3
Output:
6
Explanation:
Split as:
[1, 2, 3] | [4] | [5]
Subarray sums = 6, 4, 5
Largest sum = 6
*/

//Approach (Binary Search on Answer)
/*
Key Idea
Instead of deciding the split directly, decide the maximum allowed subarray sum and check if
the array can be split into at most K subarrays.
● If more than K subarrays are required → allowed sum is too small
● If K or fewer subarrays are enough → allowed sum is valid
The answer space is monotonic, so Binary Search applies.
*/

/*
Binary Search Logic
while(low <= high):
mid = (low + high) / 2
partitions = countPartitions(mid)
if partitions > K:
low = mid + 1
else:
high = mid - 1
Final answer is low
*/

#include <bits/stdc++.h>
using namespace std;
int countPartitions(vector<int>& a, int maxSum) {
    int partitions = 1;
    long long currentSum = 0;
    for (int i = 0; i < a.size(); i++) {
    if (currentSum + a[i] <= maxSum) {
        currentSum += a[i];
    } else {
        partitions++;
        currentSum = a[i];
    }
    }
    return partitions;
}
int splitArrayLargestSum(vector<int>& a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    while (low <= high) {
    int mid = low + (high - low) / 2;
    int partitions = countPartitions(a, mid);
    if (partitions > k) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
    }
    return low;
}
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 3;
    cout << splitArrayLargestSum(a, k) << endl;
    return 0;
}

/*
==================================================
Time: O(N log(sum − max))
Space: O(1)
==================================================
*/

 
