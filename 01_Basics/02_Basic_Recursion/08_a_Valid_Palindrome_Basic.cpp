/*
Problem:Check if String is Palindrome or not
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. Compare first and last characters.
2. If not equal, return false.
3. Call recursion for the inner substring.

==================================================

*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return isPalindrome(s, l + 1, r - 1);
}
int main() {
    string s = "madam";
    cout << isPalindrome(s, 0, s.size() - 1);
    return 0;
}