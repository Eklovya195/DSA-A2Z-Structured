/*
Problem: Longest Subarray with given Sum K(Positives & Negatives)
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1"
==================================================
Example:
Input: [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10].
    The length of the longest subarray with a sum of 15 is 6.
*/


/*
// Brute Force
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }
            if (s == k)
            len = max(len, j - i + 1);
        }
    }
    return len;
}
int main()
{
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
*/

/*
Time Complexity: O(N3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
*/


/*
// Brute force se thoda behtar
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.
    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        int s = 0;
        for (int j = i; j < n; j++) { // ending index
        // add the current element to
        // the subarray a[i...j-1]:
        s += a[j];
        if (s == k)
            len = max(len, j - i + 1);
        }
    }
    return len;
}
int main()
{
vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
*/

/*
Time Complexity: O(N^2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
*/



/*
Core idea (Prefix sum + map)
Let pref[i] = a[0] + a[1] + ... + a[i].
Agar kisi index i par pref[i] = S hai, aur pehle kabhi pref[j] = S - K mila tha (j < i),
to subarray (j+1 ... i) ka sum K hoga (kyunki pref[i] - pref[j] = K).
Isi liye:
● Har prefix sum ka pehla index map me store karo (max length chahiye, isliye first occurrence hi best hota hai).
● Har step par rem = pref - K dekho: agar rem pehle dikha, to length = i - firstIndex[rem].
*/

// Optimal code (use unordered_map for O(N) avg)
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];
        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;
        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
int main() {
    vector<int> a = { -1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

/*
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N =
size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will
be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time
complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be
O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
Space Complexity: O(N) as we are using a map data structure.

*/