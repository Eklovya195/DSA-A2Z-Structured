/*
Problem: 1482:Minimum no of days to make m Bouquets
Problem Statement:You are given an integer array bloomDay, an integer m and an integer k.
    You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
    The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
    Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
Platform: Binary Search / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/"
==================================================
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
==================================================
*/

/*
==================================================
You have:
● N roses
● An array arr[] where arr[i] = the day the i-th rose will bloom
● You need to make m bouquets
● Each bouquet needs k adjacent bloomed roses
● You can use a rose only if it is already bloomed (its bloom-day ≤ today).
Your goal:
👉 Find the minimum day when you can form at least m bouquets.
👉 If it is impossible, return -1.
What does “adjacent bloomed roses” mean?
If k = 3, you need 3 consecutive roses that have bloomed.
For example:
arr = [7,7,7,7,13,11,12,7]
These are bloom days:
Index: 0 1 2 3 4 5 6 7
Day: 7 7 7 7 13 11 12 7
⭐ Example
Input:
N = 8
arr = {7, 7, 7, 7, 13, 11, 12, 7}
m = 2 (bouquets)
k = 3 (adjacent roses needed)
We must make 2 bouquets, each having 3 adjacent roses.
==================================================
*/

/*
==================================================
❌ Brute Force
1. Check every possible day from min(arr) to max(arr).
2. For each day, check if we can form m bouquets.
3. The first day that works → answer
==================================================
*/

//Time Complexity = O(N × (max-min)) → too large

//✅ Optimal Approach (Binary Search on Days)
/*
==================================================
Algorithm(Approach):
    The answer (minimum day) lies between:
    ● low = minimum bloom day
    ● high = maximum bloom day
    If you can make bouquets on day X,
    ➡️ you can definitely make them on any day > X.
    This monotonic property ⇒ Binary Search.
    Step 1 — Check impossible case
    If m × k > N, immediately return -1.
    K adjacent rose, and aise aise M chaiye
    Step 2 — Binary search on days
    low = min(arr)
    high = max(arr)
    While low <= high:
    1. mid = (low + high) / 2 → guess a day
    2. Check possible(arr, mid, m, k)
    3. If possible → try smaller day (high = mid - 1)
    4. If not possible → need more days (low = mid + 1)
    Final answer → low
    Helper Function: possible(day):
    If arr[i] <= day → rose bloomed
    Else → reset count (not adjacent anymore)
    Each time we find k consecutive bloomed roses, we increment bouquet
    count.
    If bouquets >= m, return true.
==================================================
*/

/*
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long needed = 1LL * m * k;
        if(needed > bloomDay.size()) return -1; //not enough flower

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int bouquets = 0;

        for(int bloom: bloomDay){
            if(bloom <= day){
                cnt++;
                if(cnt == k){
                    bouquets++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return bouquets >= m;
    }
};
*/

/*
Complexity:
==================================================
Time Complexity:
    O(N × log(max(arr) - min(arr)))
    Because:
    ● checking possible() takes O(N)
    ● binary search takes log(range of days)
Space Complexity: O(1)
==================================================
*/