#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int Pmin=1000,Smin=1000;
    int P,S;
    int ans=0,newAns=0;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> P >> S ; 
        if(Pmin>P) Pmin = P;
        if(Smin>S) Smin = S;
    }
    if(Pmin > Smin*6){
        ans = Smin*N;
    }
    else{
        if(N%6==0){
            ans = N/6 * Pmin;
        }
        else{
            newAns = (N/6+1) * Pmin;
            ans =  N/6 * Pmin + N%6 * Smin;
            if(newAns < ans) ans = newAns;
        }
    }
    cout << ans << "\n";
    return 0;
}