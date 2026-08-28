/*
Problem: XOR of a Number Range
Problem Statement: Given two integers l and r, find the XOR of elements of the range [l, r].
Platform: Bit Manipulation / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1"

==================================================
Input: l = 4, r = 8 
Output: 8 
Explanation: The value of (4 ^ 5 ^ 6 ^ 7 ^ 8) = 8.
==================================================
*/

//Brute Force:
/*
Algorithm
    Initialize a variable ans with 0.
    Traverse all numbers from L to R.
    For each number, take XOR with ans and update ans.
    After finishing the loop, ans contains the XOR of all numbers in the range.
    Return ans.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        ans = ans^i;
    }
    cout << ans;
    return 0;
}
*/

/*
=================================================
Time Complexity: O(N), where N = R − L + 1.
Space Complexity: O(1), only one variable is used.
=================================================
*/

// Optimal Approach 
/*
Algorithm:
    The XOR of numbers from 1 to n follows a fixed pattern based on n % 4.
    If n % 4 == 0, XOR from 1 to n is n.
    If n % 4 == 1, XOR from 1 to n is 1.
    If n % 4 == 2, XOR from 1 to n is n + 1.
    If n % 4 == 3, XOR from 1 to n is 0.
    To find XOR from L to R:
    Compute XOR from 1 to R.
    Compute XOR from 1 to L − 1.
    XOR these two results to cancel common values and get the answer
*/

#include <bits/stdc++.h>
using namespace std;

int Xortill(int n){
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    return 0;
}

int findRangeXOR(int l,int r){
    return Xortill(r)^Xortill(l-1);
}

int main(){
    int l,r;
    cin >> l >> r;
    cout << findRangeXOR(l,r);
    return 0;
}

/*
=================================================
Time Complexity: O(1), constant time computation.
Space Complexity: O(1), no extra space is used.
=================================================
*/


