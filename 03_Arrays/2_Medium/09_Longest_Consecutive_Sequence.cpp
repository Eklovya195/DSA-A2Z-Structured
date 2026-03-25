/*
Problem:  Longest Consecutive Sequence in an Array
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/longest-consecutive-sequence/"
==================================================
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
==================================================
*/

//Approach 1: Brute Force
/*
#include <bits/stdc++.h>
using namespace std;
bool ls(vector<int> arr,int x){
    for(int i=0;i<arr.size();i++){
        if(arr[i] == x) return true;
    }
    return false;
}

int LongestSequence(vector<int> arr,int n){
    int largest = 1;
    for(int i=0;i<n;i++){
        int cnt = 1;
        int x = arr[i];
        while(ls(arr,x+1) == true){
            x += 1;
            cnt++;
        }
        largest = max(largest,cnt);
    }
    return largest;
}

int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    int n = arr.size();
    int ans = LongestSequence(arr,n);
    cout << ans;
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O(N^2), N = size of the given array.
    Reason: We are using nested loops each running for approximately N times.
Space Complexity: O(1), as we are not using any extra space to solve this problem.
====================================================================================================
*/

/*
Approach 2: Sort then scan (O(N log N))
Idea:
1. Array sort karo.
2. Ek pass me consecutive run length count karo.
3. Duplicate elements ko skip karna zaroori hai, warna count toot jayega.
*/
/*
#include <bits/stdc++.h>
using namespace std;

int LongestSequence(vector<int> arr,int n){
    if(n == 0) return 0;
    //first sort the array
    sort(arr.begin(),arr.end());
    int largest = 1;
    int cnt = 0;
    int lastSmallest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastSmallest){
            cnt++;
            lastSmallest = arr[i];
        }
        else if(lastSmallest != arr[i]){
            cnt = 1;
            lastSmallest = arr[i];
        }
        largest = max(largest,cnt);
    }
    return largest;
}

int main(){
    vector<int> arr = {100,4,200,1,3,2};
    int n = arr.size();
    int ans = LongestSequence(arr,n);
    cout << ans;
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O(NlogN) + O(N), N = size of the given array.
    Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
Space Complexity: O(1), as we are not using any extra space to solve this problem.
====================================================================================================
*/

//Approach 3: Hash set (O(N) average)
/*
Best for interviews.
Idea:
    unordered_set me sab elements daal do.
    Sirf starting points se sequences grow karo: koi number x tab start hoga jab x-1 set me na ho.
    Fir x+1, x+2, ... count karte jao.
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSequence(vector<int> arr,int n){
    if(n == 0) return 0;
    unordered_set<int> st;
    int largest = 1;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
       if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                cnt++;
            }
            largest = max(largest,cnt);
       }
    }
    return largest;
}

int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    int n = arr.size();
    int ans = LongestSequence(arr,n);
    cout << ans;
    return 0;
}

/*
====================================================================================================
Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
    Reason: O(N) for putting all the elements into the set data structure. After that for every starting element,
    we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at
    most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).
Space Complexity: O(N), as we are using the set data structure to solve this problem.
====================================================================================================
*/

/*
Note: The time complexity is computed under the assumption that we are using unordered_set and it is
taking O(1) for the set operations.
If we consider the worst case the set operations will take O(N) in that case and the total time complexity
will be approximately O(N^2).
And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN)
and the total time complexity will be O(N*logN).
*/