#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;
vector<int> honamsun;
int finalUp=0, finalDown=0, finalEqual=0;
int crntStage=0;
int maxAsk(int N){
    int times=0;
    while(N>1){
        N/=2;
        times++;
    }
    return times;
}

void createCase(int stage, int N){
    if(stage==N){
        crntStage++;
        int up=0,down=0;
        for(int i=0;i<N;i++) {
            if(crntStage<28 || crntStage>65500) cout << honamsun[i];
            if(i!=0){
                if(honamsun[i-1]<honamsun[i]) up++;
                else if(honamsun[i-1]>honamsun[i]) down++;
            }
        }
        if(crntStage<28 || crntStage>65500) cout << " : up is " << up << " , down is " << down;
        if(up>down) {
            if(crntStage<28 || crntStage>65500) cout << " - res : 1\n";
            finalUp++;
        }
        else if(up<down) {
            if(crntStage<28 || crntStage>65500) cout << " - res : -1\n";
            finalDown++;
        }
        else {
            if(crntStage<28 || crntStage>65500) cout << " - res : 0\n";
            finalEqual++;
        }
        return;
    }
    for(int i=0;i<=1;i++){
        honamsun[stage] = i;
        createCase(stage+1,N);
    }
    return;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int ask;
    int firstTrain,endTrain;
    cin >> N;
    cout << "? 1" << endl;
    cout << flush;
    cin >> firstTrain;
    cout << "? " << N << endl;
    cout << flush;
    cin >> endTrain;
    if(firstTrain==endTrain) cout << "! 0" << endl << flush;
    else if(firstTrain>endTrain) cout << "! -1" << endl << flush;
    else if(firstTrain<endTrain) cout << "! 1" << endl << flush;

    return 0;
}