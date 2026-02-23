/*
Problem:Finding Nth Fibonacci number using Recursion
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Problem Link:"https://leetcode.com/problems/fibonacci-number/description/"

==================================================
Complexity Analysis:
Time Complexity: O(2^N), due to repeated calls.
Space Complexity: O(N), recursion stack.

Approach(Algorithm):
1. If N <= 1, return N.
2. Return fib(N-1) + fib(N-2).
==================================================

*/

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}