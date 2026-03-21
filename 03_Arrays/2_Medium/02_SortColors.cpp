/*
Problem: Sort an array of 0s, 1s and 2s
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/sort-colors/description/"

==================================================
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
==================================================
*/

//Approach 1 
// Directly Sorting becuase only three no is there 0,1,2
/*
Complexity Analysis:
    Time Complexity: O(N*logN)
    Space Complexity: O(1)
*/


//Approach 2: Counting Method (a.k.a. Counting Sort for 3 Elements)
/*
Idea:
Count how many 0s, 1s, and 2s exist,
then rewrite the array based on these counts.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    vector<int> arr = {2,0,2,1,1,0};
    int zero_cnt = 0;
    int one_cnt = 0;
    int two_cnt = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == 0) zero_cnt++;
        else if(arr[i] == 1) one_cnt++;
        else two_cnt++;
    }

    for(int i=0;i<zero_cnt;i++) arr[i] = 0;
    for(int i=zero_cnt;i<zero_cnt+one_cnt;i++) arr[i] = 1;
    for(int i=zero_cnt+one_cnt;i<n;i++) arr[i] = 2;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s,
    1’s, 2’s, and second O(N) for placing them correctly in the original array.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

//Approach 3: Dutch National Flag Algorithm (Most Optimal)
#include <bits/stdc++.h>
using namespace std;

void SortColor(vector<int> &arr,int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    int n = 6;
    vector<int> arr = {2,0,2,1,1,0};
    SortColor(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N), where N = size of the given array.
    Reason: We are using a single loop that can run at most N times.
Space Complexity: O(1) as we are not using any extra space
==================================================
*/