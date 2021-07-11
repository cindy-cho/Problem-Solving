#include<stdio.h>
long long int arr[10];
int main(void){
    int T,n,i,j,k;
    long long int ans;
    arr[0]=1;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        ans = 0;
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            for(k=1;k<10;k++){
                if(j==1) arr[k]=1;
                else arr[k]=arr[k-1]+arr[k];
        }}
        for(k=0;k<10;k++) ans+=arr[k];
        printf("%lld\n",ans);
    }
    return 0;
}