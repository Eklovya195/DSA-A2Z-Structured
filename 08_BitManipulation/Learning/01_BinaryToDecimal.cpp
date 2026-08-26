#include <bits/stdc++.h>
using namespace std;

int BinaryToDecimal(string x){
    int len = x.size();
    int p2 = 1;
    int num = 0;
    for(int i=len-1;i>=0;i--){
        if(x[i] == '1'){
            num += p2;
        }
        p2 = p2*2;
    }
    return num;
}

int main(){
    string x = "1011";
    int num = BinaryToDecimal(x);
    cout << num;
    return 0;
}

/*
==================================================
Time Complexity: O(len(string));
Space Complexity: O(1)
==================================================
*/