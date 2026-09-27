/*
Problem: 1423. Maximum Points You Can Obtain from Cards
Platform: Sliding Window And Two pointers / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/"
==================================================
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. 
The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
==================================================
*/

/*
Problem Statement: 
    You are given an array cardScore representing scores of cards placed in a row.
    You must choose exactly k cards.
    At every step, you are allowed to pick one card either from the beginning or from the end of the row.
    Your task is to return the maximum total score you can obtain by picking exactly k cards following these rules.
*/

/*
Approach:
    Instead of recalculating sums every time, we use a sliding window idea.
    Key observation:
    If you pick k cards from the ends, it is equivalent to removing a contiguous subarray of
    length n - k from the middle and keeping the rest.
    But since the given approach uses front/back shifting, we follow that logic
Algorithm:
    1. Take all k cards from the front and compute the initial sum.
    2. Then, step by step:
        ○ Remove one card from the front
        ○ Add one card from the back
    3. Update the maximum score at each step.
    4. Do this k times.
*/

//Brute Force Approach:
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        for(int i = 0; i <= k; i++) {
            int currSum = 0;
            // Take i cards from the front
            for(int j = 0; j < i; j++) currSum += cardPoints[j];
            // Take (k - i) cards from the back
            for(int j = 0; j < k - i; j++) currSum += cardPoints[n - 1 - j];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    Solution obj;
    int ans = obj.maxScore(cardPoints,k);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(k^2)
    For each of k combinations, we sum up to k elements.
Space Complexity: O(1)
    Only constant extra variables are used.
==================================================
*/

//Optimal Solution
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }
        int maxSum = lsum;
        int ridx = n-1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[ridx];
            ridx--;
            maxSum = max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    Solution obj;
    int ans = obj.maxScore(cardPoints,k);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(2*k)
    Initial sum takes k steps, and sliding takes k steps.
Space Complexity: O(1)
    Only constant extra variables are used.
==================================================
*/