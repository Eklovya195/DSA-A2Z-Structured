/*
Problem: Remove Duplicates in-place from Sorted Array
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/remove-duplicates-from-sorted-array_1102307?leftPanelTabValue="
Leetcode Link:"https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/"

==================================================
Example:
Input: 0 0 1 1 1 2 2 3 3 4
Output Array: 0 1 2 3 4 …aage kuch bhi ho
k = 5

*/

/*
// APPROACH 1: Using unordered_set
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    int index = 0;
    for (int num : nums) {
    // If num is not in seen, it's unique
        if (seen.find(num) == seen.end()) {
            // Add this num to the set of seen numbers
            seen.insert(num);
            // Overwrite nums[index] with this unique num
            nums[index] = num;
            // Move index forward
            index++;
        }
    }
    // Return count of unique elements
    return index;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N), We traverse the entire array and insert elements into set.
Space Complexity: O(N), additional space used to store elements in set.
==================================================
*/

// APPROACH 2 (Optimal): Two Pointer Technique
#include <bits/stdc++.h>
using namespace std;
// Class to hold the solution logic
class Solution {
public:
// Function to remove duplicates from sorted array in-place
    int removeDuplicates(vector<int>& nums) {
    // If array is empty, return 0 directly
        if (nums.empty()) return 0;
        // Pointer for the position of last unique element
        int i = 0;
        // Traverse the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
        // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move pointer for unique element forward
                i++;
                // Place the new unique element at the next position
                nums[i] = nums[j];
            }
        }
        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int k = sol.removeDuplicates(nums);
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N), We traverse the entire original array only once.
Space Complexity: O(1), constant additional space is used to check unique elements.

==================================================
*/