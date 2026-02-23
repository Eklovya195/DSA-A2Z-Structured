/*
Problem:Factorial of a number
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/factorial5739/1"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. If N == 0, return 1.
2. Return N * factorial(N-1).

==================================================

*/

#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
