
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N, L,val,ans=0;
    double idx;
    int i;
    cin >> N >> L;
    // 0 1 2 3 4 5 .... 1000
    // 1 2 100 101
    // 0.5 1.5 1.5 2.5 99.5 100.5 101.5
    // 0.5 + 4= 4.5  
    // 0 0.5 1 1.5 2 2.5 .... 1000.5
    // 0 1 2 3 4 ...... 2001
    int water[2002]={0,};
    for(i=0;i<N;i++){
        cin>> val;
        idx = (val-0.5)*2;
        water[(int)idx]=1;
        idx = (val+0.5)*2;
        water[(int)idx]=1.;
    }
    for(i=0;i<2002;i++) if(water[i]==1) break;
    while(1){
        if(i>=2002) break;
        if(water[i]==1) ans++;
        i+=2*L;
        i++;
        for(;i<2002;i++) if(water[i]==1) break;
    }
    cout << ans << "\n";
    return 0;
}