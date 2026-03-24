/*
Problem: Leaders in Array: Everything in right must be smaller
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1"
==================================================
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
==================================================
*/

//Approach 1: Brute Force 
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int> arr,int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool isLeader = true;
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader) ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    int n = arr.size();
    vector<int> ans = Leaders(arr,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2)
    { Since there are nested loops being used, at the worst case n^2 time would be consumed }.
Space Complexity: O(N) 
    { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
==================================================
*/

//Approach 2: Optimal Approach: Traverse from right
#include <bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int> arr,int n){
    vector<int> ans;
    //approach is traverse from right and check with max from right
    int max = arr[n-1];
    ans.push_back(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        if(arr[i] > max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    //reverse if you want order maintain
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    int n = arr.size();
    vector<int> ans = Leaders(arr,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N)
    {Since the array is traversed single time back to front, it will consume O(N) of time where N = size of the array }.
Space Complexity: O(N) 
    {There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
==================================================
*/