/*
Problem: Stock Buy And Sell
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/"
==================================================
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
==================================================
*/

//Approach 1: Brute Force (O(N²))
/*
#include <bits/stdc++.h>
using namespace std;

int BuySell(vector<int> arr){
    int n = arr.size();
    int maxProfit = 0;
    int profit = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            profit = arr[j] - arr[i];
            maxProfit = max(profit,maxProfit);
        }
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    int ans = BuySell(arr);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time complexity: O(n^2)
Space Complexity: O(1)
==================================================
*/

//Approach 2: Optimized (My first Thought Process)
/*
#include <bits/stdc++.h>
using namespace std;

int BuySell(vector<int> arr){
    int n = arr.size();
    int min = arr[0];
    int index = 0;
    //finding min element
    for(int i=1;i<n;i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
        }
    }
    int maxProfit = 0;
    int profit = 0;
    for(int i=index+1;i<n;i++){
        if(arr[i] > min){
            profit = arr[i] - min;
        }
        maxProfit = max(profit,maxProfit);
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {7,6,4,3,1};
    int ans = BuySell(arr);
    cout << ans;
    return 0;
}
*/

//Optimized (O(N)) — Kadane’s style
/*
Instead of checking every pair, we can do this in one pass.
Intuition:
    As we traverse, keep track of the lowest price so far (the best day to buy).
    For each price, calculate the potential profit = price - minPriceSoFar.
    Keep track of the maximum profit.
*/
#include <bits/stdc++.h>
using namespace std;

int BuySell(vector<int> arr){
    int n = arr.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        minPrice = min(minPrice,arr[i]);
        maxProfit = max(maxProfit,arr[i]-minPrice);
    }
    return maxProfit;
}

int main(){
    vector<int> arr = {7,1,5,3,6,4};
    int ans = BuySell(arr);
    cout << ans;
    return 0;
}

/*
==================================================
Time complexity: O(n)
Space Complexity: O(1)
==================================================
*/