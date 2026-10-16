/*
Problem:  1922. Count Good Numbers
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/count-good-numbers/submissions/2173829756/?utm=codolio"
==================================================
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
==================================================
*/

// Approach(iterative approach):
#include <bits/stdc++.h>
using namespace std;

class Solution {
#define ll long long
public:
    const ll M = 1e9+7;
    //iterative approach
    int pow(int x, ll n){
        int ans = 1;
        while(n){
            if(n&1){
                ans = (ans*1LL*x)%M;
                n  = n-1;
            }else{
                x = (x*1LL*x)%M;
                n = n/2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        int ans = pow(20,n/2);
        if(n&1) ans = (5 * 1LL * ans) % M;
        return ans;
    }
};

int main(){
    long long n = 4;
    Solution obj;
    int ans = obj.countGoodNumbers(n);
    cout << ans;
    return 0;
}



/*
==================================================
Complexity Analysis:
Time Complexity: O(logn) — n->n/2->n/4->n/8
Space Complexity: O(1) 
==================================================
*/