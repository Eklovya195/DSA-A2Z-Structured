/*
Problem: Intersection of two sorted arrays
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1"
coding Ninjas Link: "https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149"

==================================================
*/

// 1) Brute Force (O(n1·n2)) — visited array ke saath
/*
// (A) Multiplicity (e.g., [1,2,2,3] & [2,2,2] → [2,2])
#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionBruteMultiplicity(int arr1[], int n1, int arr2[], int n2) {
    vector<int> res;
    vector<int> visited(n2, 0); // mark matched indices in arr2
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (!visited[j] && arr1[i] == arr2[j]) {
                res.push_back(arr1[i]);
                visited[j] = 1; // this arr2[j] consumed
                break; // move to next arr1[i]
            }
            if (arr2[j] > arr1[i]) break; // small optimization if sorted
        }
    }
    return res;
}

int main(){
    int n = 4, m = 3;
    int arr1[] = {1,2,2,3};
    int arr2[] = {2,2,2};
    vector < int > Intersection = intersectionBruteMultiplicity(arr1,n,arr2,m);
    for (auto & val: Intersection)
    cout << val << " ";
    return 0;
}
*/

/*
//(B) Unique intersection (deduplicate result)
#include <bits/stdc++.h>
using namespace std;
vector<int> intersectionBruteUnique(int arr1[], int n1, int arr2[], int n2) {
    vector<int> res;

    for (int i = 0; i < n1; i++) {
        if (i > 0 && arr1[i] == arr1[i-1]) continue;

        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                res.push_back(arr1[i]);
                break;
            }
            if (arr2[j] > arr1[i]) break;  // valid only if sorted
        }
    }
    return res;
}

int main(){
    int n = 4, m = 3;
    int arr1[] = {1,2,2,3};
    int arr2[] = {2,2,2};
    vector < int > Intersection = intersectionBruteUnique(arr1,n,arr2,m);
    for (auto & val: Intersection)
    cout << val << " ";
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n1·n2)
Space Complexity: O(n2)
==================================================
*/

/*
// 2.Two-Pointer (O(n1+n2)) — BEST for sorted arrays
// (A) Unique intersection
#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionTwoPointerUnique(vector<int> &arr1, vector<int> &arr2) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            j++;
        }
        else {
            //Avoid duplicates
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 4, 6, 7, 8};

    vector<int> Intersection = intersectionTwoPointerUnique(arr1, arr2);

    for (auto &val : Intersection)
        cout << val << " ";

    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(n1+n2)
Space Complexity: O(1)
==================================================
*/

// (B) Multiplicity (counted intersection)
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
	vector<int> result;
    int i = 0;
    int j = 0;
    while(i<n && j<m){
            if(arr1[i] < arr2[j]){
                i++;
            }
            else if(arr1[i] > arr2[j]){
                j++;
            }
            else{
                result.push_back(arr1[i]);
                i++;
                j++;
            }
        }
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 4, 6, 7, 8};
    int n = arr1.size();
    int m = arr2.size();
    vector<int> Intersection = findArrayIntersection(arr1,n, arr2,m);

    for (auto &val : Intersection)
        cout << val << " ";

    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(n1+n2)
Space Complexity: O(1)
==================================================
*/
