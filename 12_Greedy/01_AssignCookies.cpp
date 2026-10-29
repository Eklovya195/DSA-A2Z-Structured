/*
Problem: 455. Assign Cookies
Platform: Greedy Algorithms / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/assign-cookies/submissions/2184107347/?utm=codolio"
==================================================
You are given two arrays:
● student[] where student[i] is the minimum cookie size needed by the i-th student
● cookie[] where cookie[j] is the size of the j-th cookie
Each student can receive at most one cookie, and a cookie can be assigned only if
cookie[j] >= student[i].
Your task is to maximize the number of students who receive a cookie.

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
==================================================
*/

// Note: You can do it with dp also but it will take O(m*n) time and it will be a 2D DP problem
//that is not even optimal approach 

/*
Approach: Optimal Greedy Approach (Two Pointers)
    Algorithm
    To maximize satisfied students:
    ● Give the smallest sufficient cookie to the least greedy student.
    Steps:
    1. Sort both student and cookie arrays.
    2. Use two pointers:
        ○ One for students
        ○ One for cookies
    3. If current cookie satisfies current student:
        ○ Assign it and move both pointers.
    4. Otherwise:
        ○ Move to the next cookie
    5. Count how many students are satisfied
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int cnt = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                cnt++;
                i++; 
            }
            j++;
        }
        return cnt;
    }
};

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    Solution obj;
    cout << obj.findContentChildren(g,s);
    return 0;
}


/*
==================================================
Complexity Analysis:
    Time Complexity: O(n log n + m log m ) due to sorting
    Space Complexity: O(1)
==================================================
*/
