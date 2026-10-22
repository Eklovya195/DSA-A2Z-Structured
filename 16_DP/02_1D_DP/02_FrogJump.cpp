/*
Problem:  Frog Jump
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/geek-jump/1?utm=codolio"
==================================================
A frog starts at stair 0 and wants to reach stair n-1.
From stair i, it can jump to:
● i + 1
● i + 2
Energy cost of a jump from i → j:
abs(height[i] - height[j])
Return the minimum total energy required to reach stair n-1.


Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
==================================================
*/

/*
==================================================
3 step Approach of Solving DP problems:
    1. explain problem in term of index
    2.do all stuff on that index
    3.take the min(all stuff)/sum(all stuff) whatever is asked
==================================================
*/

//Brute force Solution (Recursion only no dp used)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rec(vector<int> &height,int idx){
        //base case
        if(idx == 0) return 0;
        //one step
        int left = rec(height,idx-1) + abs(height[idx]-height[idx-1]);
        //two steps
        int right = INT_MAX;
        if(idx>1){
            right = rec(height,idx-2) + abs(height[idx]-height[idx-2]);
        }
        //return minimum among both
        return min(left,right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        return rec(height,n-1);
    }
};

int main(){
    vector<int> heights = {30, 20, 50, 10, 40};
    Solution obj;
    cout << obj.minCost(heights);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(2^n)  ->  recursion(2^n)
Space Complexity: O(n)  -> recursion
==================================================
*/

//Approach 1: Memoization(Top-Down)
/*
Algorithm
    ● Define a recursive function solve(i)
    ● Store already computed results in dp[]
    ● Avoid recomputation of overlapping subproblems
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rec(vector<int> &height,int idx,vector<int> &dp){
        //base case
        if(idx == 0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //one step
        int left = rec(height,idx-1,dp) + abs(height[idx]-height[idx-1]);
        //two steps
        int right = INT_MAX;
        if(idx>1){
            right = rec(height,idx-2,dp) + abs(height[idx]-height[idx-2]);
        }
        //return minimum among both
        return dp[idx] = min(left,right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        return rec(height,n-1,dp);
    }
};

int main(){
    vector<int> heights = {20, 30, 40, 20};
    Solution obj;
    cout << obj.minCost(heights);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)  -> instead of whole recursion(2^n)
    it will check only n times and store these values into dp array
Space Complexity: O(n+n)  -> recursion + dp array
==================================================
*/

//Appraoch 2: Tabulation Appraoch(Bottom Up)
/*
Algorithm
    ● Build the solution iteratively
    ● Each state depends only on previous two states
*/
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int idx=1;idx<n;idx++){
            int fs = dp[idx-1]+abs(height[idx]-height[idx-1]);
            int ss = INT_MAX;
            if(idx>1){
                ss = dp[idx-2]+abs(height[idx]-height[idx-2]);
            }
            dp[idx] = min(fs,ss);
        } 
        return dp[n-1];
    }
};

int main(){
    vector<int> heights = {20, 30, 40, 20};
    Solution obj;
    cout << obj.minCost(heights);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)  -> instead of whole recursion(2^n)
    it will check only n times and store these values into dp array
Space Complexity: O(n)  -> dp array
==================================================
*/

//Appraoch 3: Tabulation Appraoch without dp array (Bottom Up)
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev2 = 0;
        int prev = 0;
        int curr;
        for(int idx=1;idx<n;idx++){
            int fs = prev+abs(height[idx]-height[idx-1]);
            int ss = INT_MAX;
            if(idx>1){
                ss = prev2+abs(height[idx]-height[idx-2]);
            }
            curr = min(fs,ss);
            prev2 = prev;
            prev = curr;
        } 
        return prev;
    }
};

int main(){
    vector<int> heights = {20, 30, 40, 20};
    Solution obj;
    cout << obj.minCost(heights);
    return 0;
}
/*
==================================================
Complexity Analysis:
Time Complexity: O(n)  -> instead of whole recursion(2^n)
    it will check only n times and store these values into dp array
Space Complexity: O(1)
==================================================
*/