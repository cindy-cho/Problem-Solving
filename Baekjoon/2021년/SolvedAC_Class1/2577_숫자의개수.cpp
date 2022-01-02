#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long A,B,C;
    vector<int> dec(10,0);
    cin >> A >> B >> C ;
    C *= A*B;
    while(C>0){
        dec[C%10]++;
        C/=10;
    }
    for(int i=0;i<10;i++){
        cout << dec[i] << "\n";
    }
    return 0;
}