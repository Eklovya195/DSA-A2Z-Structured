/*
Problem:  Spiral Traversal of Matrix
Platform: Array / Striver A2Z
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/spiral-matrix/description/"
==================================================
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>> &matrix,int n,int m){
    int left = 0, right = m-1;
    int top = 0, bottom = n-1; 
    vector<int> ans;
    while(left<=right && top<=bottom){
        // Left → Right
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        // Top → Bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        // Right → Left
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        // Bottom → Top
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans = SpiralMatrix(matrix,n,m);
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}

/*
==================================================
Time Complexity: O(m x n) 
    {Since all the elements are being traversed once and there are total n x m
    elements ( m elements in each row and total n rows) so the time complexity will be O(n x m)}.
Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.
==================================================
*/