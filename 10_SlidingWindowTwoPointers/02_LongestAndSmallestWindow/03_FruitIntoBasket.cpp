/*
Problem: 904. Fruit Into Baskets
Platform: Sliding Window And Two pointers / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/fruit-into-baskets/description/"
==================================================
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
==================================================
*/

/*
Problem Statement: 
    You are given an array fruits where fruits[i] represents the type of fruit on the i-th tree.
    You have only two baskets, and each basket can store only one type of fruit, but in unlimited quantity.
    You can start picking fruits from any tree, but once you start, you must move only to the right, picking exactly one fruit from each tree.
    If you encounter a fruit type that cannot fit into your two baskets, you must stop.
    Your task is to return the maximum number of fruits you can collect following these rules.
*/

//Appraoch 1: Brute force 
/*
Algorithm:
    Try starting from every index.
    From each start index, move right and collect fruits.
    Keep track of fruit types using a map or set.
    Stop when more than 2 fruit types are encountered.
    Track the maximum number of fruits collected.
*/

/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxcnt = 0;
        for(int start=0;start<n;start++){
            set<int> st;
            int cnt = 0;
            for(int end=start;end<n;end++){
                st.insert(fruits[end]);
                if(st.size()>2) break;
                cnt++;
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;
    }
};

int main(){
    vector<int> fruits = {1,2,3,2,2};
    Solution obj;
    cout << obj.totalFruit(fruits);
    return 0;
}
*/


/*
==================================================
Time Complexity: O(n²)
    st.insert take logn time but here n = 3 therfore 
    constant time 
Space Complexity: O(1)
    at most 3 fruit types in set so constant
==================================================
*/

//Better Approach (Sliding Window with set)
/*
Algorithm:
    Use a sliding window with two pointers left and right.
    Maintain a hash map to count fruit types in the current window.
    Expand window to the right.
    If fruit types exceed 2, shrink window from the left.
    Track the maximum window size.
*/
/*
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;
        int l=0,r=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                    l++;
                }
            }
            if(mp.size()<=2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    vector<int> fruits = {1,2,3,2,2};
    Solution obj;
    cout << obj.totalFruit(fruits);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*n)
Space Complexity: O(1)
    at most 2 fruit types in map so constant
==================================================
*/


//Optimal Approach 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;
        int l=0,r=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[fruits[r]]++;
            //just here changes and remove the while loop
            //time complexity reduces from 2*n -> n
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

int main(){
    vector<int> fruits = {1,2,3,2,2};
    Solution obj;
    cout << obj.totalFruit(fruits);
    return 0;
}

/*
==================================================
Time Complexity: O(n)
Space Complexity: O(1)
    at most 2 fruit types in map so constant
==================================================
*/
