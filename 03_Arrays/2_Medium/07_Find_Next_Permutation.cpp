/*
Problem: next_permutation : find next lexicographically greater permutation
Problem Description: Given a sequence, find the next arrangement in dictionary (lexicographic) order.
    If you’re already at the largest arrangement (strictly decreasing), the next is the smallest (sorted
    ascending).
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/next-permutation/description/"
==================================================
Input: nums = [1,2,3]
Output: [1,3,2]
==================================================
*/

/*
Brute-Force Approach
The brute force approach to find the next permutation is to find all possible permutations of the array and
then look for next permutation.
● Find all possible permutations of elements present and store them.
● Sort the permutations and search input from all possible permutations. Print the next
permutation present right after it.If the current permutation is the last, return the first
permutation in the list.
Use Recursion to generate all the permutation.
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(vector<vector<int>> &res,vector<int> &arr, int idx) {
    // Base case: if idx reaches the end of array
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }
    // Generate all permutations by swapping
    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        // Recur for the next index
        generatePermutations(res, arr, idx + 1);
        // Backtrack to restore original array
        swap(arr[idx], arr[i]);
    }
}

// Function to find the next permutation
void nextPermutation(vector<int>& arr) {
    vector<vector<int>> res;
    // Generate all permutations
    generatePermutations(res, arr, 0);
    // Sort all permutations lexicographically
    sort(res.begin(), res.end());
    // Find the current permutation index
    for (int i = 0; i < res.size(); i++) {
        // If current permutation matches input
        if (res[i] == arr) {
            // If it's not the last permutation
            if (i < res.size() - 1) {
                arr = res[i + 1];
            }
            // If it's the last permutation
            else {
                arr = res[0];
            }
            break;
        }
    }
}
int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
*/

/*
Don't try to write the code if asked in interview just explain approach
and tell that it will take very large tim complexity
like O(N!*N) so never write code.
*/

/*
Optimal Approach:
Think of the array as: prefix | pivot | suffix
1. Scan from right to left to find the first index i (pivot) such that
nums[i] < nums[i+1].
○ If no such i exists, the array is in descending order → reverse entire array and return.
2. Find the smallest number > nums[i] in the suffix (which is decreasing), so just scan from right
to left to find the first j with nums[j] > nums[i].
3. Swap nums[i] and nums[j].
4. Reverse the suffix (from i+1 to end).
Why reverse? Because the suffix was decreasing; reversing makes it the smallest ascending
tail after the new pivot → gives the immediate next permutation.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> NextPermutaion(vector<int> &arr,int n){
    int index = -1;
    // Step 1: Find dip
    for(int i=n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }
    // Step 2: If last permutation reverse entire array
    if(index == -1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    // Step 3: Find just larger element and swap
    for(int i=n-1;i>index;i--){
        if(arr[i] > arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
     // Step 4: Reverse right part
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    NextPermutaion(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N), we find the breaking point and reverse the subarray in linear time.
Space Complexity: O(1), constant additional space is used.
==================================================
*/

//Bonus: STL one-liner
//C++ already gives you this algorithm!
/*
vector<int> nums = {1,2,3};
if (!next_permutation(nums.begin(), nums.end())) {
// nums has become the smallest permutation
}
*/
//It returns false if it wrapped around (i.e., you were at the last permutation).