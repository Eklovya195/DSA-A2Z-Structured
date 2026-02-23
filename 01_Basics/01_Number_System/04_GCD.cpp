/*
Problem: GCD or HCF
Platform: Basic Maths / Striver A2Z
Difficulty: Easy
Practice Link:"https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1"
For LCM and GCD both:"https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1"

==================================================
Complexity Analysis:
Time Complexity: O(log min(a, b))
Space Complexity: O(1)

Approach(Algorithm):
(Euclidean Algorithm)
1. While b is not 0:
○ a = a % b
○ Swap a and b
2. When b becomes 0, a is the GCD.

==================================================
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int a,b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}