/*
Problem:Print 1 to n using Recursion
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:" https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/0"

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. If N == 0, stop.
2. First call recursion with N-1.
3. Print N.

==================================================
*/

#include <bits/stdc++.h>
using namespace std;
void print1toN(int n) {
    if (n == 0) return;
    print1toN(n - 1);
    cout << n << " ";
}
int main() {
    int n;
    cin >> n;
    print1toN(n);
    return 0;
}