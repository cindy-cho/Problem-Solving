#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,N;
    cin >> T;
    string input,ans;
    for(int i=0;i<T;i++){
        ans = "";
        cin >> N >> input;
        for(auto i:input){
            for(int j=0;j<N;j++) ans+=i;
        }
        cout << ans <<  "\n" ;
    }
    return 0;
}