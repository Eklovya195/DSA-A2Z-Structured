/*
Problem: Aggressive Cows
Problem Statement:Given an integer array arr[], which denotes the positions of stalls.
    All the positions are distinct. There are k aggressive cows.
    Assign the cows to the stalls such that the minimum distance between any two cows is maximized.
Platform: Binary Search / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/aggressive-cows/1"
==================================================
Input: arr[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]),
     which is the maximum possible among all valid arrangements.
==================================================
*/

//Brute Force
/*
CanWePlace(d) logic
● First cow ko first stall me rakh do
Har next stall par check karo:
stalls[i] - lastPlaced >= d
● Agar haan → cow place karo
● Jaise hi k cows place ho jaaye → true
● End tak nahi ho paayi → false
*/
/*
#include <bits/stdc++.h>
using namespace std;

bool CanWePlace(vector<int> &arr,int dist,int cows){
    int cntcows = 1;
    int last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last >= dist){
            cntcows++;
            last = arr[i];
        }
    }
    if(cntcows >= cows) return true;
    else return false;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 5};
    int k = 3;
    int n = arr.size();
    //sort the array first
    sort(arr.begin(),arr.end());
    //find the min and max element in array
    int mini = *min_element(arr.begin(),arr.end());
    int maxi = *max_element(arr.begin(),arr.end());
    for(int i=1;i<=(maxi-mini);i++){
        if(CanWePlace(arr,i,k)){
            continue;
        }else{
            cout << (i-1);
            break;
        }
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O((maxi-min)*O(n)) approx quadratic time complexity
Space Complexity: O(1)
==================================================
*/

//OPtimal Approach (Using Binary)
#include <bits/stdc++.h>
using namespace std;

bool CanWePlace(vector<int> &arr,int dist,int cows){
    int cntcows = 1;
    int last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last >= dist){
            cntcows++;
            last = arr[i];
        }
    }
    if(cntcows >= cows) return true;
    else return false;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 5};
    int k = 3;
    int n = arr.size();
    //sort the array first
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n-1]-arr[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(CanWePlace(arr,mid,k)){
            low = mid+1;
        }else{
            high = mid-1;
        } 
    }
    cout << high;
    return 0;
}


/*
==================================================
Sorting: O(N log N)
    Binary Search × check: O(N log(maxDist))
Space: O(1)
==================================================
*/

