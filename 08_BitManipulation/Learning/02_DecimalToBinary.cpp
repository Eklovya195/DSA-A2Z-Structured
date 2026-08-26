#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 13;
    string res = "";
    while (n != 0) {
        if (n % 2 == 1) res += '1';
        else res += '0';
        n = n / 2;
    }

    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}

/*
==================================================
Time Complexity: O(logN);
Space Complexity: O(logN)
==================================================
*/