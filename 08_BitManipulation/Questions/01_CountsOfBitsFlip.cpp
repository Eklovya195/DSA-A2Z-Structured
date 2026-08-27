/*
Problem: 2220. Minimum Bit Flips to Convert Number
Platform: Bit Manipulation / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/"

==================================================
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
==================================================
*/

/*
=================================================
Algorithm:
    To find differing bits between two numbers, compare them bit by bit.
    Use XOR between start and goal.
    XOR produces 1 at positions where the bits are different.
    Each set bit in the XOR result represents one required flip.
    Count the number of set bits in the XOR result to get the answer.
=================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int start = 3;
    int goal = 2;
    int ans = (start^goal);
    int cnt = 0;
    for(int i=0;i<31;i++){
        if(ans&(1<<i)) cnt=cnt+1;
    }
    cout << cnt;
    return 0;
}

/*
=================================================
Time Complexity: O(1), the loop always runs for 32 bits.
Space Complexity: O(1), only constant extra variables are used.
=================================================
*/