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
#include<algorithm>

using namespace std;

class Solution {
private:
    int dic[26];

public:

    void saveDictionary(string order){
        for(int i=0;i<26;i++){
            dic[order[i]-'a'] = i;
        }
    }

    bool isAlienSorted(vector<string>& words, string order) {
        saveDictionary(order);
        for(int i=0;i<words.size()-1;i++){
            if(wordsCompare(words[i],words[i+1])==false) return false;
        }
        return true;
    }

    bool wordsCompare(string a, string b){
        int len;
        len = min(a.length(),b.length());
        
        for(int i=0;i<len;i++){
            if(dic[a[i]-'a'] == dic[b[i]-'a']) continue;
            if(dic[a[i]-'a'] > dic[b[i]-'a']) return false;
            else return true;
        }
        if(len==a.length()) return true;
        return false;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    bool ans;
    vector<string> input{"apple","app"};
    ans = S.isAlienSorted(input,"abcdefghijklmnopqrstuvwxyz");
    if(ans==true) cout << "true\n";
    else cout << "false\n";
    
    return 0;
}

