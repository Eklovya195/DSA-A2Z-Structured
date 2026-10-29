/*
Problem: Fractional Knapsack
Platform: Greedy Algorithms / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm=codolio"
    Another Version:  "https://www.naukri.com/code360/problems/fractional-knapsack_975286?utm=codolio"
==================================================
Given two arrays, val[] and wt[] , representing the values and weights of items, 
and an integer capacity representing the maximum weight a knapsack can hold, 
determine the maximum total value that can be achieved by putting items in the knapsack. 
You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
Hence total price will be 60+100+(2/3)(120) = 240
==================================================
*/

//First Type Question :GFG one
/*
Approach: Optimal Greedy Approach
This greedy choice works because taking the highest ratio first always gives maximum value contribution per unit weight.
Algorithm:
    1. Create items: Combine each item's value and weight into a single structure and 
        calculate its value-to-weight ratio val[i]/wt[i].
    2. Sort items: Sort all items in descending order of their value-to-weight ratio.
    3. Initialize: Set totalVal = 0 to store the maximum value and use the given knapsack capacity.
    4. Select items greedily: Traverse the sorted items. If an item fits completely, add its full value and 
        subtract its weight from the remaining capacity. Otherwise, take the fraction that fits, add its proportional value, and stop.
    5. Return the result: Return totalVal as the maximum obtainable value.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Items structure
   struct Item{
       int val;
       int wt;
       double ratio;
   };
   //sorting 
   static bool comparewhat(Item a,Item b){
       return a.ratio>b.ratio;
   }
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        //initializing Item array
        vector<Item> items(n);
        
        //filling items Array
        for(int i=0;i<n;i++){
            items[i].val = val[i];
            items[i].wt = wt[i];
            items[i].ratio = (double)val[i]/wt[i];
        }
        
        //sorting the item array
        sort(items.begin(),items.end(),comparewhat);
        
        //storing ans in totalVal
        double totalVal = 0.0;
        for(int i=0;i<n;i++){
            if(capacity>=items[i].wt){
                totalVal += items[i].val;
                capacity -= items[i].wt;
            }else{
                totalVal += capacity*items[i].ratio;
                capacity = 0;
                break;
            }
        }
        return totalVal;
    }
};


int main(){
    vector<int> val = {500};
    vector<int> wt = {30};
    int capacity = 10;
    Solution obj;
    cout << obj.fractionalKnapsack(val,wt,capacity);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(n) + O(nlogn) + O(n)
    calculationg ratio + sorting + traversing items
Space Complexity: O(n)
    item vector used n space 
==================================================
*/


//Second Type Qus : Code Studio
//here val and wt are given as vector pair 
// #include <bits/stdc++.h>
// struct Item{
//     int val;
//     int wt;
//     double ratio;
// };

// static bool compare(Item a,Item b){
//     return a.ratio>b.ratio;
// }

// double maximumValue (vector<pair<int, int>>& items, int n, int w)
// {
//     //initialise and store val in our arr
//     vector<Item> arr(n);
//     for(int i=0;i<n;i++){
//         arr[i].val = items[i].second;
//         arr[i].wt = items[i].first;
//         arr[i].ratio = (double)items[i].second/items[i].first;
//     }

//     //sort the arr
//     sort(arr.begin(),arr.end(),compare);

//     double totalVal = 0.0;
//     for(int i=0;i<n;i++){
//         if(w>=arr[i].wt){
//             totalVal += arr[i].val;
//             w -= arr[i].wt;
//         }else{
//             totalVal += arr[i].ratio*w;
//             w = 0;
//             break;
//         }
//     }
//     return totalVal;
// }