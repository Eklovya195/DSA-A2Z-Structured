/*
Problem: 4. Median of Two Sorted Arrays
Problem Statement:Given two sorted arrays nums1 and nums2 of size m and n respectively,
    return the median of the two sorted arrays.
    The overall run time complexity should be O(log (m+n)).
Platform: Binary Search / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/median-of-two-sorted-arrays/description/"
==================================================
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
==================================================
*/

//Brute Force (Using Extra Array)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> nums3;
    int i = 0;
    int j = 0;
    while(i<n1 && j <n2){
        if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
        else nums3.push_back(nums2[j++]);
    }
    while(i<n1) nums3.push_back(nums1[i++]);
    while(j<n2) nums3.push_back(nums2[j++]);

    int n = n1+n2;
    int mid = n/2;
    if(n%2 != 0){
        cout << nums3[mid];
    }else{
       double ans = (nums3[mid]+nums3[mid-1])/2.0;
       cout << ans;
    }
    
    return 0;
}
*/

/*
==================================================
Time: O(N1+N2)
Space: O(n)
==================================================
*/

//other approach is by removing nums3(reduced space from n->1)
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    int n1 = nums1.size(),n2 = nums2.size();
    int n = (n1+n2);
    int i = 0,j = 0;
    int ind2 = n/2;
    int ind1 = ind2-1;
    int cnt = 0;
    int indel1 = -1,indel2 = -1;
    while(i<n1 && j<n2){
        if(nums1[i] < nums2[j]){
            if(cnt == ind2) indel2 = nums1[i];
            if(cnt == ind1) indel1 = nums1[i];
            cnt++;
            i++;
        }else{
            if(cnt == ind2) indel2 = nums2[j];
            if(cnt == ind1) indel1 = nums2[j];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt == ind2) indel2 = nums1[i];
        if(cnt == ind1) indel1 = nums1[i];
        cnt++;
        i++;
    }  
    while(j<n2){
        if(cnt == ind2) indel2 = nums2[j];
        if(cnt == ind1) indel1 = nums2[j];
        cnt++;
        j++;
    }
    if(n%2 == 1) cout << indel2;
    else{
        cout << (double)((double)(indel1+indel2)/2.0);
    }
    return 0;
}

/*
==================================================
Time: O(N1+N2)
Space: O(1)
==================================================
*/