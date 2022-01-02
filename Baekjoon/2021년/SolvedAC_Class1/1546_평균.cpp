#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N,M=0,T=0;
    cin >> N;
    vector<int> score(N);
    for(int i=0;i<N;i++){
        cin>>score[i];
        T +=score[i];
        if(score[i]>M) M=score[i];
    }
    cout << T/M*100/N << "\n";
    return 0;
}