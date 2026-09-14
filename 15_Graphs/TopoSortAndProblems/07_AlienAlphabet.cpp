/*
Problem:  Alien Dictionary
Platform: Graph / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/alien-dictionary/1"
==================================================
Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' -> 'd' -> 'a' -> 'c' is a valid ordering.
==================================================
*/

/*
Algorithmm (Topological Sort):
    
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<int> adj(26,0);
        for(int i=0;i<26;i++){
            
        }
        
    }
};

int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    Solution obj;
    string ans = obj.findOrder(words);
    cout << ans;
    return 0;
}

/*
==================================================

==================================================
*/