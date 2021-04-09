#include<iostream>
using namespace std;

int main(void){
    int N;
    int oL,oR,nL,nR, cycle=0;

    scanf("%d",&N);
    oL = N/10;
    oR = N%10;
    while(1){
        cycle ++;
        nL = (oL+oR) / 10;
        nR = (oL+oR) % 10;
        oL = oR;
        oR = nR;

        if(oL*10+oR==N) break;
    }

    cout << cycle << endl;
    return 0;
}