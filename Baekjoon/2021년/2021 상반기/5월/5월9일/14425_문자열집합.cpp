#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map <string,int> dic;
    int N,M;
    int ans=0;
    string input;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        dic[input] = 1;
    }
    for(int i=0;i<M;i++){
        cin >> input;
        if(dic[input]==1) ans++;
    }
    cout << ans << "\n";
    return 0;
}