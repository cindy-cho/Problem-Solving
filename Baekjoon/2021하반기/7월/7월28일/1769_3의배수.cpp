#include<iostream>
#include<string>
#define endl '\n'
typedef long long ll;

using namespace std;

bool isAnswer(ll num){
    if(num==3 || num==6 || num ==9) return true;
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll answer = 0;
    ll newAnswer;
    int crnt;
    string input;
    int step = 0;
    cin >> input;
    int inLen = input.length();
    if(inLen==1){
        cout << "0" <<endl;
        if(input=="3" || input=="6" || input=="9") cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    for(int i=0;i<inLen;i++){
        crnt = input[i]-'0';
        answer += crnt;
    }
    step ++;
    while(answer>=10){  // >= equal을 붙였어야~~!
        step++;
        newAnswer = 0;
        while(answer>0){
            newAnswer += answer % 10;
            answer /= 10;
        }
        answer = newAnswer;
    }
    cout << step << endl;
    if(isAnswer(answer)==true) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}