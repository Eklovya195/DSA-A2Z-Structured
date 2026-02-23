/*
Problem: Check Prime
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/prime-number2314/1"

==================================================
Complexity Analysis:
Time Complexity: O(√n)
Space Complexity: O(1)

Approach(Algorithm):
1. If n ≤ 1, not prime.
2. Loop from 2 to sqrt(n).
3. If any divisor is found, not prime.
4. Otherwise, prime.

==================================================

Example
Input: n = 7
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << boolalpha << isPrime(n);
    return 0;
}
