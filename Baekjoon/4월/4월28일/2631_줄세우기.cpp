#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,ans=0;
    cin >> N;
    vector<int> kid(N);
    vector<int> LIS(N,0);
    
    for(int i=0;i<N;i++) {
        cin >> kid[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(kid[j] < kid[i] && LIS[i] < LIS[j]+1) {
                LIS[i] = LIS[j] + 1;
                if(LIS[i] > ans) ans = LIS[i];
            }
        }
    }

    cout << N-ans-1 << "\n";
    return 0;
}