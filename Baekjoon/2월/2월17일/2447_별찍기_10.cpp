#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

void makingStars(int stage);

int main(void){
    int N,i,j,target;
    scanf("%d",&N);
    for(target=1;;target++) if(pow(3,target)==N) break;
    for(i=1;i<=target;i++) makingStars(i);

    return 0;
}