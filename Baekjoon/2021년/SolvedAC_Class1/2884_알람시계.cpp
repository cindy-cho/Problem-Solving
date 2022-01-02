#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H,M,T;
    cin >>  H >> M;
    T  =  H*60 + M;
    T -= 45;
    if(T<0) T +=1440;
    cout << T/60 << " " << T%60 << "\n";
    return 0;
}