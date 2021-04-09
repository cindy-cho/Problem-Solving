#include<iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A,B;
    cin >> A >> B;
    int lenA=A.length(),lenB=B.length();
    int diff = lenB-lenA;
    int max=50,now=0;
    int Aidx,Bidx;

    for(int i=0;i<=diff;i++){
        now=0;
        Aidx=0;
        Bidx=i;
        for(int j=0;j<lenA;j++){
            if(A[Aidx]!=B[Bidx]){
                now++;
            }
            Aidx++;
            Bidx++;
        }
        if(now<max){
            max = now;
        }
    }

    cout << max << "\n";
    
    return 0;
}
