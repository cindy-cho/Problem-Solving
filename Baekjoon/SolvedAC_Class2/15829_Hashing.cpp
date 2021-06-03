#include<iostream>
#include<string>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll r=31,M=1234567891,H,len,dec,sum=0,mul=1;
    int N;
    string input;
    cin >> N;
    cin >> input;
    
    for(int i=0;i<N;i++){
        dec = input[i]-'a'+1;
        sum += dec*mul;
        mul *= r;
        mul %= M;
        sum %= M;
    }
    cout << sum << endl;
    return 0;
}