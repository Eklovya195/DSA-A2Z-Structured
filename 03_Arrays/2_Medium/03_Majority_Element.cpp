/*
Problem: Find the Majority Element that occurs more than N/2 times
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/majority-element/description/"
Code Studio: "https://www.naukri.com/code360/problems/majority-element_842495"
==================================================
Input: nums = [2,2,1,1,1,2,2]
Output: 2
==================================================
*/

//Approach 1: Brute Force 
/*
#include <bits/stdc++.h>
using namespace std;

int MajorElement(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == arr[i]){
                cnt++;
            }
        }
        if(cnt > n/2) return arr[i];
    }
    return -1;
}

int main(){
    int n = 7;
    vector<int> arr = {2,2,1,1,1,2,2};
    int ans = MajorElement(arr,n);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the given array. Reason: For every element of the array the
    inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2).
Space Complexity: O(1) as we use no extra space
==================================================
*/

//Approach 2: Hash/Map Method
/*
#include <bits/stdc++.h>
using namespace std;

int MajorElement(vector<int> arr,int n){
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        if(it.second > (n/2)) return it.first;
    }
    return -1;
}

int main(){
    int n = 7;
    vector<int> arr = {2,2,1,1,1,2,2};
    int ans = MajorElement(arr,n);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N*logN) + O(N), where N = size of the given array.
    Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it
    for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element
    occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the
    best and average case and for the worst case, it will be O(N2).
Space Complexity: O(N) as we are using a map data structure.
==================================================
*/


//Approach 3: Boyer–Moore Majority Vote (⭐ optimal)
#include <bits/stdc++.h>
using namespace std;

int MajorElement(vector<int> arr,int n){
    int el;
    int cnt = 0;
    //calculate the count and find the expected majority element
    for(int i=0;i<n;i++){
        if(cnt == 0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    //checking if the expected element is the majority one or not
    for(int i=0;i<n;i++){
        if(arr[i] == el){
            cnt1++;
        }
    }
    //if excepted element is majority then return that element
    if(cnt1 > (n/2)) return el;
    return -1;
}

int main(){
    int n = 7;
    vector<int> arr = {2,2,1,1,1,2,2};
    int ans = MajorElement(arr,n);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N) + O(N), where N = size of the given array.
    Reason: The first O(N) is to calculate the count and find the expected majority element. The second one
    is to check if the expected element is the majority one or not.

    Note: If the question states that the array must contain a majority element, in that case, we do not need
    the second check. Then the time complexity will boil down to O(N).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/