#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,M,B,Bcpy,time,minTime,min=256,max=1,height;
    int flag = 0;
    cin >> N >> M >> B;
    vector<int> ground(N*M);
    for(int i=0;i<N*M;i++) {
        cin >> ground[i];
    }
    sort(ground.begin(),ground.end());
    min = ground[0];
    max = ground[N*M-1];
    minTime = 1000000000;
    for(int i=min; i<=max; i++){
        Bcpy=B;
        time = 0;
        flag = 0;
        for(int j=N*M-1;j>=0;j--){
            if(ground[j]>i) {
                Bcpy += ground[j]-i;
                time += (ground[j]-i)*2;
            }
            else if(ground[j]<i){
                if((i-ground[j]) > Bcpy){
                    flag=1;
                    break;
                }
                else{
                    Bcpy -= (i-ground[j]);
                    time += (i-ground[j]);
                }
            }
        }
        if(flag==1) continue;
        if(time <= minTime){
            minTime = time;
            height = i;
        }
    }
    cout << minTime << " " << height << endl;
    
    return 0;
}