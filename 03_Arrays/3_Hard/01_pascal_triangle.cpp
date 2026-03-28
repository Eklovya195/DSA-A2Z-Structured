/*
Problem:  Pascal's Triangle
Platform: Array / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/pascals-triangle/description/"
==================================================
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
==================================================
*/

//Type 1: Find the Element at (r, c)
/*
The element in the r-th row and c-th column of Pascal’s triangle is:
Element(r,c)= C(r−1,c−1)
We can calculate this using the iterative formula for binomial coefficients:
C(n,k) = n! / ((n-k)! * k!
*/

/*
#include <bits/stdc++.h>
using namespace std;

void findPascalElement(int r,int c){
    //element finding formula is C(r-1,c-1)
    int n = r-1;
    int k = c-1;
    long long res = 1;
    //run loops for c-1 times
    for(int i=0;i<k;i++){
        res *= (n-i);
        res /= (i+1);
    }
    cout << res;
}

int main(){
    int r = 5, c = 3;
    findPascalElement(r,c);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(min(c,r−c)), The loop runs for min(c−1,r−c) iterations because binomial coefficients
are symmetric.
Space Complexity: O(1), constant additional space is used.
==================================================
*/

//Type 2:Generate Only Nth Row (Efficient)
//Method 1
/*
#include <bits/stdc++.h>
using namespace std;

long long findPascalElement(int r,int c){
    long long res=1;
    for(int i=0;i<c;i++){
        res *= (r-i);
        res /= (i+1);
    }
    return res;
}

void printPascalRow(int r){
    for(int c=0;c<r;c++){
        cout << findPascalElement(r-1,c) << " ";
    }
}

int main(){
    int r = 5;
    printPascalRow(r);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N), we iterate N times to compute each element of the row in O(1) time using the
direct relation.
Space Complexity: O(1)
==================================================
*/

//Method 2
/*
We can compute the Nth row directly using the binomial formula:
C(n,k) = C(n,k-1) * (n-k)/k
This lets us compute the entire row in O(N) time without using the triangle.
*/

/*
#include <bits/stdc++.h>
using namespace std;

vector<long long> getPascalRow(int r){
    vector<long long> row;
    
    long long val = 1;   // first element is always 1
    row.push_back(val);

    for(int c = 1; c < r; c++){
        val = val * (r - c);
        val = val / c;
        row.push_back(val);
    }

    return row;
}

int main(){
    int r = 5;
    vector<long long> ans = getPascalRow(r);

    for(auto x : ans){
        cout << x << " ";
    }
}
*/

/*
==================================================
Time Complexity: O(N), we iterate N times to compute each element of the row in O(1) time using the
direct relation.
Space Complexity: O(N),additional space used for storing the Nth row.
==================================================
*/

//Type 3: Generate Full Pascal’s Triangle (Brute Force)
//Type 3 Solved using Method 1:
/*
#include <bits/stdc++.h>
using namespace std;

long long findPascalElement(int r,int c){
    long long res=1;
    for(int i=0;i<c;i++){
        res *= (r-i);
        res /= (i+1);
    }
    return res;
}

void printPascalRow(int numrow){
    for(int i=1;i<=numrow;i++){
        for(int c=0;c<i;c++){
            cout << findPascalElement(i-1,c) << " ";
        }
        cout << "\n";
    }
}

int main(){
    int numrow = 5;
    printPascalRow(numrow);
    return 0;
}
*/


//Method 2: Best
//Type 3 Solved using Method 2:
#include <bits/stdc++.h>
using namespace std;

//returning element of individual row
vector<long long> getPascalRow(int r){
    vector<long long> row;
    
    long long val = 1;   // first element is always 1
    row.push_back(val);

    for(int c = 1; c < r; c++){
        val = val * (r - c);
        val = val / c;
        row.push_back(val);
    }

    return row;
}

vector<vector<long long>> pascalTriangle(int n){
    vector<vector<long long>> triangle;
    for(int i=1;i<=n;i++){
        triangle.push_back(getPascalRow(i));
    }
    return triangle;
}

int main(){
    int n = 5;
    vector<vector<long long>> ans = pascalTriangle(n);

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
Time Complexity: O(N^2), we generate all the elements in first N rows sequentially one by one.
Space Complexity: O(N^2), additional space used for storing the entire pascal triangle.
==================================================
*/