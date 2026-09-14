/*
Problem: 451. Sort Characters by Frequency
Problem Statement: Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
    Return the sorted string. If there are multiple answers, return any of them.
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/sort-characters-by-frequency/description/"
==================================================
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
==================================================
*/

//This is wrong approach for leetcode problem
//beacuse here freq[26] is not enough as question had Uppercase alphabets also 
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        pair<int,char> freq[26];
        //initialize
        for(int i=0;i<26;i++){
            freq[i] = {0,char('a'+i)};
        }

        //count freq of each element
        for(char c:s){
            freq[c-'a'].first++;
        }
        //sort the frequency
        sort(freq,freq+26,greater<pair<int,char>>());

        //print result
        string ans = "";
        for(int i=0;i<26;i++){
            ans += string(freq[i].first,freq[i].second);
        }
        return ans;
    }
};

int main(){
    string s = "tree";
    Solution obj;
    string ans = obj.frequencySort(s);
    cout << ans;
    return 0;
}
*/


//Use Unordered map
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        //count freq of each element
        for(char c:s){
            mp[c]++;
        }
 
        // Move map elements to vector
        vector<pair<char,int>> freq;

        for(auto it : mp){
            freq.push_back({it.first, it.second});
        }

        // Sort by frequency in descending order
        sort(freq.begin(), freq.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // Build answer
        string ans = "";
        for(auto it : freq){
            ans += string(it.second, it.first);
        }

        return ans;
    }
};

int main(){
    string s = "tree";
    Solution obj;
    string ans = obj.frequencySort(s);
    cout << ans;
    return 0;
}


/*
==================================================
Time: O(n + k log k)
Space: O(n + k), or effectively O(n) for the output
==================================================
*/