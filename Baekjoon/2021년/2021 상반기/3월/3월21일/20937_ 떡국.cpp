#include<iostream>

using namespace std;

int main(void){
    int N,i,val,ans=0,max=0,sflag=1;
    int tteok[50000]={0,};
    scanf("%d",&N);
    for(i=0;i<N;i++){
       scanf("%d",&val);
       tteok[val-1]++;
       if(tteok[val-1]>max) max=tteok[val-1];
    }

  

    cout << max << "\n";
    return 0;
}

