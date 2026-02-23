/*
Problem: Count Digits
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/count-digits5716/1"

==================================================
Complexity Analysis:
Time Complexity: O(log₁₀ n), number of digits
Space Complexity: O(1)

Approach(Algorithm):
1. If n is 0, the number of digits is 1.
2. Initialize a counter as 0.
3. Repeatedly divide n by 10.
4. Increment the counter for each division.
5. Stop when n becomes 0.
6. Return the counter.

==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0){
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countDigits(n);
    return 0;
}

