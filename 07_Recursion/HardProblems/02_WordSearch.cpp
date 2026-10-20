/*
Problem:  79. Word Search
Platform: Recursion / Striver A2Z
Difficulty: Medium
Problem Link: "https://leetcode.com/problems/word-search/description/?utm=codolio"
==================================================
Explanation
You are given a 2D grid of characters (board) and a string word.
You need to check whether the word can be formed by moving through adjacent cells (up,
down, left, right)
Important rules:
● Each character must match the corresponding character in word
● You can move only horizontally or vertically
● The same cell cannot be used more than once in forming the word


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
==================================================
*/

//Approach 1: Using Recursion and backtracking
//My Thinking Solution -> this is also similar to the dfs+backtracking solution
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void funGenerate(vector<vector<char>>& board, string word,bool &ans,string subset,int m,int n,int indx,int indy,vector<vector<bool>> &vis){
        //first check if we are going out of grid or visiting already 
        if(indx < 0  || indx >= m || indy < 0 || indy >= n || vis[indx][indy]){
            return;
        }
        //add it to our new string subset
        subset += board[indx][indy];
        //check if ans found return true
        if(subset == word){
            ans = true;
            return;
        }
        //check first if we picked a wrong letter -> stop
        if(subset.size() < word.size() && board[indx][indy] == word[subset.size()-1]){
            vis[indx][indy] = true;
            // we need to move in all four directions
            funGenerate(board,word,ans,subset,m,n,indx+1,indy,vis);
            funGenerate(board,word,ans,subset,m,n,indx,indy+1,vis);
            funGenerate(board,word,ans,subset,m,n,indx-1,indy,vis);
            funGenerate(board,word,ans,subset,m,n,indx,indy-1,vis);
            vis[indx][indy] = false;  //backtrack mark unvisited
        }
        subset.pop_back();
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        // we need to access all grid as starting point
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){ //only start if first letter matches
                    string subset = "";
                    vector<vector<bool>> vis(m,vector<bool>(n,false));
                    funGenerate(board,word,ans,subset,m,n,i,j,vis);
                    if(ans) return true; // early return
                }    
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution obj;
    bool ans = obj.exist(board,word);
    cout << ans;
    return 0;
}
*/

/*
==================================================
Complexity Analysis:
Time Complexity: O(m × n × L * 4^L) 
    From each cell, we try 4 directions for each character of the word.
    L extra for string copy 
Space Complexity: O(L)
    Due to recursion stack depth equal to the word length
==================================================
*/

/*
Approach (Backtracking / DFS):
This is a classic backtracking problem:
    Start DFS from every cell in the grid
    ● If the current cell matches the current character of the word:
        ○ Mark the cell as visited (temporarily)
        ○ Try moving in all 4 directions
    ● If at any point the full word is matched → return true
    ● If a path fails, backtrack by restoring the cell
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int indx,int indy,int idx){
        if(idx == word.size()) return true; 

        if(indx < 0  || indx >= board.size() || indy < 0 || indy >= board[0].size() || board[indx][indy] != word[idx]){
            return false;
        }
        char temp = board[indx][indy];
        board[indx][indy] = '#'; //mark as visited
        bool found = dfs(board,word,indx+1,indy,idx+1)||
                     dfs(board,word,indx,indy+1,idx+1) ||
                     dfs(board,word,indx-1,indy,idx+1) ||
                     dfs(board,word,indx,indy-1,idx+1);
        
        board[indx][indy] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // we need to access all grid as starting point
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0)) return true;   
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution obj;
    bool ans = obj.exist(board,word);
    cout << ans;
    return 0;
}

/*
==================================================
Complexity Analysis:
Time Complexity: O(m × n × 4^L)
    From each cell, we try 4 directions for each character of the word.
Space Complexity: O(L)
    Due to recursion stack depth equal to the word length.
==================================================
*/