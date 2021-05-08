#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0, idx=0, len=s.length();
    char tmp;
    string intAns="";
    string alpha[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    int alphaLen[10] = {4,3,3,5,4,4,3,5,5,4};
    
    while(1){
        if(idx>=len) break;

        if(s[idx]>='0' && s[idx]<='9'){
            intAns += s[idx];
            idx++;
        }
        else{
            for(int i=0;i<10;i++){
                if(idx+alphaLen[i]<=len && s.substr(idx,alphaLen[i]) == alpha[i]){
                    tmp = '0' + i;
                    intAns += tmp;
                    idx+=alphaLen[i];
                    break;
                }
            }
        }
    }
    
    answer = stoi(intAns);
    return answer;
}