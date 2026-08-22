/*
Problem: 151. Reverse Words in a string
Problem Statement: Given an input string s, reverse the order of the words.
    A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
    Return a string of the words in reverse order concatenated by a single space.
    Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
Difficulty: Medium
Practice Link: "https://leetcode.com/problems/reverse-words-in-a-string/description/"
==================================================
Input: s = "the sky is blue"
Output: "blue is sky the"
==================================================
*/

//Brute Force Approach
/*
#include<bits/stdc++.h>
using namespace std;

vector<string> ReverseWordsInString(string s){
    vector<string> words;
    string word = "";
    //adding word to the words 
    for(char c:s){
        if(c!=' '){
            word += c;
        }else if(!word.empty()){
            words.push_back(word);
            word = "";
        }
    }
    //for one that is left(last word)
    if(!word.empty()){
        words.push_back(word);
    }
    //reverse the whole words string 
    reverse(words.begin(),words.end());
   return words;
}

int main(){
    string s = "  hello     world  ";
    int n = s.size();
    vector<string> ans = ReverseWordsInString(s);
    for(string word:ans){
        cout << word << " ";
    }
    return 0;
}
*/

/*
==================================================
Time Complexity: O(N)
    (single pass from right + single pass from left)
Space Complexity: O(N)
    (extra list to store words)
==================================================
*/

//Optimal Approach(Right to left scan)
/*
Idea: 
Instead of storing words and reversing later:
● Scan the string from right to left
● Extract each word and append it directly to the result
This avoids:
● Extra list
● Explicit reverse step
*/


#include <bits/stdc++.h>
using namespace std;

string ReverseWordsInString(string s) {
    string result = "";
    int i = s.size() - 1;

    while (i >= 0) {

        // Skip spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // If all characters are processed
        if (i < 0) break;

        int end = i;

        // Find the beginning of the word
        while (i >= 0 && s[i] != ' ') {
            i--;
        }

        // Extract the word
        string word = s.substr(i + 1, end - i);

        // Add space between words
        if (!result.empty()) {
            result += " ";
        }

        result += word;
    }

    return result;
}

int main() {
    string s = "  hello     world  ";
    cout << ReverseWordsInString(s);
    return 0;
}

/*
==================================================
Time Complexity: O(N)
    (single pass from right + single pass from left)
Space Complexity: O(N1)
==================================================
*/