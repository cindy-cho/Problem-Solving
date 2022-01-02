#include<iostream>
#include<string>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int black=0,white=0;
    char init;
    bool flag=false;
    string input;
    cin >> input;
    for(auto a:input){
        if(flag==false){
            init=a;
            flag=true;
        }
        if(a!=init){
            init == '1'? black++ : white++;
            init = a;
        }
    }
    init == '1' ? black++ : white++;
    black < white ? cout << black << endl : cout << white << endl;
    return 0;
}