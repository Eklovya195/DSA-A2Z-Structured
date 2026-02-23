/*
Problem: Armstrong Number
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1?page=1"

==================================================
Complexity Analysis:
Time Complexity: O(log₁₀ n)
Space Complexity: O(1)

Approach(Algorithm):
1. Count the number of digits.
2. Traverse each digit.
3. Add digit^count to sum.
4. Compare sum with original number.


==================================================

Example
Input: n = 153
Explanation: 1³ + 5³ + 3³ = 153
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

bool isArmstrong(int n) {
    int original = n;
    int digits = log10(n) + 1;
    int sum = 0;
    while (n != 0) {
        int d = n % 10;
        sum += pow(d, digits);
        n /= 10;
    }
    return sum == original;
}
int main() {
    int n;
    cin >> n;
    cout << isArmstrong(n);
    return 0;
}
