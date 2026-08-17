/*
Problem: 1011. Capacity To Ship Packages Within D Days
Problem Statement:A conveyor belt has packages that must be shipped from one port to another within days days.
    The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
    We may not load more weight than the maximum weight capacity of the ship.
    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/"
==================================================
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given,
 so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
==================================================
*/

/*
� Brute Force Approach:
Idea:
Try every possible capacity from
max(weights) → sum(weights)
For each capacity:
● Simulate shipping
● Count number of days taken
● First capacity that fits in D days is the answer
Correct but very slow.
==================================================
❌ Brute Force: Time Complexity
O(N * (sum(weights) - max(weights))) approximately O(n^2)
Too slow (sum(weights) can be up to 10^9)
==================================================
*/

//Optimal Approach: (using Binary Search)
#include <bits/stdc++.h>
using namespace std;

long long CalculateDays(vector<int> &weights,int mid,int days){
    long long totalD = 1;
    int sum = 0;
    for(int i=0;i<weights.size();i++){
        if(sum + weights[i] > mid){
            totalD++;
            sum = 0;
        }
        sum += weights[i];  
    }
    return totalD;   
}

long long sumOfElements(vector<int> &weights,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += weights[i];
    }
    return sum;
}

int main(){
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    int n = weights.size();
    int low = *max_element(weights.begin(),weights.end());
    long long high = sumOfElements(weights,n);

    while(low<=high){
        int mid = (low+high)/2;
        int totalDays = CalculateDays(weights,mid,days);
        if(totalDays<=days){
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
Time Complexity: O(log(sum(weights) - max(weights)+1) * N)
Space Complexity: O(1)
==================================================
*/