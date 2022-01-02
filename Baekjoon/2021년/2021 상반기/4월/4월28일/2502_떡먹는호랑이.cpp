#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C,D,K;
    int m;
    cin >> D >> K;
    for(int i=1;i<=K/D;i++){
        for(int j=i+1;j<=K/(D-2);j++){
            A=i;
            B=j;
            for(m=3;m<=D;m++){
                C = A+B;
                A = B;
                B = C;
                if(m<D && B>=K) break;               
            }
            if(m==D+1 && B==K){
                cout << i << "\n" << j << "\n";
                return 0;
            }
        }
    }
    return 0;
}