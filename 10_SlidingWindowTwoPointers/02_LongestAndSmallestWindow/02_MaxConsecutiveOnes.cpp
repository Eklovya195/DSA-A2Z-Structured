/*
Problem: 1004. Max Consecutive Ones III
Platform: Sliding Window And Two pointers / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/max-consecutive-ones-iii/description/?utm=codolio"
==================================================
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
==================================================
*/

/*
Problem Statement: 
    You are given a binary array nums (containing only 0 and 1) and an integer k.
    You are allowed to flip at most k zeros into ones.
    Your task is to return the maximum number of consecutive 1s that can be obtained after
    performing at most k flips
*/

//Appraoch 1: Brute force 
/*
Algorithm:
    Try every possible subarray.
    For each subarray, count how many zeros it contains.
    If the number of zeros is less than or equal to k, the subarray is valid.
    Track the maximum length among all valid subarrays.
    Return the maximum length found.
*/


/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            int zerocnt = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==0) zerocnt++;
                if(zerocnt<=k){
                    int len = j-i+1;
                    maxlen = max(maxlen,len);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution obj;
    cout << obj.longestOnes(nums,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(n²)
    Nested loops check all possible substrings.
Space Complexity: O(1)
==================================================
*/

//Better Approach: Sliding Window Approach 
/*
Algorithm:
        Use a sliding window with two pointers left and right.
        Expand the window using right.
        Count zeros inside the window.
        If zeros exceed k, shrink the window from the left.
        Update the maximum window size after each step.
        Return the maximum length found.
        Right pointer ek step me sirf 1 zero add kar sakta hai.
        So:
            zerocount maximum 1 se hi badh sakta hai
            Isliye window sirf 1 step invalid hoti hai
            Usko theek karne ke liye 1 step shrink bhi kaafi hota hai
*/

/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0,zerocnt = 0,l = 0,r = 0;
        while(r<n){
            if(nums[r]==0) zerocnt++;
            while(zerocnt>k){
                if(nums[l]==0) zerocnt--;
                l++;
            }
            if(zerocnt<=k){
                int len = r-l+1;
                maxlen = max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution obj;
    cout << obj.longestOnes(nums,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*n)
    inner while loop will not run always n times
Space Complexity: O(1)
==================================================
*/

//Optimal Approach: Sliding Window Approach 
/*
Algorithm:
        Use two pointers left and right.
        Maintain a count of zeros in the current window.
        Move right forward each step.
        If zero count exceeds k, move left forward once and adjust zero count.
        Update maximum window length at each step.
        This avoids an inner loop and keeps logic simple
*/




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0,zerocnt = 0,l = 0,r = 0;
        while(r<n){
            if(nums[r]==0) zerocnt++;
            if(zerocnt>k){
                if(nums[l]==0) zerocnt--;
                l++;
            }
            if(zerocnt<=k){
                int len = r-l+1;
                maxlen = max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    Solution obj;
    cout << obj.longestOnes(nums,k);
    return 0;
}

/*
==================================================
Time Complexity: O(n)
Space Complexity: O(1)
==================================================
*/