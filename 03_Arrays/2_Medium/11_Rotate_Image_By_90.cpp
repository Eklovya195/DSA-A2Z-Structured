/*
Problem:  Rotate Image By 90 degree
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/rotate-image/description/"
====================================================================================================
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

        1 2 3   rotated by 90 deg          7 4 1 
        4 5 6   --------->                 8 5 2
        7 8 9                              9 6 3
====================================================================================================
*/

//Approach 1: Using Extra Matrix (Brute Force)
/*
Intuition:
Every element (i, j) in the original matrix moves to position (j, n - 1 - i) in the rotated matrix.
So:
new[j][n - i - 1] = old[i][j];
We simply copy into a new matrix based on that relationship.
*/
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> RotateBy90(vector<vector<int>> &matrix,int n){
    vector<vector<int>> rotated(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotated[j][n-1-i] = matrix[i][j];
        }
    }
    return rotated;
}

void printMatrix(vector<vector<int>> &mat){
    for(const auto &row : mat){
        for(int val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = matrix.size();
    vector<vector<int>> ans = RotateBy90(matrix,n);
    printMatrix(ans);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
Space Complexity: O(N*N) to copy it into some other matrix.
==================================================
*/


//APPROACH 2 — In-place (Optimal)
/*
Intuition:
We can do it without using extra space.
We know:
90° rotation = Transpose + Reverse every row
Why it works:
    Transpose: converts rows → columns
    (matrix[i][j] ↔ matrix[j][i])
Reverse each row: rotates the matrix
*/

/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> RotateBy90(vector<vector<int>> &matrix,int n){
    // Step 1: Transpose
    for(int i=0;i<n;i++){
        //transpose visit only upper triangle
        for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
        }
    }
    // Step 2: Reverse each row
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}

void printMatrix(vector<vector<int>> &mat){
    for(const auto &row : mat){
        for(int val : row){
            cout << val << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = matrix.size();
    vector<vector<int>> ans = RotateBy90(matrix,n);
    printMatrix(ans);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for
reversing the matrix.
Space Complexity: O(1).
==================================================
*/