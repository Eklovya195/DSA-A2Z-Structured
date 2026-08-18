/*
Problem: The Painter's Partition Problem-II
Problem Statement:Given an array arr[] where each element denotes the length of a board, and an integer k representing the number of painters available.
Each painter takes 1 unit of time to paint 1 unit length of a board.
Determine the minimum amount of time required to paint all the boards, under the constraint that each painter can paint only a contiguous sequence of boards (no skipping or splitting allowed).
Platform: Binary Search / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1"
==================================================
Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
==================================================
*/

/*
Approach:
Key Idea
    Instead of deciding which painter paints which boards, decide the maximum time a painter is
    allowed to work and check if the job can be completed using at most K painters.
    Question to check:
    If each painter can work for at most T time, can all boards be painted using ≤ K
    painters?
    ● If more than K painters are needed → T is too small
    ● If K or fewer painters are enough → T is valid
    This condition is monotonic, so Binary Search applies.
Search Space
    ● Minimum time = max(boards)
    (a painter must paint at least one full board)
    Prepared by Vinay Kajla Instagram: @Vinay.Kajla_
    ● Maximum time = sum(boards)
    (one painter paints all boards)
    low = max(boards)
    high = sum(boards)
Feasibility Function: countPainters(time)
Greedy allocation:
● Assign boards in order to the current painter
● If adding a board exceeds time, assign it to a new painter
*/


#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int>& boards, int time) {
    int painters = 1;
    long long currentWork = 0;
    for (int i = 0; i < boards.size(); i++) {
        if (currentWork + boards[i] <= time) {
            currentWork += boards[i];
        } else {
            painters++;
            currentWork = boards[i];
        }
    }
    return painters;
}
int painterPartition(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << painterPartition(boards, k) << endl;
    return 0;
}

/*
==================================================
Feasibility check: O(N)
Binary Search: O(log(sum − max))
Total Time: O(N log(sum − max))
Space: O(1)
==================================================
*/