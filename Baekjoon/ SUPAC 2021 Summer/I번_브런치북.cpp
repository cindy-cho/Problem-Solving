#include<iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
#include <string>


#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int N;
    string alpha = "0123456789abcedf";
    ll rest;
    ll K;
    cin >> T;
    for(int i=0;i<T;i++){
        string ans="";
        cin >> N >> K;
        K--;
        while(K>0){
            rest = K % 16;
            K = K / 16;
            ans = alpha[rest] + ans;
        }
        while(ans.length()<N){
            ans = '0' + ans;
        }
        cout << ans << endl;
    }
    return 0;
}