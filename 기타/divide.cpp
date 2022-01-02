#include <stdio.h>
double divide(int x, int y){
    double z;
    z = (double)x / (double)y;
    return z;
}

void main(){
    int a,b;
    double result;
    a = 10;
    b = 12;
    result = divide(a,b);
    printf("나눗셈 결과는 : %g \n",result);
}