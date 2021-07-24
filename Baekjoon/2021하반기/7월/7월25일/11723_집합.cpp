#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,x;
    vector<bool> status(21,false);
    string op;
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> op;
        if(op=="add"){
            cin >> x;
            status[x]=true;
        }
        else if(op=="remove"){
            cin >> x;
            status[x]=false;
        }
        else if(op=="check"){
            cin >> x;
            if(status[x]==false){
                cout << "0" << endl;
            }
            else cout << "1" << endl;
        }
        else if(op=="toggle"){
            cin >> x;
            if(status[x]==false) status[x]=true;
            else status[x]=false;;
        }
        else if(op=="all"){
            for(int j=1;j<=20;j++) status[j]=true;
        }
        else if(op=="empty"){
            for(int j=1;j<=20;j++) status[j]=false;
        }
    }
    return 0;
}