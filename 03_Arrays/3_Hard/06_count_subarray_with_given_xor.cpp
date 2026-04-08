/*
Problem:  Count Subarray(contiguous) with given xor as k
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1"
==================================================
Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
==================================================
*/

//Approach 1: Brute force O(N^3)
//Har subarray [i..j] ka sum inner loop se nikaalo. (Slow)

/*
#include <bits/stdc++.h>
using namespace std;

int SubArrayXor(vector<int> &arr,int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int Xor = 0;
            for(int m=i;m<=j;m++){
                Xor = Xor^arr[m];
            }
            if(Xor == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,1,1,1};
    int n = arr.size();
    int k = 4;
    int ans = SubArrayXor(arr,n,k);
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

int SubArrayXor(vector<int> &arr,int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        int Xor = 0;
        for(int j=i;j<n;j++){
            Xor = Xor^arr[j];
            if(Xor == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    int k = 6;
    int ans = SubArrayXor(arr,n,k);
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

int SubArrayXor(vector<int> &arr,int n,int k){
    int cnt = 0;
    map<int,int> mp;
    // mp<frontxor,cnt>
    //formula used is Xor = x^k
    int xr = 0; //frontxor
    mp[xr]++;
    for(int i=0;i<n;i++){
        xr = xr ^ arr[i];
        int x = xr^k;
        if(mp.find(x) != mp.end()){
            cnt += mp[x];
        }
        mp[xr] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();
    int k = 6;
    int ans = SubArrayXor(arr,n,k);
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