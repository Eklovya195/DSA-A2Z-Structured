/*
Problem: 1283: Find the Smallest Divisor Given a Threshold
Problem Statement:Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
    Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
    Each result of the division is rounded to the nearest integer greater than or equal to that element.
    (For example: 7/3 = 3 and 10/2 = 5).
    The test cases are generated so that there will be an answer.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/"
==================================================
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
==================================================
*/

/*
Brute Force Idea (very slow)
1. Try every divisor d from 1 to max(arr[]).
2. Compute the sum of ceil(arr[i]/d).
3. Return smallest d satisfying condition.
==================================================
Time Complexity: O(max(arr) * N) → too slow for large values
Space Complexity: O(1)
==================================================
*/

//cautious code gives TLE not used
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {44,22,33,11,1};
    int threshold = 5;
    int ans = 1;
    do{
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum += ceil((double)nums[i]/(double)ans);
        }
        if(totalSum<=threshold) break;
        ans++;

    }while(true);
    cout << ans;
    return 0;
}
*/

//optimal Approach (Using Binary search)
/*
As divisor increases → sum decreases
This is a monotonic function, perfect for binary search.
low = 1
high = max(arr)
*/
#include <bits/stdc++.h>
using namespace std;

long long CalculateSum(vector<int> &nums,int mid,int n){
    long long totalS = 0;
    for(int i=0;i<n;i++){
        totalS += ceil((double)nums[i]/(double)mid);
    }
    return totalS;
}

int findMaxEle(vector<int> &nums,int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,5,9};
    int n = nums.size();
    int threshold = 6;
    int low = 1;
    int high = findMaxEle(nums,n);

    while(low<=high){
        int mid = (low+high)/2;
        long long totalSum = CalculateSum(nums,mid,n);
        if(totalSum<=threshold){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << low;
    return 0;
}

/*
==================================================
Time Complexity: O(log(max(arr)) * N)
Space Complexity: O(1)
==================================================
*/