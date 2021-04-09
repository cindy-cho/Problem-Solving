#include<iostream>

using namespace std;

 int main(void){
     int N,i,j;
     scanf("%d",&N);

     for(i=0;i<N;i++){
         for(j=N;j>i;j--) printf("*");
         printf("\n");
     }
     return 0;
 }