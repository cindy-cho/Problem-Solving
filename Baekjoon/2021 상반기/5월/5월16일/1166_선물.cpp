#include<iostream>
#include<math.h>
using namespace std;

#define ll long long

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N,L,W,H,A=1,S,E,A2;
    long long SUM;
    int i,cnt=0;
    cin >> N >> L >> W >> H;
    A2 = min(L,min(W,H));
    E = A2*1.0;
    S = 0.0;
    // while(S<E)
    while(E-S >= 0.000000001 && cnt<100){
        cnt++;
        
        A = (E+S) / (2.0);
        SUM = (ll)(L/A)*(ll)(W/A)*(ll)(H/A);
        if(SUM >= N) S = A;
        else if(SUM <N) E = A;
    }

    printf("%.10lf\n",S);
    
    return 0;
}