/*
Problem: 136. Single Number
Problem Statement:Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.
Platform: Bit Manipulation / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/single-number/description/"

==================================================
Input: nums = [2,2,1]
Output: 1
==================================================
*/

// Approach 1: Brute Force
/*
=================================================
Algorithm:
    Use a hashmap to store the frequency of each number.
    Traverse the array and for each element, increase its count in the map.
    After filling the map, traverse it to find the element whose frequency is exactly 1.
    Return that element.
    If no such element is found (though the problem guarantees one), return -1.
=================================================
*/

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

//Better Approach (Using Xor operator)
/*
Algorithm:
    
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={1,2,2,4,3,1,4};
    int XOR=0;
    for(int i=0;i<nums.size();i++){
        XOR ^= nums[i];
    }
    cout << XOR;
    return 0;
}

/*
=================================================
Time Complexity: O(N), where N is the size of the array.
Space Complexity: O(1)
=================================================
*/