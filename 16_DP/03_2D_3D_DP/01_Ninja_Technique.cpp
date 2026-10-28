/*
Problem:  Geek's Training/ Ninja Training
Platform: DP / Striver A2Z
Difficulty: Medium
Practice Link: "https://www.geeksforgeeks.org/problems/geeks-training/1?utm=codolio"
==================================================
A ninja is training for n days. Each day, he can perform one of three activities:
● Running
● Fighting practice
● Stealth training
The points gained for each activity on each day are given in a 2D matrix points, where
points[day][activity] represents the points earned.
The rule is that the ninja cannot perform the same activity on two consecutive days.
We need to find the maximum total points the ninja can earn over all days.

Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
Output: 210
Explanation:
Day 1: fighting practice = 70
Day 2: stealth training = 50
Day 3: fighting practice = 90
Total = 70 + 50 + 90 = 210
This gives the optimal points.
==================================================
*/

//Memoization Approach
/*
Algorithm
    We use recursion with memoization.
    ● Define a function f(day, last) that returns the maximum points from day 0 to day, where last is the activity done on the previous day.
    ● last can be 0, 1, 2 (activities) or 3 (no activity restriction).
    ● Base case:
        ○ If day == 0, choose the maximum activity on day 0 that is not equal to last.
    ● For other days:
        ○ Try all activities except last.
        ○ Add current day’s points to the result of f(day-1, current_activity).
        ○ Take the maximum.
    ● Store results in a dp[day][last] table to avoid recomputation.
    ● Final answer is f(n-1, 3)
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f(int day,vector<vector<int>>  &mat,int lastTask,vector<vector<int>> &dp){
        //base case
        if(day == 0){
            int maxi = 0;
            for(int i=0;i<=2;i++){
                if(i!=lastTask){
                    maxi = max(maxi,mat[0][i]);
                }
            }
            return maxi;
        }
        if(dp[day][lastTask]!=-1) return dp[day][lastTask];
        int maxi = 0;
        for(int i=0;i<=2;i++){
            if(i!=lastTask){
                int pts = mat[day][i] + f(day-1,mat,i,dp);
                maxi = max(maxi,pts);
            }
        }
        return dp[day][lastTask] = maxi;
    }

    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,mat,3,dp);
    }
};

int main(){
    vector<vector<int>> mat = {{8,7,1},{9,2,1}};
    Solution obj;
    cout << obj.maximumPoints(mat);
    return 0;
}
*/


/*
==================================================
Complexity Analysis:
Time Complexity: O(n × 4 × 3) = O(n)
    For each day, we try 4 possible last values and 3 activities.
Space Complexity: O(n × 4) + O(n)
    O(n × 4) for the DP table and O(n) for recursion stack.
==================================================
*/

//Tabulation Approach
/*
Algorithm:
    This is a bottom-up dynamic programming approach.
    ● Create a DP table dp[day][last].
    ● On day 0, initialize dp[0][last] with the best activity excluding last.
    ● For each next day:
        ○ For every possible last, try all activities not equal to last.
        ○ Update dp[day][last] with the maximum achievable points.
    ● The final answer is stored in dp[n-1][3].

*/

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//   public:
//     int maximumPoints(vector<vector<int>>& mat) {
//         int n = mat.size();
//         vector<vector<int>> dp(n,vector<int>(4,-1));
//         //these initial contains the max score if we ignore the specific task on day0
//         dp[0][0] = max(mat[0][1],mat[0][2]); //ignoring task 0
//         dp[0][1] = max(mat[0][0],mat[0][2]); //ignoring task 1
//         dp[0][2] = max(mat[0][0],mat[0][1]); //ignoring task 2
//         dp[0][3] = max(mat[0][0],max(mat[0][1],mat[0][2])); //no task is ignored
//         for(int day=1;day<n;day++){
//             for(int lastTask=0;lastTask<4;lastTask++){ //last task is basically task you are not allowed to do today
//                 dp[day][lastTask] = 0;
//                 for(int task=0;task<=2;task++){  //task is the task you are performing today
//                     if(task!=lastTask){
//                         //adding this day task with last day max points 
//                         //of forbidden task
//                         int pts = mat[day][task] + dp[day-1][task];
//                         dp[day][lastTask] = max(dp[day][lastTask],pts); 
//                     }
//                 }
//             }
//         }
//         return dp[n-1][3];
//     }
// };

// int main(){
//     vector<vector<int>> mat = {{8,7,1},{9,2,1}};
//     Solution obj;
//     cout << obj.maximumPoints(mat);
//     return 0;
// }


/*
==================================================
Complexity Analysis:
Time Complexity: O(n × 4 × 3) = O(n)
Space Complexity: O(n × 4)
    DP table stores results for all days and last activities.
==================================================
*/


//Tabulation With space Optimization
/*
Algorithm
    We observe that to compute the current day, we only need results from the previous day.
    ● Use two arrays of size 4:
        ○ prev for previous day
        ○ temp for current day
    ● Initialize prev for day 0.
    ● For each day:
        ○ Compute temp[last] by checking all task != last.
        ○ Assign prev = temp.
    ● Final answer is prev[3].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        //space optimization approach
        vector<int> prev(4,0);
        //these initial contains the max score if we ignore the specific task on day0
        prev[0] = max(mat[0][1],mat[0][2]); //ignoring task 0
        prev[1] = max(mat[0][0],mat[0][2]); //ignoring task 1
        prev[2] = max(mat[0][0],mat[0][1]); //ignoring task 2
        prev[3] = max(mat[0][0],max(mat[0][1],mat[0][2])); //no task is ignored
        for(int day=1;day<n;day++){
            vector<int> temp(4,0);
            for(int lastTask=0;lastTask<4;lastTask++){ //last task is basically task you are not allowed to do today
                temp[lastTask] = 0;
                for(int task=0;task<=2;task++){  //task is the task you are performing today
                    if(task!=lastTask){
                        //adding this day task with last day max points 
                        //of forbidden task
                        int pts = mat[day][task] + prev[task];
                        temp[lastTask] = max(temp[lastTask],pts); 
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};

int main(){
    vector<vector<int>> mat = {{8,7,1},{9,2,1}};
    Solution obj;
    cout << obj.maximumPoints(mat);
    return 0;
}


/*
==================================================
Complexity Analysis:
Time Complexity: O(n × 4 × 3) = O(n)
Space Complexity: O(4)
    Only constant size array is used
==================================================
*/
