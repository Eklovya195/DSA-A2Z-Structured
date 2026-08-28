/*
Problem: 260. Single Number |||
Problem Statement: Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
Platform: Bit Manipulation / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/single-number-iii/description/"

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
    vector<int> nums={1,2,1,3,2,5};
    //Using hashing to store frequency of elements
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    vector<int> ans;
    for(auto it:mp){
        if(it.second == 1){
            ans.push_back(it.first);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
=================================================
Time Complexity: O(N*logM+M) //logM is 1 here as i take unorderd map
    where N is the size of the array.
    M is the size of hashmap & M=(N/2)+1
Space Complexity: O(M), hashmap stores frequencies of elements.
=================================================
*/

//Optimal Approach:(Using Xor And Bucket Method)
/*
Algorithm:
    XOR all elements of the array. Duplicate elements cancel out, leaving XOR of the two unique numbers.
    Find the rightmost set bit in this XOR result. This bit differs between the two unique numbers.
    Traverse the array again and divide numbers into two groups/buckets based on this bit.
    XOR numbers within each group/buckets separately.
    Each group/buckets will give one unique number.
    return them.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums){
    int n = nums.size();
    //need to take long otherwise overflow for 2^-31
    //good point for interview
    long x = 0; 
    for(int i=0;i<n;i++){  //O(N)
        x = x^nums[i];
    }

    int rightmost = (x&(x-1))^x;
    int bucket1 = 0;
    int bucket2 = 0;
    for(int i=0;i<n;i++){ //O(N)
        if(nums[i]&rightmost) bucket1 ^= nums[i];
        else bucket2 ^= nums[i];
    }
    return {bucket1,bucket2};
}

int main() {
    vector<int> nums={1,2,1,3,2,5};
    vector<int> ans= singleNumber(nums);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
=================================================
Time Complexity: O(2*N), the array is traversed twice.
Space Complexity: O(1), only constant extra variables are used.
=================================================
*/
