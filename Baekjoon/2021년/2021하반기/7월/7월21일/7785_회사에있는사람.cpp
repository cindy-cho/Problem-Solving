#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<string> log;
    string name,status;
    for(int i=0;i<n;i++){
        cin >> name >> status;
        if(status=="enter") log.insert(name);
        else log.erase(name);
    }
    for(auto iter = log.rbegin();iter!=log.rend();iter++) cout << *iter << endl;
    return 0;
}