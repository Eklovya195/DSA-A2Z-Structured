/*
Problem:Build Up logicl thinnking by generating some patterns
Platform: Basic patterns/ Striver A2Z
Difficulty: Easy
Practice Link:"https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa"
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    // Pattern 1
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // Pattern 2
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 3
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 4
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 5
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 6
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 7
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     for(int j=1;j<=2*i-1;j++){
    //         cout << "*";
    //     }
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    
    //Pattern 8
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i-1;j++){
    //         cout << " ";
    //     }
    //     for(int j=1;j<=(2*n-2*i+1);j++){
    //         cout << "*";
    //     }
    //     for(int j=1;j<=i-1;j++){
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    //Pattern 9
    // for(int i=1;i<=n;i++){ //upper half
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     for(int j=1;j<=2*i-1;j++){
    //         cout << "*";
    //     }
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=1;i<=n;i++){ //lower half
    //     for(int j=1;j<=i-1;j++){
    //         cout << " ";
    //     }
    //     for(int j=1;j<=(2*n-2*i+1);j++){
    //         cout << "*";
    //     }
    //     for(int j=1;j<=i-1;j++){
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    //Pattern 10
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // for(int i=n-1;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    //Pattern 11
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         if((i+j)%2==0){
    //             cout << "1 ";
    //         }
    //         else{
    //             cout << "0 ";
    //         }
    //     }
    //     cout << endl;
    // }

    //Pattern 12
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << j;
    //     }
    //     for(int j=1;j<=2*(n-i);j++){
    //         cout << " ";
    //     }
    //     for(int j=i;j>=1;j--){
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    //Pattern 13
    // int x = 1;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << x << " ";
    //         x++;
    //     }
    //     cout << endl;
    // }

    //Pattern 14
    // for(int i=1;i<=n;i++){
    //     char ch = 'A';
    //     for(int j=1;j<=i;j++){
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    //Pattern 15
    // for(int i=n;i>=1;i--){
    //     char ch = 'A';
    //     for(int j=1;j<=i;j++){
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    //Pattern 16
    // char ch = 'A';
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout << ch << " ";
    //     }
    //     ch++;
    //     cout << endl;
    // }

    //Pattern 17
    // for(int i=1;i<=n;i++){
    //     char ch = 'A';
    //     //for spaces
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     //for increasing part of characters
    //     for(int j=1;j<=i;j++){     
    //             cout << ch;
    //             ch++;
    //     }
    //     ch--;
    //     //for decreasing part of character
    //     for(int j=i+1;j<=(2*i-1);j++){
    //         ch--;
    //         cout << ch;
    //      }
    //      //for last spaces
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    //Pattern 18
    // for(int i=1;i<=n;i++){
    //     char ch = 'E';
    //     ch = ch-i+1;
    //     for(int j=1;j<=i;j++){
    //         cout << ch;
    //         ch++;
    //     }
    //     cout << endl;
    // }

    //Pattern 19
    //upper half
    // for(int i=1;i<=n;i++){
    //     //for star
    //     for(int j=1;j<=n-i+1;j++){
    //         cout << "*";
    //     }
    //     //for space
    //     for(int j=1;j<=(2*i-2);j++){
    //         cout << " ";
    //     }
    //     //for Star
    //     for(int j=1;j<=n-i+1;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // //lower half
    // for(int i=1;i<=n;i++){
    //     //for star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     //for space
    //     for(int j=1;j<=(2*n-2*i);j++){
    //         cout << " ";
    //     }
    //     //for Star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    //Pattern 20
    //Upper Half
    // for(int i=1;i<=n;i++){
    //     //for star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     //for space
    //     for(int j=1;j<=(2*n-2*i);j++){
    //         cout << " ";
    //     }
    //     //for Star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // //Lower half
    // for(int i=n-1;i>=1;i--){
    //     //for star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     //for space
    //     for(int j=1;j<=(2*n-2*i);j++){
    //         cout << " ";
    //     }
    //     //for Star
    //     for(int j=1;j<=i;j++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    //Pattern 21
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         if(i==1 || i==n){
    //             cout << "*";
    //         }else{
    //             if(j==1 || j==n){
    //                 cout << "*";
    //             }else{
    //                 cout << " ";
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

    //Pattern 22
    //this is the good concept learning
    // for(int i=0;i<(2*n-1);i++){
    //     for(int j=0;j<(2*n-1);j++){
    //         int top = i;
    //         int left = j;
    //         int right = (2*n-2)-i;
    //         int bottom = (2*n-2)-j;
    //         cout << (n-min(min(top,bottom),min(left,right)));
    //     }
    //     cout << endl;
    // }

    

}