/*
Problem: . Kadane's Algorithm : Maximum Subarray Sum in an Array
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/maximum-subarray/description/"
==================================================
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
==================================================
*/

//Approach 1: Brute Force (Three loops)
/*
#include <bits/stdc++.h>
using namespace std;

int MaxSubarray(vector<int> arr,int n){
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
                maxSum = max(sum,maxSum);
            }
        }
    }
    return maxSum;
}

int main(){
    int n = 9;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = MaxSubarray(arr,n);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^3), where N = size of the array.
    Reason: We are using three nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

//Approach 2: Improved (2 loops) 
/*
#include <bits/stdc++.h>
using namespace std;

int MaxSubarray(vector<int> arr,int n){
    int maxSum = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxSum = max(sum,maxSum);
        }
    }
    return maxSum;
}

int main(){
    int n = 9;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = MaxSubarray(arr,n);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the array.
    Reason: We are using two nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

//Approach 3: Kadane’s Algorithm (O(N))
/*
At any element arr[i], we have two choices:
1. Continue the previous subarray → sum + arr[i]
2. Start a new subarray → arr[i]
Whichever gives the larger sum, we choose that.
Also, if at any point the running sum becomes negative,
we reset it to 0 — because a negative prefix can never help future sums.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int MaxSubarray(vector<int> arr,int n){
    int maxSum = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum > maxSum) maxSum = sum;
        //if sum<0 discard the calculated sum
        if(sum<0) sum = 0;
    }
    return maxSum;
}

int main(){
    int n = 9;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = MaxSubarray(arr,n);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N), where N = size of the array.
    Reason: We are using a single loop running N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

/*
Follow up Question: Print Subarray too
*/

#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // starting index
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "] and ";
    // To consider the sum of the empty subarray
    // uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxi;
}
int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

/*
==================================================
Time Complexity: O(N), where N = size of the array.
    Reason: We are using a single loop running N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/