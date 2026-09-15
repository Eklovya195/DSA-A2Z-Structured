/*
Problem: 13. Roman To Integer 
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/roman-to-integer/description/"
==================================================
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
==================================================
*/


/*
Key Idea (Most Important):
    While scanning the string:
        If current value < next value → subtract it
        Else → add it
    Why?
        Smaller numeral before a larger one means subtraction (IV, IX, etc.)

Step-by-Step Algorithm:
    1. Create a map of Roman symbols to values
    2. Initialize ans = 0
    3. Traverse the string from left to right
    4. At index i:
        ○ If i + 1 < n and value(s[i]) < value(s[i+1])
            ■ Subtract value(s[i])
        ○ Else
            ■ Add value(s[i])
    5. Return ans
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map <char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i+1<n && roman[s[i]]<roman[s[i+1]]){
                ans -= roman[s[i]];
            }else{
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};

int main(){
    string s = "MCMXCIV";
    Solution obj;
    cout << obj.romanToInt(s);
    return 0;
}


/*
==================================================
Time Complexity: O(N)
    Single pass through the string
Space Complexity: O(1)
    Fixed-size map (7 symbols)
==================================================
*/