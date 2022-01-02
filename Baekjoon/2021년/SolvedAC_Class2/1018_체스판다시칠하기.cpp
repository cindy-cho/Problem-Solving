#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,cmpIdx;
    int minAnswer=2500,toColor;
    string cmp[2]={"BWBWBWBW","WBWBWBWB"};
    cin >> N >> M;
    vector <string> chess (N);
    for(int i=0;i<N;i++){
        cin>> chess[i];
    }

    for(int i=0;i<N-7;i++){
        for(int j=0;j<M-7;j++){
            toColor = 0;
            cmpIdx = 0;
            for(int a=0;a<8;a++){
                for(int b=0;b<8;b++){
                    if(cmp[cmpIdx][b]!=chess[i+a][j+b]) toColor++;
                }
                cmpIdx = (cmpIdx+1)%2;
            }
            if(minAnswer > toColor) minAnswer = toColor;

            toColor = 0;
            cmpIdx = 1;
            for(int a=0;a<8;a++){
                for(int b=0;b<8;b++){
                    if(cmp[cmpIdx][b]!=chess[i+a][j+b]) toColor++;
                }
                cmpIdx = (cmpIdx+1)%2;
            }
            if(minAnswer > toColor) minAnswer = toColor;
        }
    }

    cout << minAnswer << "\n";
    return 0;
}