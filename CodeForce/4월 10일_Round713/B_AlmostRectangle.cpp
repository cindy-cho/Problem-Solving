#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    char val;
    pair <int,int> P1,P2,P3,P4;
    int count = 0;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        count = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin >> val;
                if(val=='*'){
                    if(count == 0){
                        P1.first = j;
                        P1.second = k;
                        count++;
                    }
                    else{
                        P2.first = j;
                        P2.second = k;
                    }
                }
            }
        }
        if(P1.first==P2.first){ //x값이 같을 때
            if(P1.first!=0){
                P3.first=P1.first-1;
                P4.first=P1.first-1;
            }
            else{
                P3.first=P1.first+1;
                P4.first=P1.first+1;
            }
            P3.second=P1.second;
            P4.second=P2.second;
        }
        else if(P1.second==P2.second){ //y값이 같을 때
            if(P1.second!=0){
                P3.second=P1.second-1;
                P4.second=P1.second-1;
            }
            else{
                P3.second=P1.second+1;
                P4.second=P1.second+1;
            }
            P3.first=P1.first;
            P4.first=P2.first;
        }
        else{ //x,y가 대각선일 때
            P3.first = P1.first;
            P3.second = P2.second;
            P4.first = P2.first;
            P4.second = P1.second;
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j==P1.first && k==P1.second) cout << "*";
                else if(j==P2.first && k==P2.second) cout << "*";
                else if(j==P3.first && k==P3.second) cout << "*";
                else if(j==P4.first && k==P4.second) cout << "*";
                else cout <<".";
            }
            cout <<"\n";
        }

    }
    return 0;
}