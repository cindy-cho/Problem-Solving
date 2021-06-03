#include<iostream>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    while(1){
        if(a==0 && b==0 && c==0) break;
        if(a<b) swap(a,b);
        if(a<c) swap(a,c);
        // a가 최대값
        if(a*a == b*b + c*c) cout << "right" << endl;
        else cout << "wrong" << endl;
        cin >> a >> b >> c ;
    }
    return 0;
}