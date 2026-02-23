/*
Problem: Check Palindrome
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://leetcode.com/problems/palindrome-number/description/"

==================================================
Complexity Analysis:
Time Complexity: O(log₁₀ n)
Space Complexity: O(1)

Approach(Algorithm):
1. Store the original number.
2. Reverse the number.
3. Compare reversed number with original.
4. If equal, it is a palindrome

==================================================
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n) {
    int original = n, rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev == original;
}
int main() {
    int n;
    cin >> n;
    cout << isPalindrome(n);
    return 0;
}
