/*
Problem:  Count Subarray(contiguous) sum Equals K
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/subarray-sum-equals-k/description/"
==================================================
Input: nums = [1,2,3], k = 3
Output: 2
==================================================
*/

//Approach 1: Brute force O(N^3)
//Har subarray [i..j] ka sum inner loop se nikaalo. (Slow)
/*
#include <bits/stdc++.h>
using namespace std;

int SubArraySum(vector<int> &arr,int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int m=i;m<=j;m++){
                sum += arr[m];
            }
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int k = 3;
    int ans = SubArraySum(arr,n,k);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^3), where N = size of the array.
    Reason: We are using three nested loops here. Though all are not running for exactly N times, the time
    complexity will be approximately O(N^3).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

//Approach 2: Better (O(N^2))
/*
#include <bits/stdc++.h>
using namespace std;

int SubArraySum(vector<int> &arr,int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == k){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3,-3};
    int n = arr.size();
    int k = 3;
    int ans = SubArraySum(arr,n,k);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the array.
    Reason: We are using two nested loops here. As each of them is running for exactly N times, the time
    complexity will be approximately O(N^2).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/


//Approach 3: Optimal (Prefix-sum + Hash) O(N) avg
#include <bits/stdc++.h>
using namespace std;

int SubArraySum(vector<int> &arr,int n,int k){
    int cnt = 0;
    map<int,int> mp;
    mp[0] = 1;
    int presum = 0;
    for(int i=0;i<n;i++){
        presum += arr[i];
        int remove = presum - k;
        if(mp.find(remove) != mp.end()){
            cnt += mp[remove];
        }
        mp[presum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int k = 3;
    int ans = SubArraySum(arr,n,k);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N =
size of the array.
    Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will
    be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least
    complexity will be O(N) as we are using a loop to traverse the array.
Space Complexity: O(N) as we are using a map data structure.
==================================================
*/