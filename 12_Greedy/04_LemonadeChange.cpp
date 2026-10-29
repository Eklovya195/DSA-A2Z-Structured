/*
Problem: 860. Lemonade Change
Platform: Greedy Algorithms / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/lemonade-change/description/?utm=codolio"
==================================================
You are given an array bills where each element represents the bill a customer pays with.
Each lemonade costs 5$. Customers can only pay using 5$, 10$, or 20$ bills.
Initially, you have no change.
Your task is to determine whether you can provide the correct change to every customer in
order.
Return true if possible, otherwise return false.

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
==================================================
*/

/*
Approach: Optimal Greedy Approach
Algorithm
    We simulate the process of giving change to each customer using a greedy strategy.
    Steps:
    1. Maintain two counters:
        ○ five → number of 5$ bills
        ○ ten → number of 10$ bills
    2. Traverse the bills array one by one:
        ○ If the bill is 5:
            ■ No change needed, increment five.
        ○ If the bill is 10:
            ■ We must give one 5$ as change.
            ■ If five > 0, decrement five and increment ten.
            ■ Otherwise, return false.
        ○ If the bill is 20:
            ■ We need to give 15$ change.
            ■ Prefer giving one 10$ and one 5$ (best option).
            ■ If not possible, try giving three 5$ bills.
            ■ If neither is possible, return false.
    3. If all customers are processed successfully, return true
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int cnt5 = 0,cnt10 = 0;
        for(int i=0;i<n;i++){  //O(n)
            if(bills[i] == 5) cnt5++;
            else if(bills[i] == 10){
                cnt10++;
                if(cnt5) cnt5--;
                else return false;
            }
            else{
                if(cnt10 && cnt5){
                    cnt10--;
                    cnt5--;
                }
                else if(cnt5 >= 3){
                    cnt5 = cnt5-3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    vector<int> bills = {5,5,5,10,20};
    Solution obj;
    cout << boolalpha << obj.lemonadeChange(bills);
    return 0;
}


/*
==================================================
Complexity Analysis:
    Time Complexity: O(n)
    Space Complexity: O(1)
==================================================
*/
