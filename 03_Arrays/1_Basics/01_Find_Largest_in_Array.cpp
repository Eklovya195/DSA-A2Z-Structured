/*
Problem: Finding Largest element in Array
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1"

==================================================
Array ko int main me define karo to garbage value se initialize hota hai, Agar globally karo to 0 se
initialize hota hai.
10 power 6 is maximum length of array we can define (inside int main)
10 power 7 is maximum length of array we can define (global declaration)

==================================================
*/

/*
// APPROACH 1 → Using sort()
#include<bits/stdc++.h>
using namespace std;

int sortArr(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    cout<<"The Largest element in the array is: "<< sortArr(arr1);
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(N*log(N))
Space Complexity: O(1)
==================================================
*/

/*
==================================================
Algorithm(Approach 2):
1.Initialize Maximum
    Set max equal to the first element of the array.
2.Traverse the Array
    Loop through all elements from index 0 to n-1.
3.Compare and Update
    If the current element is greater than max, update max.
4.Return Result
    After completing the loop, return max as the largest element.
==================================================
*/

// APPROACH 2 → Linear Scan (BEST)
#include<bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr) {
        int max = arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
}

int main() {
    vector<int> arr = {2,5,1,3,0};
    cout <<"The Largest element in the array is: "<< largest(arr);
    return 0;
}


/*
==================================================
Complexity Analysis(Approach 2):
Time Complexity: O(N)
Space Complexity: O(1)
==================================================
*/