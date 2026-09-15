/*
Problem:  127. Word Ladder
Platform: Graph / Striver A2Z
Difficulty: Hard
Practice Link: "https://leetcode.com/problems/word-ladder/"
==================================================
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
==================================================
*/

/*
Algorithm:
    This problem can be solved using Breadth First Search (BFS) because BFS always finds the shortest path.
    1. Treat each word as a node.
    2. Two words are connected if they differ by exactly one character.
    3. Push {startWord, 1} into a queue where 1 is the starting step.
    4. Store all words from wordList in an unordered_set for fast lookup.
    5. While the queue is not empty:
        ○ Pop the front word and its current step count.
        ○ If the word equals targetWord, return the step count.
        ○ For each character in the word:
            ■ Try replacing it with all characters from 'a' to 'z'.
            ■ If the new word exists in the set:
            ■ Remove it from the set (to avoid revisiting).
            ■ Push it into the queue with steps + 1.
    6. If BFS ends without reaching targetWord, return 0.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            //if word == endWord return steps
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                //after checking replace orginal element
                word[i] = original;
            }
        }
        return 0;
    }
};

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    Solution obj;
    cout << obj.ladderLength(beginWord,endWord,wordList);
    return 0;
}


/*
==================================================
Time Complexity: O(N × L × 26)
    Reason: For each word, we try changing all L characters to 26 possible letters.
            here we are taking unordered set therefore O(1) for set otherwise it also take logn
Space Complexity: O(N × L)
    Reason: Space used by the unordered_set and BFS queue.
==================================================
*/