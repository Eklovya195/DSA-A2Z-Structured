/*
Problem: Union of two sorted arrays
Platform: Array / Striver A2Z
Difficulty: Easy
Practice Link: "https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1"
Leetcode Link:"https://leetcode.com/problems/merge-sorted-array/description/"
coding Ninjas Link: "https://www.naukri.com/code360/problems/sorted-array_6613259?interviewProblemRedirection=true&search=merge"

==================================================
Example:
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7] 
Output : [1, 2, 3, 4, 5, 6, 7]
*/

/*
// Approach A — map / set (easy, uses tree)
#include <bits/stdc++.h>
using namespace std;
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    map < int, int > freq;
    vector < int > Union;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    for (auto & it: freq)
        Union.push_back(it.first);
    return Union;
}
int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Compleixty : O( (m+n)log(m+n) ) 
    Inserting a key in map takes logN times, where N is no of
    elements in map. At max map can store m+n elements {when there are no common elements and
    elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation
    across insertion of all elements in worst it would take O((m+n)log(m+n) time.
    Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but
    sorting the union vector takes O((m+n)log(m+n)) time. Because at max union vector can have m+n
    elements.
Space Complexity : O(m+n)
    {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}

==================================================
*/

/*
// Aproach - B (Using Set)
#include <bits/stdc++.h>
using namespace std;

vector<int> FindUnion(int a[],int b[],int n,int m){
    set <int> st;
    vector <int> Union;
    for(int i=0;i<n;i++)
        st.insert(a[i]);
    for(int i=0;i<m;i++)
        st.insert(b[i]);
    for(auto &it:st)
        Union.push_back(it);
    return Union;
}

int main(){
    int n = 10, m = 7;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(a, b, n, m);
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Compleixty : O( (m+n)log(m+n) ) 
    ->Inserting an element in a set takes logN time, where N is no of
    elements in the set. At max set can store m+n elements {when there are no common elements and
    elements in a,b are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation
    across inserting all elements in worst, it would take O((m+n)log(m+n) time.
    ->Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but
    sorting the union vector takes O((m+n)log(m+n)) time. Because at max union vector can have m+n
    elements.
Space Complexity : O(m+n) + O(m+n){second is used to return the address}
                {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}
==================================================
*/

// Approach (BEST when inputs are sorted) — Two-pointer merge
#include <bits/stdc++.h>
using namespace std;
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]){ // Case 1 and 2
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        } else { // case 3
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) { // IF any element left in arr1
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) {// If any elements left in arr2
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}
int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    for (auto & val: Union)
    cout << val << " ";
    return 0;
}

/*
==================================================
Time Complexity: O(m+n), 
    Because at max i runs for n times and j runs for m times. When there are no
    common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct.
Space Complexity : O(m+n) {just for returning the answer}
    {If Space of Union ArrayList is considered}
    O(1) {If Space of union ArrayList is not considered}
==================================================
*/

/*
==================================================
If arrays are already sorted → always use two-pointer.
If arrays unsorted and you need sorted union → either use set (simple) or sort both then two-pointer.
==================================================
*/