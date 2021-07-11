
#include<stdio.h>
using namespace std;

int main(void){
    int N; 
    int idx=0,mov=0;
    int i;
    scanf("%d",&N);
    int balloon[1000];
    for(i=0;i<N;i++){
        scanf("%d",&balloon[i]);
    }
    for(i=0;i<N;i++){
        while(mov!=0){
            if(mov>0){
                idx++;
                if(idx>=N) idx %=N;
                if(balloon[idx]!=0) mov--;
            }
            else{
                idx--;
                if(idx<0) idx+=N;
                if(balloon[idx]!=0) mov++;
            }
        }
        printf("%d ",idx+1);
        mov = balloon[idx];
        balloon[idx] = 0;
    }
    printf("\n");
    return 0;
}