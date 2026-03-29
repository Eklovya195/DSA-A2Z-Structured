/*
Problem:  Majority Elemet ||(>N/3 times) | Find the elements that appears more than N/3 times in the array
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/majority-element-ii/description/"
//similar problem
Also refer: "https://leetcode.com/problems/majority-element/description/"
==================================================
Input: nums = [3,2,3]
Output: [3]
==================================================
*/

//Approach 1: Brute Force
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> MajorElement(vector<int> arr,int n){
    vector<int> ls;
    for(int i=0;i<n;i++){
        //if list is empty or 
        //new element is not equal to previous counted one
        if(ls.size() == 0 || ls[0] != arr[i]){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(arr[j] == arr[i]){
                    cnt++;
                }
            }
            //checking if cnt > n/3
            if(cnt > n/3){
                ls.push_back(arr[i]);
            }
        }
        //list has max 2 element
        if(ls.size() == 2){
            break;
        }
    }
    return ls;
}

int main(){
    vector<int> arr = {1,2};
    int n = arr.size();
    vector<int> ans = MajorElement(arr,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the given array.
    Reason: For every element of the array the inner loop runs for N times. And there are N elements in the
    array. So, the total time complexity is O(N^2).
Space Complexity: O(1) as we are using a list that stores a maximum of 2 elements. The space used is
so small that it can be considered constant.
==================================================
*/

//Better Approach: Hash map / unordered_map
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> MajorElement(vector<int> arr,int n){
    vector<int> ls;
    map<int,int> mp;
    int mini = int(n/3) + 1;
    for(int i=0;i<n;i++){
        //counting
        mp[arr[i]]++;
        //checking
        if(mp[arr[i]] == mini){
            ls.push_back(arr[i]);
        }
        //list size is of max 2
        if(ls.size() == 2) break;
    }
    return ls;
}

int main(){
    vector<int> arr = {3,2,3};
    int n = arr.size();
    vector<int> ans = MajorElement(arr,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O(N*logN), where N = size of the given array.
    Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it
    for N elements. So, it results in the first term O(N*logN).
    If we use unordered_map instead, the first term will be O(N) for the best and average case and for the
    worst case, it will be O(N^2).
Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a
    maximum of 2 elements. That space used is so small that it can be considered constant.
====================================================================================================
*/

//Optimal Approach: Extended Boyer–Moore 
#include <bits/stdc++.h>
using namespace std;

vector<int> MajorElement(vector<int> nums,int n){
        int cnt1 = 0,cnt2 = 0;
        int el1,el2;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1 = 0,cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        int mini = int(n/3)+1;
        if(cnt1 >= mini) ls.push_back(el1);
        if(cnt2 >= mini) ls.push_back(el2);
        return ls;
}

int main(){
    vector<int> nums = {3,2,3};
    int n = nums.size();
    vector<int> ans = MajorElement(nums,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N) + O(N), where N = size of the given array.
    Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second
    one is to check if the calculated elements are the majority ones or not.
Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space
    used is so small that it can be considered constant
==================================================
*/