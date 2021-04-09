// Example 1:

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:

// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:

// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        return true;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string order;
    Solution S;
    string input[] = {"hello","leetcode"};
    vector<string> words;
    for(auto i:input) words.push_back(i);
    for(auto w:words) cout << w << endl;
    S.isAlienSorted(words,"hlabcdefgijkmnopqrstuvwxyz");
    
    return 0;
}

