/*
Problem: Reverse a Number
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://leetcode.com/problems/reverse-integer/description/"

==================================================
Complexity Analysis:
Time Complexity: O(log₁₀ n)
Space Complexity: O(1)

Approach(Algorithm):
1. Initialize rev = 0.
2. While n is not 0:
○ Extract last digit using n % 10.
○ Update rev = rev * 10 + digit.
○ Remove last digit from n using n /= 10.
3. Return rev.


==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main() {
    int n;
    cin >> n;
    cout << reverseNumber(n);
    return 0;
}
