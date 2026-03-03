/*
Problem: Longest Subarray with given Sum K(Positives)
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399"
==================================================
Example:
Input: nums = [1,2,3], k = 3
Output: 2
*/


/*
//Approach 1: Brute Force — 3 Loops
#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(vector<int> &nums,int k){ 
    int n = nums.size();
    int len = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int K=i;K<=j;K++){
                sum += nums[K];
            }
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

int main() {
    vector < int > nums = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;
    cout << LongestSubarray(nums,k);
    return 0;
}
*/


/*
==================================================
Time Complexity: O(N^3) approx., where N = size of the array.
    Reason: We are using three nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/


/*
//Approach 2: (Better)
#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(vector<int> &nums,int k){ 
    int max_cnt = 0;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            
            if(sum == k){
                int len = j - i + 1;
                max_cnt = max(max_cnt, len);
            }
        }
    }
    return max_cnt;
}
int main() {
    vector < int > nums = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;
    cout << LongestSubarray(nums,k);
    return 0;
}

*/

/*
==================================================
Time Complexity: O(N^2) approx., where N = size of the array.
    Reason: We are using two nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/


/*
//Approach 3: Optimal (using Prefix Sum + Hash Map)
#include <bits/stdc++.h>
using namespace std;

int LongestSubarray(vector<int> &nums,int k){ 
    map<long long,int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            // if the sum = k, update the maxLen:
            if(sum == k) maxLen = max(maxLen,i+1);
            
            // calculate the sum of remaining part i.e. x-k:
            long long rem = sum - k;
            
            //Calculate the length and update maxLen:
            if(preSumMap.find(rem) != preSumMap.end()){
                int len = i-preSumMap[rem];
                maxLen = max(maxLen,len);
            }
            
            //Finally, update the map checking the conditions:
            if(preSumMap.find(sum) == preSumMap.end()){
                preSumMap[sum] = i;
            }
        }
        return maxLen;
}
int main() {
    vector < int > nums = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;
    cout << LongestSubarray(nums,k);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) or O(N*logN) 
    depending on which map data structure we are using, where N = size of the array.
    Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will
    be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time
    complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be
    O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
Space Complexity: O(N) as we are using a map data structure.
==================================================
*/


/*
� Idea
Since all numbers are positive,
we can use a sliding window that expands and shrinks intelligently.
● Add elements to window (increase right)
● If sum > k → shrink from left
● If sum == k → check length
*/

//Approach 4: Sliding Window (Two Pointers) — Only for Positive Numbers
#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }
        return maxLen;
}
int main() {
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


/*
==================================================
Time Complexity: O(2*N), where N = size of the given array.
    Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the
    inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner
    loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N)
    instead of O(N^2).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/
