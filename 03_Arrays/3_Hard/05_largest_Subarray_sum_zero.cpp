/*
Problem:  Largest Subarray with Sum Equal to Zero
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1"
==================================================
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
==================================================
*/

//Brute Force: (O(n^2))
/*
#include <bits/stdc++.h>
using namespace std;

int LargestSubarray(int arr[],int n){
    int max_cnt = 0;

    for(int i=0;i<n;i++){
        int sum = 0;
        
        for(int j=i;j<n;j++){
            sum += arr[j];
            
            if(sum == 0){
                int cnt = j-i+1;
                max_cnt = max(cnt,max_cnt);
            }
        }
    }
    return max_cnt;
}

int main(){
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = LargestSubarray(arr,n);
    cout << ans;
    return 0;
}
*/


/*
==================================================
Time Complexity: O(N^2) as we have two loops for traversal
Space Complexity: O(1) as we aren’t using any extra space.
==================================================
*/

//Optimal Approach : (Using HashMap)
/*
1. Maintain a variable sum = 0 (prefix sum).
2. Traverse array ke har element par:
    sum += A[i]
    Agar sum == 0, matlab start se i tak sum 0 hua ⇒ max_len = i + 1
    Agar sum pehle bhi map me mila, matlab pehle se koi prefix sum same tha.
    beech ka portion ka sum zero hoga.
    Length = i - mp[sum]
    max_len = max(max_len, i - mp[sum])
    Agar sum pehli baar aaya hai ⇒ mp[sum] = i store kar lo.
3. End me max_len return karo.
*/
#include <bits/stdc++.h>
using namespace std;

int LargestSubarray(int arr[],int n){
    unordered_map<int,int> mp;
    int max_len = 0;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum == 0){
            max_len = i+1;
        }
        if(mp.find(sum) != mp.end()){
            max_len = max(max_len,i-mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }
    return max_len;
}

int main(){
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = LargestSubarray(arr,n);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N), as we are traversing the array only once
Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
==================================================
*/