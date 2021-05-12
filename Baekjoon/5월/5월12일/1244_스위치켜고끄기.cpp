#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int stu, num;
    int s,e,i,j;
    cin >> N;
    vector<int> light(N,0);
    for(i=0;i<N;i++){
        cin >> light[i];
    }
    int M;
    cin >> M;
    for(i=0;i<M;i++){
        cin >> stu >>  num;
        if(stu==1){
            for(j=num-1;j<N;j+=num){
                if(light[j] == 0) light[j]=1;
                else light[j] = 0;
            }
        }
        else{
            s = num-1;
            e = num-1;
            while(light[s]==light[e]){
                if(s-1>=0 && e+1<N && light[s-1]==light[e+1]){
                    s--;
                    e++;
                }
                else break;
            }
            for(j=s;j<=e;j++){
                if(light[j]==0) light[j] = 1;
                else light[j] = 0;
            }
        }
    }

    for(i=0;i<N;i++) {
        cout << light[i];
        if((i+1)%20==0) cout << "\n"; 
        else cout << " ";
    }
    return 0;
}