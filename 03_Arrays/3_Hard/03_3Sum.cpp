/*
Problem:  3Sum
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/3sum/description/"
====================================================================================================
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
====================================================================================================
*/

//Approach 1: Brute force (O(N³))
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int> arr,int n){
    vector<vector<int>> ans;
    set<vector<int>> st; //to avoid duplicates
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp ={arr[i],arr[j],arr[k]};
                    sort(temp.begin(), temp.end());  // normalize order
                    st.insert(temp); // set removes duplicates
                }
            }
        }
    }

    // move unique triplets from set to answer
    for(auto &it : st){
        ans.push_back(it);
    }

    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(arr,n);
    for(auto &row:ans){
        for(auto val:row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^3 * log(no. of unique triplets)), where N = size of the array.
    Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of
    unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just
    sorting 3 elements every time.
Space Complexity: O(2 * no. of the unique triplets) 
    as we are using a set data structure and a list to store the triplets.
==================================================
*/

//Aproach 2: Two loops + hash set (O(N²))
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int> arr,int n){
    set<vector<int>> st; //to avoid duplicates
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp); // set removes duplicates
            }
            hashset.insert(arr[j]);
        }
    }
    // move unique triplets from set to answer
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(arr,n);
    for(auto &row:ans){
        for(auto val:row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
*/

/*
Time Complexity: O(N^2 * log(no. of unique triplets)), where N = size of the array.
    Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of
    unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just
    sorting 3 elements every time.
Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list
    to store the triplets and extra O(N) for storing the array elements in another set.
*/

//Approach 3: Sort + two pointers (optimal O(N²))
/*
Sort the array once (O(N log N)).
Loop i from 0..n-1 (skip duplicates for i).
For each i, run a classic two-pointer 2-sum on the subarray (i+1 … n-1):
    j = i+1, k = n-1
    If arr[i]+arr[j]+arr[k] < 0 → j++
    If > 0 → k--
    If == 0 → record triplet, then move j++ and k-- and skip duplicates for both sides.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int n) {
    vector<vector<int>> ans;

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Fix one element and apply two-pointer
    for(int i = 0; i < n; i++) {

        // Skip duplicate values of i
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;      // left pointer
        int k = n - 1;      // right pointer

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if(sum > 0) {
                k--;
            }
            else if(sum < 0) {
                j++;
            }
            else {
                // Found valid triplet
                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                // Skip duplicates for j
                while(j < k && nums[j] == nums[j - 1]) j++;

                // Skip duplicates for k
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int n = nums.size();

    vector<vector<int>> ans = threeSum(nums, n);

    for(auto &row : ans){
        for(auto val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N*logN)+O(N^2), where N = size of the array.
    Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can
    run for approximately N times including the operation of skipping duplicates. So the total time complexity
    will be O(N^2).
Space Complexity: O(no. of triplets), This space is only used to store the answer. We are not using
    any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
==================================================
*/