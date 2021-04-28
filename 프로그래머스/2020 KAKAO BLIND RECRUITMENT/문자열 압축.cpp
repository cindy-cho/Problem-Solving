/*
숫자를 문자로 변환할때는 +0이 아니라 10,100같은 경우는 2자리, 3자리 차지한다는 것 기억
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int solution(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = s.length()*2, repeated=0, lenTmp;
    int len = s.length();
    string parsed, preParsed, tmpS;
    for(int i=1;i<=len;i++){ //길이만큼 자를거임
        tmpS = "";
        lenTmp = 0;
        repeated = 1;
        preParsed = "";
        for(int j=0;j<len/i;j++){
            parsed = s.substr(j*i,i);
            if(j!=0 && parsed == preParsed) repeated++;
            else if(j!=0){
                if(repeated==1){
                    tmpS += preParsed;
                }
                else {
                    if(repeated<10) repeated = 1;
                    else if(repeated<100) repeated = 2;
                    else repeated = 3;
                    lenTmp += repeated;
                    tmpS += preParsed;
                    repeated = 1;
                }
            }
            preParsed = parsed;
        }
        if(repeated==1){
            tmpS += preParsed;
        }
        else{
            if(repeated<10) repeated = 1;
            else if(repeated<100) repeated = 2;
            else repeated = 3;
            lenTmp += repeated;
            tmpS += preParsed;
        }
        if(answer > tmpS.length()+(len%i)+lenTmp) answer = lenTmp+tmpS.length()+(len%i);
    }
    return answer;
}