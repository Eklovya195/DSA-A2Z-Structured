/*
Problem:  Frog Jump with K distance Hard One Leetcode
Platform: DP / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/frog-jump/?utm=codolio"
==================================================
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, 
            then 2 units to the 3rd stone, 
            then 2 units to the 4th stone, 
            then 3 units to the 6th stone, 
            4 units to the 7th stone, and 
            5 units to the 8th stone.
==================================================
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int way(int currStone,vector<int> &stones,unordered_map<int,int> &mp,int n,int prevJump,vector<vector<int>> &dp){
        int curr_idx = mp[currStone];
        //base case
        if(curr_idx == n-1) return true;
        if(dp[curr_idx][prevJump] != -1) return dp[curr_idx][prevJump];
        for(int i=-1;i<=1;i++){
            int newJump = prevJump+i;
            if(newJump>0){
                int newStone = currStone+newJump;
                if(mp.find(newStone)!= mp.end()){
                    if(way(newStone,stones,mp,n,newJump,dp)){
                        return dp[curr_idx][prevJump] = 1;
                    }
                }
            }
        }
        return dp[curr_idx][prevJump] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int> mp;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        int currStone = 0,prevJump = 0;
        return way(currStone,stones,mp,n,prevJump,dp);
    }
};

int main(){
    vector<int> stones = {0,1,3,5,6,8,12,17};
    Solution obj;
    cout << obj.canCross(stones);
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(n²). 
    The memoization table guarantees each of the n × (n+1) states is computed exactly once, with a constant 3-step loop inside.
Space Complexity: O(n²) 
    Required for the 2D dp array.
==================================================
*/
