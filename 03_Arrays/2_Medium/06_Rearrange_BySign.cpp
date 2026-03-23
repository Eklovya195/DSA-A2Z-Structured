/*
Problem: Rearrange Array Elements by Sign(Equal +ve & -ve integers given)
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/rearrange-array-elements-by-sign/description/"
==================================================
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
==================================================
*/

//My first thought process
/*
#include <bits/stdc++.h>
using namespace std;

void RearrangeBYSign(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        if(i%2==0){ //for positive integers
            if(arr[i] < 0){
                for(int j=i+1;j<n;j++){
                    if(arr[j] > 0){
                        swap(arr[i],arr[j]);
                        break;
                    }
                }
            }
        }else{  //for negative integers
            if(arr[i] > 0){
                for(int j=i+1;j<n;j++){
                    if(arr[j] < 0){
                        swap(arr[i],arr[j]);
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n = arr.size();
    RearrangeBYSign(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
*/

/*
==================================================
Time complexity: O(n^2)
Space Complexity: O(1)
==================================================
*/

//Approach 1:Brute Force
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangeBYSign(vector<int> &arr,int n){
    vector<int> pos;
    vector<int> neg;
    //pushing positive and negative element in different array
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    //rearranging positions
    for(int i=0;i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    return arr;//returning final arr
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n = arr.size();
    RearrangeBYSign(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O(N+N/2)
    { O(N) for traversing the array once for segregating positives and negatives
    and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
Space Complexity: O(N/2 + N/2) = O(N) 
    { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
====================================================================================================
*/

//A2) Single pass fill even/odd (no extra buckets for counts)
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangeBYSign(vector<int> arr,int n){
    //define array for storing answer separately
    vector<int> ans(n,0);
    //positive index starts from 0 while negative index starts from index 1
    int posIndex = 0, negIndex = 1;
    for(int i=0;i<n;i++){
        if(arr[i] < 0){  // Fill negative elements in odd indices and inc by 2
            ans[negIndex] = arr[i];
            negIndex += 2;
        }else{  // Fill positive elements in even indices and inc by 2
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;//returning final ans array
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4};
    int n = arr.size();
    vector<int> ans = RearrangeBYSign(arr,n);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) 
{ O(N) for traversing the array once and substituting positives and negatives
simultaneously using pointers, where N = size of the array A}.
Space Complexity: O(N) 
{ Extra Space used to store the rearranged elements separately in an array,where N = size of array A}.
==================================================
*/

/*
//Case B: Counts may be unequal
Strategy:
1. Split into pos and neg.
2. Fill alternating while both remain.
3. Append the leftover of the majority sign.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> RearrangeBYSign(vector<int> &arr,int n){
    // Define 2 vectors, one for storing positive
    // and other for negative elements of the array
    vector<int> pos,neg;
    //filling positive and negative element array
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }else{
           pos.push_back(arr[i]);
        }
    }
    // If negatives are lesser than the positives.
    if(neg.size() < pos.size()){
        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        // Fill the remaining positives at the end of the array.
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }else{  // If positives are lesser than the negatives
        // First, fill array alternatively till the point
        // where positives and negatives ar equal in number.
        for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        // Fill the remaining negatives at the end of the array
        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {3,1,-2,-5,2,-4,5,6};
    int n = arr.size();
    RearrangeBYSign(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}

/*
Time Complexity: O(2*N) 
    { The worst case complexity is O(2*N) which is a combination of O(N) of
    traversing the array to segregate into neg and pos array and O(N) for adding the elements alternatively
    to the main array}.
Explanation: The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). There can
    be two cases: when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover)
    = O(0) + O(N), and when equal no. of positive and negative elements are present, O(min(pos, neg)) +
    O(leftover) = O(N/2) + O(0). So, from these two cases, we can say the worst-case time complexity is
    O(N) for the second part, and by adding the first part we get the total complexity of O(2*N).
Space Complexity: O(N/2 + N/2) = O(N) 
    { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/