/*
Problem:Understand Recursion by Printing name N Times
Platform: Basic Recursion / Striver A2Z
Difficulty: Easy
Practice Link:""

==================================================
Complexity Analysis:
Time Complexity: O(N)
Space Complexity: O(N)

Approach(Algorithm):
1. If N == 0, stop.
2. Print the name
3. Call the function with N-1

==================================================
*/

#include <bits/stdc++.h>
using namespace std;

void printName(int n) {
    if (n == 0) return;
    cout << "Eklovya\n";
    printName(n - 1);
}
int main() {
    int n;
    cin >> n;
    printName(n);
    return 0;
}
