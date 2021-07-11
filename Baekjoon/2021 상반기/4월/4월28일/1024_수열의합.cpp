#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,L;
    int E,S;
    int sum = 0;
    cin >> N >> L;
    for(int i=L;i<=100;i++){
        sum = (i-1)*i/2;
        S = 0;
        E = i-1;
        if(N==sum){
            for(int j=S;j<=E;j++) cout << j << " ";
            return 0;
        }
        else if(N>sum && (N-sum)%i==0){
            
            S = (N-sum)/i;
            E = S + i -1;;
            // cout << S << "," << E << endl;
            for(int j=S;j<=E;j++) cout << j << " ";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}