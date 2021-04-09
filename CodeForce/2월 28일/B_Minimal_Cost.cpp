#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//위아래 u, 좌우 v
int main(void){
    int t,n,u,v;
    int i,j,preVal,val,status=1;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d",&n,&u,&v);
        status=1;
        for(j=0;j<n;j++){
            scanf("%d",&val);
            if(j==0) preVal=val;
            if(status==2) continue;
            else{
                if(val==preVal) continue;
                else if(abs(val-preVal)>=2){
                    status=2;
                    continue;
                    
                }  
                else if(abs(val-preVal)==1) status=3;
            }
            preVal =val;
        }

        if(status==1) u+v > v+v ? cout << v+v << endl : cout << u+v << endl ;
        else if(status==2) cout << "0" << endl;
        else if(status==3) u > v ? cout << v << endl : cout << u << endl;
    }
    return 0;
}




