#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int N,A,B,i;
    int big,small,temp;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d %d",&A,&B);
        big = max(A,B);
        small = min(A,B);

        while(big%small!=0){
            temp = big%small;
            big = small;
            small = temp;
        }

        cout << A / small * B << endl;
    }

    return 0;
}