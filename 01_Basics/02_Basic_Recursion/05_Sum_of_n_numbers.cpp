/*
Problem:Sum of first N numbers
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/sum-of-series2811/1"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. If N == 0, return 0.
2. Return N + sum(N-1)

==================================================

*/
#include <bits/stdc++.h>
using namespace std;

int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}
int main() {
    int n;
    cin >> n;
    cout << sumN(n);
    return 0;
}
