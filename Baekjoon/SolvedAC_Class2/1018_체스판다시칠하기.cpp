#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    int min,tmp;
    string sample1="WBWBWBWB",sample2="BWBWBWBW";
    cin >> N >> M;
    min = N*M;
    vector <string> chess (N);
    for(int i=0;i<N;i++){
        cin>> chess[i];
    }
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            for(int k=0;k<8;k++){
                
            }
        }
    }
    return 0;
}