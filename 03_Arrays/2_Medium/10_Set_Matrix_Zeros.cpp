/*
Problem:  Set Matrix Zeros
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/set-matrix-zeroes/description/"
==================================================
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

        1 1 1           1 0 1 
        1 0 1   -->     0 0 0
        1 1 1           1 0 1
==================================================
*/

/*
//Approach 1: In-place marking with a sentinel (❌ risky)
You mark same row/col by writing -1 and later turn all -1 → 0.
● Problem: If the input can already contain -1 (or any chosen sentinel), you’ll corrupt data.
● Also: With many zeros, time can degrade to O(Z·(N+M)) ≤ O(NM(N+M)).
● Use only if the matrix domain guarantees the sentinel is safe.
*/

/*
#include <bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
        matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
        matrix[i][j] = -1;
        }
    }
}
void printMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }
    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    printMatrix(ans);
    return 0;
}
*/

/*
====================================================================================================
Time Complexity: O((N*M)*(N + M)) + O(N*M), 
    where N = no. of rows in the matrix and M = no. of columns in the matrix.
    Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now,
    whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So,
    combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
    Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
Space Complexity: O(1) as we are not using any extra space
====================================================================================================
*/

/*
//Approach 2: Extra row/col arrays (simple & safe)
Keep two arrays row[n], col[m]. First pass marks which rows/cols to zero; second pass zeros them.
*/
/*
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    int row[n] = {0}; // row array
    int col[m] = {0}; // col array
    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
            // mark ith index of row wih 1:
            row[i] = 1;
            // mark jth index of col wih 1:
            col[j] = 1;
            }
        }
    }
    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
void printMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
int main(){
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    printMatrix(ans);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
    Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
    Reason: O(N) is for using the row array and O(M) is for using the col array.
==================================================
*/

/*
//Approach 3: O(1) extra space using 1st row & 1st column as markers (optimal)
Use matrix[i][0] to mark row i and matrix[0][j] to mark column j.
matrix[0][0] is ambiguous (marks both), so track first column separately with col0.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]
    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;
                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                col0 = 0;
            }
        }
    }
    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}
void printMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    printMatrix(ans);
    return 0;
}

/*
==================================================
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
    Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking
    O(N*M) time complexity.
Space Complexity: O(1) as we are not using any extra space.
==================================================
*/