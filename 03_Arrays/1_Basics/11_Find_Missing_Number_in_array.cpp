/*
Problem: Find Missing Number in array
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://leetcode.com/problems/missing-number/description/"
coding Ninjas Link: "https://www.naukri.com/code360/problems/missing-number_6680467"

==================================================
*/

/*
//Approach 1 (Brute Force)
#include <bits/stdc++.h>
using namespace std;

int FindMissingNumber(int arr[],int n){
    for(int i=1;i<=n+1;i++){
        // flag variable to check
        //if an element exists
        int flag = 0;
        for(int j=0;j<n;j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        //if element is missing flag == 0
        if(flag == 0) return i;
    }
    return -1; //Safety return
}

int main(){
    int n = 4;
    int arr[] = {1,2,4,5};
    int MissingNumber = FindMissingNumber(arr,n);
    cout << MissingNumber;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N^2), where N = size of the array+1.
    Reason: In the worst case i.e. if the missing number is N itself, the outer loop will run for N times, and for
    every single number the inner loop will also run for approximately N times. So, the total time complexity
    will be O(N^2).
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/

/*
//Approach 2 (Better) (Using Hashing)
#include <bits/stdc++.h>
using namespace std;

int FindMissingNumber(int arr[],int n){
   int hash[n+1] ={0};

   //Storing frequencies
   for(int i=0;i<n-1;i++){
    hash[arr[i]]++;
   }

    //checking 0 frequency(Missing Number)
    for(int i=1;i<=n;i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1; //never execute just for safety
}

int main(){
    int n = 6;
    int arr[] = {1,2,3,4,5};
    int MissingNumber = FindMissingNumber(arr,n);
    cout << MissingNumber;
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N) + O(N) ~ O(2*N), where N = size of the array+1.
    Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for
    checking the frequencies in the second step again O(N) is required. So, the total time complexity is O(N)
    + O(N).
Space Complexity: O(N), where N = size of the array+1.
    Here we are using an extra hash array of size N+1.
==================================================
*/

//Approach 3 (Optimal)

/*
//A) Sum Approach(overflow for larger values)
#include <bits/stdc++.h>
using namespace std;

int FindMissingNumber(int arr[],int n){
   int sum = n*(n+1)/2; //overflow problem may occur for larger values
   int s2 = 0;
   for(int i=0;i<n-1;i++){
    s2 += arr[i];
   }
   return (sum - s2);
}

int main(){
    int n = 6;
    int arr[] = {1,2,3,4,5};
    int MissingNumber = FindMissingNumber(arr,n);
    cout << MissingNumber;
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O(N), where N = size of array+1.
    Reason: Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N
    times. So, the time complexity is O(N).
Space Complexity: O(1) as we are not using any extra space.
====================================================================================================
*/

//B)XOR method (Best) (No overflow problem)
//(1 ^ 2 ^ ... ^ N) ^ (a[0] ^ a[1] ^ ... ) = missing
#include <bits/stdc++.h>
using namespace std;

int FindMissingNumber(int arr[],int n){
   int xor1 = 0;
   int xor2 = 0;
   for(int i=0;i<n-1;i++){
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ (i+1);
   }
   xor1 = xor1 ^ n;
   return xor1^xor2;
}

int main(){
    int n = 5;
    int arr[] = {1,2,4,5};
    int MissingNumber = FindMissingNumber(arr,n);
    cout << MissingNumber;
    return 0;
}

/*
====================================================================================================
Time Complexity: O(N), where N = size of array+1.
    Reason: Here, we need only 1 loop to calculate the XOR. The loop runs for approx. N times. So, the
    time complexity is O(N).
Space Complexity: O(1) as we are not using any extra space.
====================================================================================================
*/
