#include<iostream>

using namespace std;

 int main(void){
     int N,i,j;
     scanf("%d",&N);

     for(i=0;i<N;i++){
         for(j=0;j<N-i-1;j++) printf(" ");
         for(j=0;j<i*2+1;j++) printf("*");
         printf("\n");
     }
     for(i=1;i<N;i++){
         for(j=0;j<i;j++) printf(" ");
         for(j=0;j<(N-1-i)*2+1;j++) printf("*");
         printf("\n");
     }
     return 0;
 }