#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int a,b,k;
    ll answer,addPair;
    while(t--){
        answer = 0;
        
        cin >> a >> b >> k;
        vector<pair<int,int>> person(k);
        vector<int> boyIdx(a+1,0);
        map<pair<int,int>,bool> girl;
        for(int i=0;i<k;i++) {
            cin >> person[i].first;
            boyIdx[person[i].first-1] ++;
        }
        for(int i=0;i<k;i++) {
            cin >> person[i].second;
            girl.insert({{person[i].first,person[i].second},true});
        }
        if(k<2) cout << "0 " << endl;
        else{
            cout << answer << endl;
        }
    }
    return 0;
}