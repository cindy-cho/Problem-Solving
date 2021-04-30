#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string S, E, Q, T, id;
    map <string, int> check;
    int iS,iE,iQ,iT;
    long long int ANS=0;
    cin >> S >> E >> Q;
    iS = stoi(S.substr(0,2)) * 60 + stoi(S.substr(3,2));
    iE = stoi(E.substr(0,2)) * 60 + stoi(E.substr(3,2));
    iQ = stoi(Q.substr(0,2)) * 60 + stoi(Q.substr(3,2));
    
    while(1){
        cin >> T >> id;
        if(cin.eof()) break;
        iT = stoi(T.substr(0,2)) * 60 + stoi(T.substr(3,2));
        if(iT<=iQ){
            if(check.find(id)==check.end()){
                check.insert({id,iT});
            }
            else{
                if(check[id]==-1) continue;
                else if(iT<=iS) check[id] = iT;
                else if(check[id] <=iS && iT>=iE && iT<=iQ){
                    ANS++;
                    check[id] = -1;
                }
            }
        }
        cout << ANS << "\n";
    }

    cout << ANS << "\n";
    return 0;
}