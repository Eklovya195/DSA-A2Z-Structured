/*
Problem:  216. Combination Sum III
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/combination-sum-iii/description/?utm=codolio"
==================================================
Explanation
You are given two integers k and n.
You need to find all unique combinations of exactly k numbers such that:
    ● Numbers are chosen only from 1 to 9
    ● Each number is used at most once
    ● The sum of chosen numbers is exactly n
    ● No duplicate combinations are allowed
    Order of combinations does not matter


Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
==================================================
*/

/*
==================================================
Idea:
This is a classic backtracking problem where we try to build combinations step by step.
At every step:
    ● Pick a number from 1 to 9
    ● Use each number only once
    ● Keep track of remaining sum
    ● Stop early if:
        ○ sum becomes negative
        ○ combination size exceeds k
==================================================
*/

/*
==================================================
Algorithm:
    1. Start from number 1
    2. Maintain:
        ○ sum
        ○ current combination
    3. If sum is n and size of combination is k, store it
    4. If sum < 0 or size > k, stop recursion
    5. Try next numbers from last + 1 to 9
    6. Backtrack after each recursive call
==================================================
*/

//Recursive Approach(Backtracking Approach):
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(int val,int k,int n,vector<int> &subset,vector<vector<int>> &ans,int length,int sum){
        //base case
        if(length == k){
            if(sum == n){
                ans.push_back(subset);
            }
            return;
        }
        // if(sum>n || length>k) return; 
        for(int i=val;i<=9;i++){
            subset.push_back(i);
            sum += i;
            length++;
            funGenerate(i+1,k,n,subset,ans,length,sum);
            sum -= i;
            length--;
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        int sum = 0;
        funGenerate(1,k,n,subset,ans,0,sum);
        return ans;
    }
};

int main(){
    int k = 3;
    int n = 7;
    int target = 8;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum3(k,n);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
    return 0;
}



/*
==================================================
Complexity Analysis:
Time Complexity: O(2^9 * k)
    We explore all subsets of numbers from 1 to 9.
Space Complexity: O(k)
    Used by recursion stack and current combination
==================================================
*/

//Also replace solution with this to educe no if variable passing in the function
/*
class Solution {
public:
    void funGenerate(int val,int k,int sum,vector<int> &subset,vector<vector<int>> &ans){
        //base case
        if(subset.size() == k && sum == 0){
            ans.push_back(subset);
            return;
        }
        if(sum<0 || subset.size()>k) return; 
        for(int i=val;i<=9;i++){
            subset.push_back(i);
            funGenerate(i+1,k,sum-i,subset,ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        vector<vector<int>> ans;
        int sum = 0;
        funGenerate(1,k,n,subset,ans);
        return ans;
    }
};
*/
