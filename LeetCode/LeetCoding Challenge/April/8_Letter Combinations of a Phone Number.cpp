// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    string dic[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string given;
    vector <string> ans;
    int target;
 
public:
    void makeCombinations(int digit,string tmp){
        if(digit==-1) return;
        if(digit==target){
            ans.push_back(tmp);
            digit = -1;
            return;
        }
        int current;
        current = given[digit]-'0';
        for(int i=0;i<dic[current].length();i++){
            makeCombinations(digit+1,tmp+dic[current][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        target = digits.length();
        given = digits;
        makeCombinations(0,"");

        return ans;
    }
};

int main(void){
    Solution S;
    vector <string> ans;
    ans = S.letterCombinations("2");
    for(auto a : ans) cout << a << ",";
    cout << endl;
    

    return 0;
}