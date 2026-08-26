// Method 1:
/*
Algorithm:
    Initialize a counter to zero.
    While the number is greater than zero:
    Check if the least significant bit (LSB) is 1 by performing bitwise AND with 1.
    If LSB is 1, increment the counter.
    Right shift the number by one bit.
    Return the counter.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 13;
    int cnt = 0;
    while(n!=0){
        cnt += n&1; // same as if(n%2==1) cnt++;
        n = n>>1; //same as n=n/2
    }
    if(n==1) cnt++;
    cout << cnt;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(log n), because each bit of the integer is checked once.
Space Complexity: O(1), only a few variables are used.
==================================================
*/

// Methd 2:Optimal Approach
/*
Algorithm:
    Initialize a counter to zero.
    While the number is greater than zero:
    Check if the least significant bit (LSB) is 1 by performing bitwise AND with 1.
    If LSB is 1, increment the counter.
    Right shift the number by one bit.
    Return the counter.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 13;
    int cnt = 0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
    cout << cnt;
    return 0;
}

/*
==================================================
Time Complexity: O(k), where k is the number of set bits (often faster than checking all bits).
Space Complexity: O(1), only a few variables are used.
==================================================
*/