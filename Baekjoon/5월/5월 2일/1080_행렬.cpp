#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    char P;
    int count=0;
    int maxCount=2500,maxI,maxJ,sum;
    cin >> N >> M;
    vector<vector<int>> A(N,vector<int> (M));
    vector<vector<int>> B(N,vector<int> (M));
    vector<vector<int>> C(N-2,vector<int> (M-2));
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> P;
            if(P=='0') A[i][j] = 0;
            else A[i][j] = 1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> P;
            if(P=='0') B[i][j] = 0;
            else B[i][j] = 1;
        }
    }
    for(int i=0;i<N-2;i++){
        for(int j=0;j<M-2;j++){
            sum = 0;
            for(int a=0;a<3;a++){
                for(int b=0;b<3;b++){
                    sum += A[i+a][j+b]^B[i+a][j+b];
                }
            }
            if(maxCount < sum){
                maxCount = sum;
                maxI = i;
                maxJ = j;
            }
        }
    }
    if(maxCount==0){
        cout << "0\n";
        return 0;
    }
    while(maxCount!=0 && count<1000){
        count ++;
        maxCount = 0;
        for(int i=0;i<N-2;i++){
            for(int j=0;j<M-2;j++){
                sum = 0;
                for(int a=0;a<3;a++){
                    for(int b=0;b<3;b++){
                        sum += A[i+a][j+b]^B[i+a][j+b];
                    }
                }
                if(maxCount < sum){
                    maxCount = sum;
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        for(int i=maxI;i<maxI+3;i++){
            for(int j=maxJ;j<maxJ+3;j++){
                A[i][j] = !A[i][j];
            }
        }
    }
    if(count>=1000) cout << "-1\n";
    cout << count-1 << "\n";

    return 0;
}


// 1 1 1 0      0 1 1 1
// 1 1 0 0      0 1 0 1
// 1 1 1 0      0 1 1 1

// 1 0 0 1       1 0 0 1
// 1 0 1 1       1 0 1 1
// 1 0 0 1       1 0 0 1