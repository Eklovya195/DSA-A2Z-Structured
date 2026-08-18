/*
Problem: Book Allocation
Problem Statement:You have N books, where the i-th book has A[i] pages. There are M students.
You need to distribute all books to the students with these rules:
Each student must get at least one book.
Each book can be given to only one student.
The books given to a student must be next to each other (contiguous).
Your task is to distribute the books so that the maximum pages any student gets is as small as possible.
If it is not possible to distribute the books, print -1.
Platform: Binary Search / Striver A2Z
Difficulty: Hard
Practice Link: "https://www.codechef.com/practice/course/binary-search-new/BINARYSP07/problems/BOOKALLOCATE"
==================================================
Input Format
First line: two integers N (number of books) and M (number of students).
Second line: N integers, where A[i] = pages in the i-th book.
Output Format
Print the minimum possible value of the maximum pages assigned to a student.
If distribution is not possible, print -1.
==================================================
*/

/*
Key Observation:
    We cannot directly find the optimal allocation, but we can check feasibility.
    Question to ask:
    If each student is allowed to read at most X pages, can we allocate all books using
    ≤ m students?
    ● If more than m students are required → X is too small
    ● If m or fewer students are sufficient → X is valid
    This feasibility condition is monotonic → Binary Search applies
Search Space
    ● Minimum pages = max(arr[])
    (a student must read at least one full book)
    ● Maximum pages = sum(arr[])
    (one student reads all books)
    low = max(arr)
    high = sum(arr)
    countStudents(pages)
Greedy allocation:
    ● Start with one student
    ● Add books to the current student until page limit exceeds
    ● Then assign next book to a new student
    students = 1
    currentPages = 0
    for each book:
    if currentPages + book <= pages:
    currentPages += book
    else:
    students++
    currentPages = book
    Return the number of students needed.

*/

//Brute Force (Linear Approach)
/*
#include <bits/stdc++.h>
using namespace std;

int StudentCount(vector<int> &books,int pages){
    int students = 1;
    int pagecnt = 0;
    for(int i=0;i<books.size();i++){
        if(books[i]+pagecnt <= pages){
            pagecnt += books[i];
        }else{
            students++;
            pagecnt = books[i];
        }
    }
    return students;
}

int main(){
    int m=4; //# of students
    int n=5; // # of books
    vector<int> books = {25,46,28,49,24};
    if(m>n) cout << -1;
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    for(int pages=low;pages<=high;pages++){
        int cntstudent = StudentCount(books,pages);
        if(cntstudent == m){
            cout << pages;
            break;
        }
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O((sum-maxi)*O(n)) approx quadratic time complexity
Space Complexity: O(1)
==================================================
*/

//Optimal Approach (using Binary Search)
#include <bits/stdc++.h>
using namespace std;

int StudentCount(vector<int> &books,int pages){
    int students = 1;
    int pagecnt = 0;
    for(int i=0;i<books.size();i++){
        if(books[i]+pagecnt <= pages){
            pagecnt += books[i];
        }else{
            students++;
            pagecnt = books[i];
        }
    }
    return students;
}

int main(){
    int m=4; //# of students
    int n=5; // # of books
    vector<int> books = {25,46,28,49,24};
    if(m>n) cout << -1;
    int low = *max_element(books.begin(),books.end());
    int high = accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int cntstudent = StudentCount(books,mid);
        if(cntstudent > m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout << low;
    return 0;
}

/*
==================================================
Time Complexity: O(log(sum-maxi)*O(n))
Space Complexity: O(1)
==================================================
*/


//Note :- 9th 10th 11th problem all have same logic and exactly same code