#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int AT,AB,BT,BB;
    int CT,CB;
    cin >> AT >> AB >> BT >> BB;
    CB = AB*BB;
    CT = AT*BB + BT*AB;
    for(int i=sqrt(CT);i>=2;i--){
        if(CT%i==0 && CB%i==0){
            CT /=i;
            CB /=i;
        }
    }
    cout << CT << " " << CB << "\n";
    return 0;
}