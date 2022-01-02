#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

typedef struct{
    int nation;
    int gold;
    int silver;
    int copper;
}Rank;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,K,i;
    int cont=0,answer=1;
    Rank target;
    cin >> N >> K;

    vector<Rank> input(N);
    
    for(int i=0;i<N;i++){
        cin >> input[i].nation >> input[i].gold >> input[i].silver >> input[i].copper;
        if(input[i].nation == K){
            target.nation = K;
            target.gold = input[i].gold;
            target.silver = input[i].silver;
            target.copper = input[i].copper;
        }
    }

    for(i=0;i<N;i++){
        if(input[i].gold>target.gold) answer++;
        else if(input[i].gold==target.gold && input[i].silver>target.silver) answer++;
        else if(input[i].gold==target.gold && input[i].silver==target.silver && input[i].copper>target.copper) answer++;
    }
    cout << answer << endl;
    return 0;
}