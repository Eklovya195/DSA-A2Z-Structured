/*
Problem:  70. Climbing Stairs
Platform: DP / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/climbing-stairs/description/?utm=codolio"
==================================================
You start at stair 0 and want to reach stair n.
At each move, you can climb 1 step or 2 steps.
Return the total number of distinct ways to reach stair n

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
==================================================
*/

//This approach is more easy to understand 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int level,int n,vector<int> &dp){
        //base case
        if(level == n) return 1;

        //check if it is available in dp or not
        if(dp[level]!=-1) return dp[level];

        int ans = 0;
        for(int step=1;step<=2;step++){
            if(level+step<=n){
                int ways = rec(level+step,n,dp);
                ans += ways;
            }
        }
        return dp[level] = ans;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(0,n,dp);
    }
};

int main(){
    int n = 2;
    Solution obj;
    cout << obj.climbStairs(n);
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)  -> instead of whole recursion(2^n)
    it will check only n times and store these values into dp array
Space Complexity: O(n+n)  -> recursion + dp array
==================================================
*/

/*
==================================================
Key Insight:
This problem is identical to a Fibonacci-style recurrence.
    To reach stair n:
    ● You must come from n-1 (1 step), or
    ● From n-2 (2 steps)
    So,
    ways(n) = ways(n-1) + ways(n-2)

Base Cases
    ● ways(0) = 1 → one way (do nothing)
    ● ways(1) = 1 → one way (1 step)
==================================================
*/

/*
Approach 1: Tabulation (Bottom-Up DP)
Algorithm:
    1. Create a dp array of size n+1
    2. Initialize:
        ○ dp[0] = 1
        ○ dp[1] = 1
    For i = 2 → n:
        dp[i] = dp[i-1] + dp[i-2]
    3. Return dp[n]
*/


/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        } 
        return dp[n];
    }
};

int main(){
    int n = 2;
    Solution obj;
    cout << obj.climbStairs(n);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(n)
==================================================
*/

//Approach 2: Space Optimized DP (Recommended)
/*
We only need the previous two values, not the full array.
Algorithm
    1. Maintain two variables:
        ○ prev2 = ways(i-2)
        ○ prev1 = ways(i-1)
    For each step:
    2.curr = prev1 + prev.
    3. Shift values forward
    4. Return final value
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;
        for(int i=2;i<=n;i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        } 
        return prev;
    }
};

int main(){
    int n = 2;
    Solution obj;
    cout << obj.climbStairs(n);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)
==================================================
*/