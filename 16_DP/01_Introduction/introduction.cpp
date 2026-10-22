/*
Dynamic Programming can be described as storing answers to various sub-problems to be used
later whenever required to solve the main problem.
The two common dynamic programming approaches are:
    ● Memoization: Known as the “top-down” dynamic programming, usually the
    problem is solved in the direction of the main problem to the base cases.
    ● Tabulation: Known as the “bottom-up '' dynamic programming, usually the
    problem is solved in the direction of solving the base cases to the main
    problem

Note: The base case does not always mean smaller input. It depends upon the implementation of
the algorithm.
*/

/*
We will be using the example of Fibonacci numbers here. The following series is called the Fibonacci
series:
0,1,1,2,3,5,8,13,21,...

We need to find the nth Fibonacci number, where n is based on a 0-based index. Every ith number of
the series is equal to the sum of (i-1)th and (i-2)th number where the first and second number is given
as 0 and 1 respectively
*/

//Normal Recursive code for finding nth fibonacci no is
/*
#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    //base case
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    int n = 6;
    cout << fib(n);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(2^n)
    Reason : Recursion is done here
Space Complexity: O(n)
    Reason: Recursion stack.
==================================================
*/

//Type1:Memoization Approach
/*
As every number is equal to the sum of the previous two terms, the recurrence relation can be
written as:
            f(n) = f(n-1)+f(n-2)
If there are two recursive calls inside a function, the program will run the first call, finish its execution
and then run the second call. Due to this reason, each and every call in the recursive tree will be
executed. This gives the recursive code its exponential time complexity. If we can store the values of
sub-problems in the first time, then we can simply find its value in constant time whenever we need
it. This technique is called Memoization. The cases which are solved again and again in recursion
are called overlapping sub-problems.

Steps to memoize a recursive solution:
    Any recursive solution to a problem can be memoized using these three steps:
    ● Create a dp[n+1] array initialized to -1.
    ● Whenever we want to find the answer of a particular value (say n),
        we first check whether the answer is already calculated using the
        dp array. If yes, simply return the value from the dp array.
    ● If not, then we are finding the answer for the given value for the
        first time, we will use the recursive relation as usual but before
        returning from the function, we will store the solution in our dp array.

*/

//Memoization code (use dp array to store previously calculated value)
/*
#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){
    //base case
    if(n<=1) return n;
    //if already computed return stored value
    if(dp[n]!=-1) return dp[n];
    //otherwise compute and store
    dp[n] = fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int n = 6;
    vector<int> dp(n+1,-1);
    cout << fib(n,dp);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(n)
    Reason : Recursion is done here but we only need to compute every value only on time for all n
Space Complexity: O(n+n)
    Reason: Recursion stack + dp array
==================================================
*/

//Type2:Tabulation Approach
/*
Tabulation is a bottom-up approach where we start from base cases and build the solution
iteratively. This avoids recursion and extra stack space.
Algorithm
    1. Create a dp array of size n+1.
    2. Initialize dp[0] = 0 and dp[1] = 1.
    3. Use a loop from 2 to n.
    4. Set dp[i] = dp[i-1] + dp[i-2].
    5. Return dp[n].
*/

/*
#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    //base case
    if(n<=1) return n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 6;
    cout << fib(n);
    return 0;
}
*/

/*
==================================================
Time Complexity: O(n)
    Reason : single loop from 2 to n
Space Complexity: O(n)
    Reason: dp array space.
==================================================
*/


//Type3: Space Optimization of Tabluation approach
/*
From the relation:
    dp[i] = dp[i-1] + dp[i-2]
We observe that we only need the previous two values, not the entire dp array.

Algorithm:
    1. Handle base cases n = 0 and n = 1.
    2. Use two variables:
        ○ prev2 for fib(i-2)
        ○ prev for fib(i-1)
    3. For each iteration, compute curr = prev + prev2.
    4. Update prev2 = prev and prev = curr.
    5. After the loop, return prev.
*/
#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    //base case
    if(n<=1) return n;

    int prev2 = 0;
    int prev1 = 1;;
    for(int i=2;i<=n;i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n = 6;
    cout << fib(n);
    return 0;
}

/*
==================================================
Time Complexity: O(n)
    Reason : single loop from 2 to n
Space Complexity: O(1)
    Reason: Only constant extra variables are used.
==================================================
*/