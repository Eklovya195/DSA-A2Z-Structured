/*
Problem:  50. Pow(x, n)
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/powx-n/submissions/2173803436/?utm=codolio"
==================================================
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
==================================================
*/

// Approach(iterative approach):
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
#define ll long long
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        ll nn = n;
        //if n is -ve made it +ve
        if(nn<0) nn = (-1)*nn;
        while(nn){
            //if nn is odd 
            if(nn%2){
                ans = ans * x;
                nn--;
            }
            //if nn is even
            else{
                x = x*x;
                nn /= 2;
            }
        }
        //if n is -ve return 1/ans
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};

int main(){
    double x = 2.00000;
    int n = -2;
    Solution obj;
    double ans = obj.myPow(x,n);
    cout << ans;
    return 0;
}
*/


/*
==================================================
Complexity Analysis:
Time Complexity: O(logn) — n->n/2->n/4->n/8
Space Complexity: O(1) 
==================================================
*/

//Recursive Approach(Binary Exponential Recursion Approach)
#include <bits/stdc++.h>
using namespace std;

class Solution {
#define ll long long
public:
    double binExpRec(double x,int n){
        if(n==0) return 1.0;
        double res = binExpRec(x,n/2);
        //if n is odd or n%2 == 1
        if(n&1){
            return x * res * res;
        }
        return res * res;
    }

    double myPow(double x, int n) {
        ll power = n;
        if(power < 0){
            return 1.0/binExpRec(x,-power);
        }
        return binExpRec(x,power);
    }
};

int main(){
    double x = 2.00000;
    int n = -2;
    Solution obj;
    double ans = obj.myPow(x,n);
    cout << ans;
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(logn) — n->n/2->n/4->n/8
Space Complexity: O(logn)-- recursive stack is used 
==================================================
*/