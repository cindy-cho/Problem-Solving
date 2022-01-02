#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,R,G,B;
    int RGB[2][3];
    int addMin;
    cin >> N;
    vector<int> DP(6,0);
    cin >> RGB[0][0] >> RGB[0][1] >> RGB[0][2];
    for(int i=1;i<N-1;i++){
        cin >> R >> G >> B;
        if(i%3==1){
            DP[0]+=R;
            DP[1]+=R;
            DP[2]+=G;
            DP[3]+=G;
            DP[4]+=B;
            DP[5]+=B;
        }
        
        else if(i%3==2){
            DP[0]+=G;
            DP[1]+=B;
            DP[2]+=R;
            DP[3]+=B;
            DP[4]+=R;
            DP[5]+=G;
        }
        else if(i%3==0){
            DP[0]+=B;
            DP[1]+=G;
            DP[2]+=B;
            DP[3]+=R;
            DP[4]+=G;
            DP[5]+=R;
        }
    }
    for(int i=0;i<6;i++){
        if(i==0 || i==1){
            addMin=min(RGB[0][1],RGB[0][2]);
            DP[i]+=addMin;
        }
        else if(i==2 || i==3){
            addMin=min(RGB[0][0],RGB[0][2]);
            DP[i]+=addMin;
        }
        else{
            addMin=min(RGB[0][1],RGB[0][0]);
            DP[i]+=addMin;
        }
    }
    if(N>=3){
        cin >> RGB[1][0] >> RGB[1][1] >> RGB[1][2];
    
    if((N-2)%3==1){
            addMin=min(RGB[1][1],RGB[1][2]);
            DP[0]+=addMin;  
            DP[1]+=addMin;  
            addMin=min(RGB[1][0],RGB[1][2]);
            DP[2]+=addMin;
            DP[3]+=addMin;
            addMin=min(RGB[1][1],RGB[1][0]);
            DP[4]+=addMin;
            DP[5]+=addMin;
        }
        
        else if((N-2)%3==2){
            addMin=min(RGB[1][1],RGB[1][2]);
            DP[2]+=addMin;  
            DP[4]+=addMin;  
            addMin=min(RGB[1][0],RGB[1][2]);
            DP[0]+=addMin;
            DP[5]+=addMin;
            addMin=min(RGB[1][1],RGB[1][0]);
            DP[1]+=addMin;
            DP[3]+=addMin;
        }
        else if((N-2)%3==0){
            addMin=min(RGB[1][1],RGB[1][2]);
            DP[3]+=addMin;  
            DP[5]+=addMin;  
            addMin=min(RGB[1][0],RGB[1][2]);
            DP[1]+=addMin;
            DP[4]+=addMin;
            addMin=min(RGB[1][1],RGB[1][0]);
            DP[0]+=addMin;
            DP[2]+=addMin;
        }
    }
    

    cout << min(DP[0], min(DP[1], min(DP[2], min(DP[3], min(DP[4], DP[5]))))) << "\n";
    return 0;
}