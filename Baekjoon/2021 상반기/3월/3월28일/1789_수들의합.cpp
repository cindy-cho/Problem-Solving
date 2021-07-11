#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long  N;
    long long  S;
    long long  T,T2;
    cin >> N;
    if(N==1){ cout << "1\n";
    return 0;}
    if(N==2){ cout << "1\n";
    return 0;}
    if(N==3){ cout << "2\n";
    return 0;}

    N = N*2;
    S = sqrt(N);
    N=N/2;
    S++;


    T = S * (S+1) / 2;
  
    while(T>N){
        S--;
        T=S*(S+1)/2;
       
        if(T==N){ cout << S << "\n";
        return 0;
        }
        
    }

    T2 = (S+1)*(S+2)/2;
   if(N>=T && N <T2) cout << S << endl;

    return 0;
}

