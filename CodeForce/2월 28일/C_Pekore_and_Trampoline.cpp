#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int t,n,i,j,k,value,uBound;
    long long int total=0;
    
    scanf("%d",&t);
    for(i=0;i<t;i++){
        total=0;
        scanf("%d",&n);
        vector <long long int> S(n,0);
        for(j=0;j<n;j++){
            scanf("%d",&value);
            if(value==1) continue;
            else{
                S[j] = S[j] + value - 1;
                if(j+2 < n){
                    j+value>=n ? uBound=n-1 : uBound = j+value;
                    for(k=uBound;k>=j+2;k--) S[k]--;
                }
                if(S[j]>=1) total+=S[j];
            }
        }
        cout << total << endl;
    }
    return 0;
}

/*
0 1 2 3 4  5 6
1 4 2 2  2 2 2
0 3   -1-1-1
    1   -1
      1   -1
         1   -1
           1  1

0 3 1 0 -1 -1 0 */
