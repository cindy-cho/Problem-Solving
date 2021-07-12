#include<iostream>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int calNextNum(int crnt){
    int newNum = 0;
    newNum+= crnt;
    while(crnt>0){
        newNum+= crnt%10;
        crnt /=10;
    }
    return newNum;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<bool> notSelfNum(10001,false);
    int crnt;
    for(int i=1;i<10001;i++){
        if(notSelfNum[i]==true) continue;
        crnt = i;
        while(crnt<=10000){
            crnt = calNextNum(crnt);
            notSelfNum[crnt] = true;
        }
    }

    for(int i=1;i<10001;i++) if(notSelfNum[i]==false) cout << i << endl;

    return 0;
}