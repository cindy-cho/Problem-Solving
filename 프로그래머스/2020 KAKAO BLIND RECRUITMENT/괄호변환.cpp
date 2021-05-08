#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
string answer;
void divideString(string p);

void addSolution(string u,string v){
    // cout << "addSolution : " << u << "   ///   " << v << endl;
    // cout << "answer current : " << answer << endl;
    int len = u.length();
    int check=0,i;
    for(i=0;i<len;i++){
        if(u[i]=='(') check++;
        else check--;
        if(check<0) break;
    }
    if(check!=0){ //4번 과정
        answer += '(';
        divideString(v);
        answer += ')';
        for(i=1;i<len-1;i++){
            if(u[i]=='(') answer += ')';
            else answer += '(';
        }
    }
    else{ // 3번 
        answer += u;
        divideString(v);
    }
}

void divideString(string p){
    // cout << "divide STring : " << p << endl;
    // cout << "answer current : " << answer << endl;
    if(p.length()==0) return;
    int sCheck=0;
    int len = p.length();
    for(int i=0;i<len;i++){
        if(p[i]=='(') sCheck++;
        else sCheck--;
        if(i!=0 && sCheck==0){
            addSolution(p.substr(0,i+1),p.substr(i+1,len-i-1));
            break;
        }
    }
}
string solution(string p) {
    answer = "";
    if(p.empty()) return p;
    int len = p.length();
    int check=0,i;
    for(i=0;i<len;i++){
        if(p[i]=='(') check++;
        else check--;
        if(check<0) break;
    }
    if(check==0) return p;
    divideString(p);
    return answer;
}