/*
Problem: Print all Divisors
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188?leftPanelTabValue=PROBLEM"

==================================================
Complexity Analysis:
Time Complexity: O(√n)
Space Complexity: O(1)

Approach(Algorithm):
1. Loop from 1 to sqrt(n).
2. If i divides n:
    ○ Print i
    ○ If i != n/i, print n/i.


==================================================

Example
Input: n = 12
Output: 1 2 3 4 6 12
*/

#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i)
            cout << n / i << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}