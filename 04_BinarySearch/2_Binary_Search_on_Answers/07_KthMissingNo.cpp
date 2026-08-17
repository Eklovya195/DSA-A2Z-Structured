/*
Problem: 1539. Kth Missing Positive Number
Problem Statement:Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
Platform: Binary Search / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/kth-missing-positive-number/description/"
==================================================
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. 
The 5th missing positive integer is 9.
==================================================
*/

//Brute Force Approach
/*
implementation: increment k for each arr[i] <= k.
Eg: if arr = {1,2,3,4} and k = 2
1) because arr[0]<k or 1<2 then k++ j will became 3
2) now arr[1]<k or 2<3 then again k++
and repeat this...
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4};
    int k = 2;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] <= k) k++;
        else break;
    }
    cout << k;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/

//Optimal Approach (Using Binary Search)
/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return k + high + 1;
    }
};
*/

/*
==================================================
Time Complexity: O(logN)
Space Complexity: O(1)
==================================================
*/