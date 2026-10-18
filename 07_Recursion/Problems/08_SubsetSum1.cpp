/*
Problem:  Subset Sum 1
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm=codolio"
==================================================
Explanation
You are given an array of integers.
Your task is to generate the sum of every possible subset of this array and print all those
sums in increasing order.
A subset can be:
    ● empty
    ● contain some elements
    ● contain all elements
For an array of size N, total subsets = 2^N, so we will also get 2^N subset sums.


Input: arr[] = [2, 3]
Output: [0, 2, 3, 5]
Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. 
When elements 2 and 3 are taken then Sum = 2+3 = 5.
==================================================
*/

/*
==================================================
Approach 1: Bitmasking
Idea
Each subset can be represented using a binary number of length N.
    ● 0 → element excluded
    ● 1 → element included
We iterate from 0 to (2^N - 1) and for each number, 
calculate the subset sum based on set bits.
==================================================
*/

/*
==================================================
Algorithm:
    1. Let n be the size of the array
    2. Iterate mask from 0 to (1 << n) - 1
    3. For each mask:
        ○ Initialize sum = 0
        ○ For each bit i from 0 to n-1
            ■ If ith bit is set, add arr[i] to sum
    4. Store sum in result list
    5. Sort the result list
    6. Return / print it
==================================================
*/

//Brute Force Approach: (Bitmasking)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums; //contain final answer
        int total = 1<<n;  //2^n total subsets
        for(int mask=0;mask<total;mask++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sum += nums[i];
                }
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end());
        return sums;
    }
};

int main(){
    vector<int> nums = {2, 3};
    Solution obj;
    vector<int> ans = obj.subsets(nums);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/


/*
==================================================
Complexity Analysis:
Time Complexity: O(2^N * N)
Space Complexity: O(2^N)
==================================================
*/

/*
==================================================
Algorithm
    1. Create a recursive function with parameters:
        ○ index
        ○ currentSum
    2. If index == N:
        ○ return
    3.Start recursion from index 0 and sum 0
    4. Recursive calls:
        ○ add arr[idx] into sum 
        ○ push sum into final ans
        ○ recursive call for idx+1
        ○ returning time subtract arr[idx] from sum and call again recursive call
    5. Sort the result list
==================================================
*/
//Recursive Approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void funGenerate(int idx,vector<int> &arr,vector<int> &ans,int sum){
        if(idx == arr.size()){
            return;
        }
        sum += arr[idx];
        ans.push_back(sum);
        funGenerate(idx+1,arr,ans,sum);
        
        sum -= arr[idx];
        funGenerate(idx+1,arr,ans,sum);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        vector<int> ans;
        ans.push_back(0);
        funGenerate(0,arr,ans,sum);
        return ans;
    }
};

int main(){
    vector<int> nums = {2, 3};
    Solution obj;
    vector<int> ans = obj.subsetSums(nums);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^N)
Space Complexity:
    ○ O(2^N) for storing sums
    ○ O(N) recursion stack
==================================================
*/