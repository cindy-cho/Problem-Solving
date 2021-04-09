#include<iostream>
#include<string>

using namespace std;

int main(void){
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string days[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int x,y,i,count=0;

    scanf("%d %d",&x,&y);
    for(i=0;i<x-1;i++) count+=month[i];
    count+=y;

    count%=7;
    cout << days[count] <<endl;
    return 0;
}