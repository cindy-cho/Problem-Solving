#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,diff,ans;
    string answer;
    char maxC,C;
    int cnt=0,now=0,total=0;
    cin >> N >> M;
    vector<string> arr(M,"" );
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> C;
            arr[j] += C;
        }
    }
    for(int i=0;i<M;i++) {
        sort(arr[i].begin(),arr[i].end());
    }
    
    for(int i=0;i<M;i++){
        C = arr[i][0];
        cnt = 0;
        now = 1;
        for(int j=1;j<N;j++){
            if(arr[i][j]!=C){
                if(now > cnt){
                    cnt = now;
                    maxC = C;
                }
                C = arr[i][j];
                now = 1;
            }
            else now++;
        }
        if(now > cnt){
            cnt = now;
            maxC=arr[i][N-1];
        }
        // cout << cnt << "\n";
        answer += maxC;
        total += (N-cnt);
    }
    cout << answer << "\n" << total << "\n";
    return 0;
}