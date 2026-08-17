/*
Problem: 875.Koko Eating Bananas
Problem Statement: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, 
    she eats all of them instead and will not eat any more bananas during this hour.
    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
    Return the minimum integer k such that she can eat all the bananas within h hours
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/koko-eating-bananas/description/"
==================================================
Input: piles = [3,6,7,11], h = 8
Output: 4
==================================================
*/

// Brute Force Approach — O(M)
// Try every number from 1 to M and check if iⁿ == M.
// Stop if iⁿ > M.
/*
int nthRoot(int n, int m) {
    for (int i = 1; i <= m; i++) {
        long long power = pow(i, n);
        if (power == m) return i;
        if (power > m) break;
    }
    return -1;
}
*/

/*
Complexity:
==================================================
    Time: O(M)
    Space: O(1)
==================================================
*/



//Cautious Approach(Time Limit Exceed therefor not used)
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h=6;
    vector<int> piles = {30,11,23,4,20};
    int n = piles.size();
    
    int k = 1;
    do{
        int total_hours = 0;
        for(int i=0;i<n;i++){
            if(piles[i]%k==0) total_hours += piles[i]/k;
            else total_hours += (piles[i]/k)+1;
        }
        if(total_hours<=h){
            cout << k;
            break;
        }
        k++;
    }while(true);
    return 0;
}
*/


//Optimal Approach (Using Binary Search)
/*
Approach:
If a speed k works (finishes in ≤ h hours), then every k' > k also works. So the answer lies in
[1, max(piles)] and we can binary-search that answer space. For a candidate k compute
total hours sum( ceil(pile/k) ).
Important edge case
Because each pile requires at least one hour, total hours ≥ n. If h < n, no possible k can
finish (each pile requires distinct hour) — return -1 (or handle per problem spec). I include that
check in the implementations.
Key micro-optimizations
● Use integer formula hours += (pile + k - 1) / k to compute ceil(pile/k)
using integers (no floats).
● Early stop while summing hours if hours > h — saves work for slow candidates.
● Use long long for hour sums to avoid overflow on large inputs.

*/
#include <bits/stdc++.h>
using namespace std;

int findMaxEle(vector<int> &piles,int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,piles[i]);
    }
    return maxi;
}

long long CalculateTotalHours(vector<int> &piles,int k){
    long long totalH = 0;
    int n = piles.size();
    for(int i=0;i<n;i++){
        totalH += ceil((double)piles[i]/(double)k);
    }
    return totalH;
}

int main(){
    int h=1000000000;
    vector<int> piles = {805306368,805306368,805306368};
    int n = piles.size();
    int low = 1;
    int high = findMaxEle(piles,n);
    while(low<=high){
        int mid = (low+high)/2;
        long long total_hours = CalculateTotalHours(piles,mid);
        if(total_hours<=h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << low;
    return 0;
}

/*
Complexity:
====================================================================================================
    Time: O(n log M) n = number of piles, M = maximum pile size
    Space: O(1)
====================================================================================================
*/