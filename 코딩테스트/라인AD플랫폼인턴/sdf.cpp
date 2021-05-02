#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string inputString) {
    int answer = 0;
    stack <char> s;
    char t;
    int len = inputString.length();
    int success = 0;
    if(inputString[0]==')' || inputString[0]=='}' || inputString[0]==']' || inputString[0]=='>') return 0;
    for(int i=0;i<len;i++){
        if(inputString[i]=='(' || inputString[i]=='{' || inputString[i]=='[' || inputString[0]=='<'){   
            s.push(inputString[i]);
        }
        else if(inputString[i]==')' || inputString[i]=='}' || inputString[i]==']' || inputString[0]=='>'){
            t = s.top();
            s.pop();
            if(inputString[i]==')' && t == '(') success++;
            else if(inputString[i]=='}' && t == '{') success++;
            else if(inputString[i]==']' && t == '[') success++;
            else if(inputString[i]=='>' && t == '<') success++;
            else return -i;
        }
    }
    if(!s.empty()) answer = -(len-1);
    else answer = success;
    return answer;
}