#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int ans=0;
    int currentWeight;
    vector <int> Weight(10000,0);
    int val;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> val;
        Weight[val-1]++;
    }
    for(int i=0;i<10000;i++){
        if(Weight[i]!=0){
            currentWeight = (i+1) * N;
            if( ans < currentWeight ) ans = currentWeight;
            N -= Weight[i];
        }
    }

    cout << ans ; 
    
    return 0;
}