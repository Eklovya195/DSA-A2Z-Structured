/*
Problem: 69.Find Sqrt of a no
Problem Statement: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operato
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/sqrtx/description/"
==================================================
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int low = 1,high = x;
    while(low<=high){
        long long mid = low + (high-low)/2;
        long long val = mid*mid;
        if(val<=x) low = mid+1;
        else high = mid-1;
    }
    cout << high;
    return 0;
}

/*
==================================================
Complexity:
    Time: O(logN)
    Space: O(1)
==================================================
*/