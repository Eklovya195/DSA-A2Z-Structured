//Problem Link: "https://leetcode.com/problems/power-of-two/submissions/2121053051/""

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 16;
    if(n>0 && (n &(n-1)) == 0) cout << "Yes";
    else cout << "No";
    return 0;
}