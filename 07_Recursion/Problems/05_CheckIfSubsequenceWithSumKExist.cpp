/*
Problem:  Check if subsequences with sum K exist or not
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://takeuforward.org/practice/dsa/check-if-there-exists-a-subsequence-with-sum-k?utm=codolio"
==================================================
Given an array nums and an integer k. 
Return true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.

Input : nums = [1, 2, 3, 4, 5] , k = 8
Output : Yes
Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.
==================================================
*/

/*
A subsequence means:
    ● You can choose or skip any element
    ● Order must remain the same
    ● Elements do not have to be contiguous
So for every element, you always have two choices:
    1. Include it in the subsequence
    2. Exclude it from the subsequence
This naturally leads to a recursive include / exclude approach.

*/
/*
Algorithm:
    1. Start recursion from index 0 with target sum k
    2. At each index:
        ○ include current element
        ○ exclude current element
    3. If sum becomes 0, return true
    4. If array ends, return false
    5. Return true if any path returns true

*/

//Recursive Approach(Include/Exclude):
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool funcGenerate(int idx,vector<int>& nums,int k,int n,int sum){
        if(idx == n){
            if(sum == k){
                return true;
            }
            return false;
        }
        //picked one
        sum += nums[idx];

        if(funcGenerate(idx+1,nums,k,n,sum) == true){
            return true;
        }

        sum -= nums[idx];

        //not picked
        if(funcGenerate(idx+1,nums,k,n,sum) == true){
            return true;
        }
        return false;
    } 
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = 0;
        int sum = 0;
        return funcGenerate(idx,nums,k,n,sum);
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 8;
    Solution obj;
    bool ans = obj.checkSubsequenceSum(nums,k);
    cout << boolalpha << ans;
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(2^n) — Every element has two choices (include / exclude)
Space Complexity: O(n) — (recursion depth)
==================================================
*/