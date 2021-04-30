#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int W,H,N,A,B;
    int X,Y;
    int tmp,total;
    cin >> W  >> H >> N;
    int ANS=0;
    vector<pair<int,int>> store(N);
    for(int i=0;i<N;i++){
        cin>> A >> B;
        if(A==1 || A==2){
            if(A==1)store[i].second = 0;
            else store[i].second = H;
            store[i].first = B;
        } 
        else{
            if(A==3) store[i].first = 0;
            else store[i].first = W;
            store[i].second = B; 
        }
    }
    cin >> X >> Y;
    if(X==1){
        X = Y;
        Y = 0;
    }
    else if(X==2){
        X = Y;
        Y = H;
    }
    else if(X==3){
        X = 0;
    }
    else{
        X = W;
    }

    total = 2*(H+W);
    for(int i=0;i<N;i++){
        if(abs(X-store[i].first)==W){
            tmp = Y + store[i].second + W;
        }
        else if(abs(Y-store[i].second)==H){
            tmp = X + store[i].first + H;
        }
        else{
            tmp = abs(X-store[i].first)+abs(Y-store[i].second);
        }
        ANS += min(tmp,total-tmp);
    }
    cout << ANS << "\n";
    return 0;
}