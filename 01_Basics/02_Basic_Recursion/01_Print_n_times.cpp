/*
Problem:Understand Recursion by Printing Something N Times
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:""

==================================================
Complexity Analysis:
Time Complexity: O(N), function is called N times.
Space Complexity: O(N), recursion stack

Approach(Algorithm):
1. If N becomes 0, stop recursion.
2. Print "Hello".
3. Call the function again with N-1.

==================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printHello(int n) {
    if (n == 0) return;
    cout << "Hello\n";
    printHello(n - 1);
}
int main() {
    int n;
    cin >> n;
    printHello(n);
    return 0;
}
