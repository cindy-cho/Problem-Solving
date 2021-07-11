#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double f;
    double ans=0;
    scanf("%d",&n);
    vector<double> saved(n);
    for(int i=0;i<n;i++){
        scanf("%lf",&saved[i]);
    }
    for(int i=0;i<n;i++){
        f = saved[i];
        if( f > ans) ans = f;
        for(int j=i+1;j<n;j++){
            f *=saved[j];
            if(f>ans) ans = f;
        }
        if( f > ans) ans = f;
    }

    printf("%.3lf\n",ans);
    return 0;
}

