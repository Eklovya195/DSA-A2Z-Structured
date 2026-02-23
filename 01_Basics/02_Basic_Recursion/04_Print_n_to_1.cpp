/*
Problem:Print n to 1 using Recursion
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/0"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. If N == 0, stop.
2. Print N.
3. Call recursion with N-1

==================================================

*/
#include <bits/stdc++.h>
using namespace std;

void printNto1(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNto1(n - 1);
}

int main() {
    int n;
    cin >> n;
    printNto1(n);
    return 0;
}