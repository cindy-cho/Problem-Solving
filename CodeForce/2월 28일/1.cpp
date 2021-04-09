#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int main(void){
    unsigned long long t;
    scanf("%llu",&t);
    unsigned long long i,p,a,b,c,ta,tb,tc,time;
    for(i=0;i<t;i++){
        scanf("%llu %llu %llu %llu",&p,&a,&b,&c);
        if(p>a) p%a==0 ? ta=0 : ta = a-(p%a);
        else ta=a-p;
        if(p>b) p%b==0 ? tb = 0 : tb = b-(p%b);
        else tb=b-p;
        if(p>c) p%c==0 ? tc = 0 : tc = c-(p%c);
        else tc=c-p;
        time = min(ta,min(tb,tc));
        printf("%llu\n",time);
    }
    return 0;
}