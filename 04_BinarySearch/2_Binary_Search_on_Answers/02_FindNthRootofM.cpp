/*
Problem: Find nth root of m
Problem Statement: You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1"
==================================================
Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8
==================================================
*/

// Brute Force Approach — O(M)
// Try every number from 1 to M and check if iⁿ == M.
// Stop if iⁿ > M.
/*
int nthRoot(int n, int m) {
    for (int i = 1; i <= m; i++) {
        long long power = pow(i, n);
        if (power == m) return i;
        if (power > m) break;
    }
    return -1;
}
*/

/*
Complexity:
==================================================
    Time: O(M)
    Space: O(1)
==================================================
*/



//optimal Approach
/*
==================================================
Approach:
    The N-th root of M must lie in the range:1 to M
    Since this range is sorted, we can use binary search.
    For a given mid:
    Compute:midⁿ
    We do NOT use pow(mid, n) because it:
    ● is slow
    ● causes overflow
    ● is inaccurate for big numbers
    Instead, we multiply mid by itself n times with overflow checking.
    ⭐ Helper function logic
    We create a function that compares:
    midⁿ with M
    without overflowing.
==================================================
*/
#include <bits/stdc++.h>
using namespace std;

int func(int mid,int n,int m){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans *= mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int main(){
    int n,m;
    cin >> n >> m;
    int low = 0,high = m;
    while(low<=high){
        int mid = low + (high-low)/2;
        int midN = func(mid,n,m);
        if(midN == 1){
            cout << mid;
            break;
        }
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }
    return 0;
}

/*
==================================================
Complexity:
    Time: O(logN)
    Space: O(1)
==================================================
*/