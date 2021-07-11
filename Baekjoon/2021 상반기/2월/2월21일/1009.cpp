#include<iostream>


using namespace std;

int main(void){
    int N,i,j,a,b,value;
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        value = a%10;
        for(j=1;j<b;j++) value = value*a%10;
        if(value==0) value = 10;
        cout << value << endl;

    }
    
    return 0;
}