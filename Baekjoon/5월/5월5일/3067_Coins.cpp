#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    int T,N,M;
    cin >> T;
    int coin[20];
    for(int i=0;i<T;i++){
        cin >> N;
        for(int j=0;j<N;j++) cin >> coin[j];
        cin >> M;
        vector<unsigned long long int> money(M+1,0);
        for(int j=0;j<N;j++){
            for(int k=1;k<=M;k++){
                if(k+coin[j]<=M) money[k+coin[j]] +=money[k];
                if(k%coin[j]==0) money[k]++;
            }
        }
        cout << money[M] << "\n";
    }
    return 0;
}