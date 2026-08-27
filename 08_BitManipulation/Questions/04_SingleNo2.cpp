/*
Problem: 137. Single Number ||
Problem Statement:Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
    You must implement a solution with a linear runtime complexity and use only constant extra space
Platform: Bit Manipulation / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/single-number-ii/description/"

==================================================
Input: nums = [0,1,0,1,0,1,99]
Output: 99
==================================================
*/

// Approach 1: (Using hashing)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={1,2,2,4,3,1,4};
    //Using hashing to store frequency of elements
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    for(auto it:mp){
        if(it.second == 1){
            cout << it.first;
        }
    }
    return 0;
}
*/

/*
=================================================
Time Complexity: O(N*logM+M) //logM is 1 here as i take unorderd map
    where N is the size of the array.
    M is the size of hashmap & M=(N/3)+1
Space Complexity: O(M), hashmap stores frequencies of elements.
=================================================
*/

//Approach 2: (analysing individual bit index)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={1,2,2,1,3,1,2};
    int ans = 0;
    for(int bitIdx=0;bitIdx<31;bitIdx++){
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<bitIdx)) cnt++;
        }
        if(cnt%3 == 1) ans = ans|(1<<bitIdx);
    }
    cout << ans;
    return 0;
}
*/

/*
=================================================
Time Complexity: O(N*32), where N is the size of the array.
Space Complexity: O(1)
=================================================
*/

//Approach 3: Here problem is we change original array so interviewer is not happy
/*
Algorithm:
    start from index 1
    check if nums[i]==nums[i-1] or not
    if equal move 3 steps ahead
    else answer will be nums[i-1]
    edge case(if single element is at end): 
    if you traverse whole array then final number will be your answer for sure
*/
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={1,2,2,1,2,1,3};
    sort(nums.begin(),nums.end()); //O(NlognN)
    for(int i=1;i<nums.size();i=i+3){  //O(N/3)
        if(nums[i]!=nums[i-1]){
            cout << nums[i-1];
            return 0;
        }
    }
    cout << nums[nums.size()-1];
    return 0;
}
*/

/*
=================================================
Time Complexity: O(N*logN), where N is the size of the array.
Space Complexity: O(1)
=================================================
*/

//Optimal Approach (Concept of buckets) Best One 
//you need to learn this approach as you will not able to find out this in interview
/*
Approach(add & delete):
    nums[i] will go to ones,if not in twos
    nums[i] will go to twos,if it is in ones
    //we don't need three 
    nums[i] will go to three,if it is in twos
    for addition either we can use ^
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={2,2,2,1};
    int ones = 0;
    int twos = 0;
    for(int i=0;i<nums.size();i++){
        ones = (ones^nums[i])&(~twos);
        twos = (twos^nums[i])&(~ones);
    }
    cout << ones;
    return 0;
}

/*
=================================================
Time Complexity: O(N), where N is the size of the array.
Space Complexity: O(1)
=================================================
*/