/*
Problem: Two Sum: Check if a pair with given sum exists in Array
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/two-sum/description/"

==================================================
Input:
arr = [2, 6, 5, 8, 11]
target = 14
Output: YES
(6 + 8 = 14)
==================================================
*/

//Approach 1: Brute Force (Nested Loops)
//Check every pair (i, j) and see if their sum equals target

//Variety 1
/*
#include <bits/stdc++.h>
using namespace std;
string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}
int main(){
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << ans << endl;
    return 0;
}
*/
/*
Time Complexity: O(N^2), where N = size of the array.
    Reason: There are two loops(i.e. nested) each running for approximately N times.
Space Complexity: O(1) as we are not using any extra space.
*/

//Variety 2
/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,target;
    cin >> n >> target;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                cout << "["<< i << "," << j << "]";
                return 0; // exit whole program
            }
        }
    }
    cout << "No pair found";
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the array.
    Reason: There are two loops(i.e. nested) each running for approximately N times.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

//Approach 2: Hash Map (Optimal)
/*
//Variety 1
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n,vector<int> arr,int target){
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int rem = target - a;
        if(mp.find(rem) != mp.end()){
            return "YES";
        }
        mp[a] = i;
    }
    return "NO";
}

int main(){
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << ans << endl;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N), where N = size of the array.
    Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So
    the time complexity is O(N).
    Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In
    that case, the time complexity will be O(N^2). If we use map instead of unordered_map, the time
    complexity will be O(N* logN) as the map data structure takes logN time to find an element.
Space Complexity: O(N) as we use the map data structure.
    Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map
    data structure, then we should move on to the following approach i.e. two pointer approach. This
    approach will have the same time complexity as the better approach.
==================================================
*/

//Variety 2
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n,vector<int> arr,int target){
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int rem = target - a;
        if(mp.find(rem) != mp.end()){
            return {mp[rem],i};
        }
        mp[a] = i;
    }
    return {};
}

int main(){
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "[" << ans[0] << "," << ans[1] << "]"; 
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N), where N = size of the array.
    Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So
    the time complexity is O(N).
    Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In
    that case, the time complexity will be O(N^2). If we use map instead of unordered_map, the time
    complexity will be O(N* logN) as the map data structure takes logN time to find an element.
Space Complexity: O(N) as we use the map data structure.
==================================================
*/

//Approach 3 : Two Pointer(sort the array then use)
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n,vector<int> arr,int target){
    sort(arr.begin(),arr.end());
    int left = 0, right = n-1;
    while(left < right){
        int sum = arr[left]+arr[right];
        if(sum == target) return "YES";
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}

int main(){
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << ans; 
    return 0;
}

/*
==================================================
Note: For variant 2, we can store the elements of the array along with its index in a new array. Then the
rest of the code will be similar. And while returning, we need to return the stored indices instead of
returning “YES”. But for this variant, the recommended approach is approach 2 i.e. hashing approach.
Time Complexity: O(N) + O(N*logN), where N = size of the array.
    Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.
Space Complex: O(1)
==================================================
*/