#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    char tile[100][100];
    int answer=0;
    bool connected;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) {
            cin >> tile[i][j];
        }
    }
    for(int i=0;i<N;i++){
        connected = false;
        for(int j=0;j<M;j++){
            if(tile[i][j]=='-'){
                connected = true;
            }
            else{
                if(connected==true) answer++;
                connected=false;
            }
        }
        if(connected==true) answer++;
    }
    
    for(int j=0;j<M;j++){
        connected=false;
        for(int i=0;i<N;i++){
            if(tile[i][j]=='|'){
                connected = true;
            }
            else{
                if(connected==true) answer++;
                connected=false;
            }
        }
        if(connected==true) answer++;
    }

    cout << answer << endl;


    return 0;
}