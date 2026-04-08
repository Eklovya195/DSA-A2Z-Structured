/*
Problem:  Merge Overlapping Intervals
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/merge-intervals/description/"
==================================================
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
==================================================
*/

// Approach 1: Truly Brute Force (O(N²)) — without sorting
/*

*/

//Approach 2: 
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MergeIntervals(vector<vector<int>> &arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= end){
                end = max(end,arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    int n = arr.size();
    vector<vector<int>> ans = MergeIntervals(arr,n);
    for (auto &row : ans) {
        cout << row[0] << " " << row[1] << endl;
    }
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*logN) + O(2*N), we sort the entire array and then merge them in a single pass.
Space Complexity: ON), additonal space used to store the non-overlapping intervals.
==================================================
*/


//Approach 3: Optimal — Sort + Single Pass (O(N log N))
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MergeIntervals(vector<vector<int>> &arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(arr[i][1],ans.back()[1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
    int n = arr.size();
    vector<vector<int>> ans = MergeIntervals(arr,n);
    for (auto &row : ans) {
        cout << row[0] << " " << row[1] << endl;
    }
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*logN) + O(N), we sort the entire array and then merge them in a single pass.
Space Complexity: ON), additonal space used to store the non-overlapping intervals.
==================================================
*/