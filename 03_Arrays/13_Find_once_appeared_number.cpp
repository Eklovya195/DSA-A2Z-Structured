/*
Problem: Find the number that appears once, and the other numbers twice
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/single-number/description/"
==================================================
Example:
Input: [2,2,1]
Output: 1
Explanation: every element appears twice except for one element. Find that single one.
*/

/*
//Approach 1: Brute Force (Double Loop)
// Idea: Har element ke liye count nikaalo, agar count = 1 → wahi answer.
int singleNumber(vector<int> &nums){ 
    for(int i=0;i<nums.size();i++){
        int cnt = 0;
        int num = nums[i];
        for(int j=0;j<nums.size();j++){
            if(nums[j] == num) cnt++;
        }
        if(cnt == 1) return num;
    }
    return -1;
}
int main() {
    vector < int > nums = {2,2,1,1,4};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N2), where N = size of the given array.
    Reason: For every element, we are performing a linear search to count its occurrence. The linear search
    takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be
    O(N2).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

/*
// Approach 2: Hashing / Frequency Array
// Idea: Store count of each number in a hash (array or map).
#include <bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();
    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
        return arr[i];
    }
    //This line will never execute
    //if the array contains a single element.
    return -1;
}
int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)+O(N)+O(N), where N = size of the array
    Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one
    is to search the single element in the array.
Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
==================================================
*/


/*
//Approach 3: Using unordered_map
// Idea: Count frequency using hash map (dynamic key storage).
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums){
    unordered_map <int,int> mp;

    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }

    for(auto it:mp){
        if(it.second == 1) return it.first;
    }
    return -1; //just for safety purpose
}
int main() {
    vector < int > nums = {2,2,1,1,4};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N*logM) + O(M), 
    where M = size of the map i.e. M = (N/2)+1. N = size of the array.
    Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M =
    size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and
    search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and
    search. In that case, the time complexity will be O(N) + O(M).
    Note: The time complexity will be changed depending on which map data structure we are using. If we
    use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of
    O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).
Space Complexity: O(M) 
as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.

==================================================
*/


// Approach 4: XOR Trick (Optimal)
// Concept:
//     a ^ a = 0
//     a ^ 0 = a
// XOR is associative and commutative
// So if you XOR all numbers, the duplicate ones cancel out, leaving the unique one.

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums){
    int xor1 = nums[0];
    for(int i=1;i<nums.size();i++){
        xor1 = xor1^nums[i];
    }
    return xor1; 
}
int main() {
    vector < int > nums = {2,2,1,1,4,4,5,6,6};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}

/*
==================================================
Time Complexity: O(N), where N = size of the array.
    Reason: We are iterating the array only once.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/