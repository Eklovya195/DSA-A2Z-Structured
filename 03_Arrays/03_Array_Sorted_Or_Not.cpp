/*
Problem: Checking if Array is Sorted or not
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.naukri.com/code360/problems/ninja-and-the-sorted-check_6581957?topList=ninjas-sde-sheet&problemListRedirection=true&leftPanelTabValue=PROBLEM"
Leetcode Link:"https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/"
*/

/*
// Approach 1: Brute Force(Don't use it)
#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
            return false;
        }
    }
    return true;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr, n);
    if (ans) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N^2)
Space Complexity: O(1)
==================================================
*/


// Approach 2: Optimal Approach(O(N))
#include<bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
        return false;
    }
    return true;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5}, n = 5;
    bool ans = isSorted(arr,n);
    cout << ans;
    return 0;
}

/*
==================================================
Complexity Analysis(Approach 2):
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/