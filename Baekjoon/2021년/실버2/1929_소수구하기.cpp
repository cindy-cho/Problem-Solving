#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,N,flag;
    cin >> M >> N;
    for(int i=M;i<=N;i++){
        flag = 1;
        if(i==1) continue;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        if(flag==1) cout << i << "\n";
    }
    return 0;
}