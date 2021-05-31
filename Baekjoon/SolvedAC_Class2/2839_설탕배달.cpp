#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,cpyN,kg3=0,kg5=0,answer=5000,curAnswer;
    cin >> N;
    for(int i=0;i<=N/5;i++){
        cpyN = N - i*5;
        kg3 = cpyN/3;
        if(cpyN%3==0){
            curAnswer = cpyN/3 + i;
            if(curAnswer<answer) answer = curAnswer;
        }
    }
    if(answer==5000) cout << "-1\n";
    else cout << answer << "\n";
    return 0;
}