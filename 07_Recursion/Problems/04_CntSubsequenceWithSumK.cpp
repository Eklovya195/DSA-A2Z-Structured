/*
Problem:  Count all subsequences with sum K
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://takeuforward.org/practice/dsa/count-all-subsequences-with-sum-k?utm=codolio"
==================================================
Given an array nums and an integer k.Return the number of non-empty subsequences of nums such that the sum of all elements in the subsequence is equal to k.

Input : nums = [4, 9, 2, 5, 1] , k = 10
Output : 2
Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].
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
        ○ Include the current element → reduce sum
        ○ Exclude the current element → keep sum same
    3. If sum becomes 0, return 1
    4. If sum < 0 or index reaches array size, return 0
    5. Add results of both choices

*/

//Recursive Approach(Include/Exclude):
#include <bits/stdc++.h>
using namespace std;

class Solution{
    // #define ll long long
    public:  
    void funcGenerate(int idx,vector<int>& nums,int k,int n,int &cnt,int sum){
        if(idx == n){
            if(sum == k){
                cnt++;
            }
            return;
        }
        //picked one
        sum += nums[idx];
        funcGenerate(idx+1,nums,k,n,cnt,sum);

        sum -= nums[idx];

        //not picked
        funcGenerate(idx+1,nums,k,n,cnt,sum);
    }  	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        int n = nums.size();
        int idx = 0;
        int cnt = 0;
        int sum = 0;
        funcGenerate(idx,nums,k,n,cnt,sum);
        return cnt;
    }
};

int main(){
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;
    Solution obj;
    int ans = obj.countSubsequenceWithTargetSum(nums,k);
    cout << ans;
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(2^n) — Every element has two choices (include / exclude)
Space Complexity: O(n) — (recursion depth)
==================================================
*/