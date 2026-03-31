/*
Problem:  4Sum
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/4sum/description/"
==================================================
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
==================================================
*/
//Brute Force: (4 nested loops + set)
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quad(vector<int> arr,int target){
    int n = arr.size();
    set<vector<int>> st; //to avoid duplicates
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = quad(arr,target);
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
Time Complexity: O(N^4), where N = size of the array.
    Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting
    as we are just sorting 4 elements every time.
Space Complexity: O(2 * no. of the quadruplets) 
    as we are using a set data structure and a list to store the quads.
==================================================
*/

//Better Approach: 3 loops + hash set
//use long long instead of int for avoiding overflow
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quad(vector<int> arr,int target){
    int n = arr.size();
    set<vector<int>> st; //to avoid duplicates
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int sum = arr[i] + arr[j];
                sum += arr[k];
                int fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> arr = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> ans = quad(arr,target);
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
====================================================================================================
Time Complexity: O(N^3*log(M)), where N = size of the array, M = no. of elements in the set.
    Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on
    the set data structure which take log(M) time complexity.
Space Complexity: O(2 * no. of the quadruplets)+O(N)
    Reason: we are using a set data structure and a list to store the quads. This results in the first term. And
    the second space is taken by the set data structure we are using to store the array elements. At most,
    the set can contain approximately all the array elements and so the space complexity is O(N).
====================================================================================================
*/

//Optimal:Sort + two pointers — O(N³), O(1) extra
/*
Sort the array.
Fix i (skip duplicates), fix j (skip duplicates).
Two pointers k=j+1, l=n-1:
   If sum < target → k++
   If sum > target → l--
   If sum == target → push quad, then k++, l-- and skip duplicates on both sides.
Why it’s best: tight O(N³), no sets, duplicate handling is clean and deterministic.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quad(vector<int> nums,int target){
    int n = nums.size();
    vector<vector<int>> ans;

    //sort the array
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        // Skip duplicate values of i
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j=i+1;j<n;j++){
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    //found quad
                    ans.push_back({nums[i], nums[j], nums[k],nums[l]});
                    k++;
                    l--;

                    //skip duplicates for k
                    while(k<l && nums[k] == nums[k-1]) k++;

                    //skip duplicates for l
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = quad(nums,target);
    for(auto &row:ans){
        for(auto val:row){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(N3), where N = size of the array.
    Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l
    combined can run for approximately N times including the operation of skipping duplicates. So the total
    time complexity will be O(N3).
Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using
    any extra space to solve this problem. So, from that perspective, space complexity can be written as
    O(1).
==================================================
*/