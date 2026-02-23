/*
Problem:Basic Hashing
Platform: Basic Hashing / Striver A2Z
Difficulty: Easy

==================================================
Hashing is a technique used to store and retrieve data efficiently.
It maps data (keys) to a fixed-size array using a hash function, which allows fast access.
The main idea is:
● Convert a value into an index using a hash function
● Store the value at that index
● Retrieve it in constant time
Hashing is mainly used for frequency counting, searching, and lookup operations.

==================================================
Complexity Analysis:
Time Complexity: O(N) average case
Space Complexity: O(N) for hash table

Approach(Algorithm):
1. Create a hash table (array, map, or unordered_map).
Prepared by Vinay Kajla Instagram: @Vinay.Kajla_
2. Traverse the input data.
3. For each element:
○ Use it as a key in the hash table.
○ Increase its count.
4. The hash table now stores frequency or presence information.
Hashing helps avoid nested loops and reduces time complexity.

==================================================
Example
Array: [1, 2, 2, 3, 1]
We want to know how many times each number appears.
Using hashing:
● 1 → 2 times
● 2 → 2 times
● 3 → 1 time

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // // int array hashing
    // int n;
    // cin >> n;
    // int arr[n];
    // // give array input 
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // //creating hash table/array
    // int hash[7] = {0};  //size of hash>6(largest number)
    // for(int i=0;i<n;i++){
    //     hash[arr[i]] += 1;
    // }
    // //input you want to check
    // int q;
    // cin >> q;
    // while(q--){
    //     int num;
    //     cin >> num;
    //     //fetch
    //     cout << hash[num] << endl;
    // }
    

    //character hashing
    // string s;
    // cin >> s;
    // int n;
    // cin >> n;
    // int hash[26] = {0};
    // for(int i=0;i<s.size();i++){
    //     hash[s[i]-'a']++;
    // }
    // while(n--){
    //     char ch;
    //     cin >> ch;
    //     //fetching
    //     cout << hash[ch-'a'] << " ";
    // }


    // Hashing using ordered map
    // int n;
    // cin >> n;
    // int arr[n];
    // // give array input 
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // //creating hash table/array(precompute)
    // map<int,int> mpp;  //size of hash>6(largest number)
    // for(int i=0;i<n;i++){
    //    mpp[arr[i]]++;
    // }
    // //iterate in the map
    // for(auto it : mpp){
    //     cout << it.first << "->" << it.second << endl;
    // }
    // //input you want to check
    // int q;
    // cin >> q;
    // while(q--){
    //     int num;
    //     cin >> num;
    //     //fetch
    //     cout << mpp[num] << endl;
    // }

    //hashing using unoredered_map
    // int n;
    // cin >> n;
    // int arr[n];
    // // give array input 
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // //creating hash table/array(precompute)
    // unordered_map<int,int> mpp;  //size of hash>6(largest number)
    // for(int i=0;i<n;i++){
    //    mpp[arr[i]]++;
    // }
    // //iterate in the map
    // for(auto it : mpp){
    //     cout << it.first << "->" << it.second << endl;
    // }
    // //input you want to check
    // int q;
    // cin >> q;
    // while(q--){
    //     int num;
    //     cin >> num;
    //     //fetch
    //     cout << mpp[num] << endl;
    // }

    
    return 0;
}
