#include<iostream>
#define endl '\n'
typedef long long ll;
#include<vector>
#include<string>
#include<list>
#include<map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string prev, next;
    map<string, list<string> > dict;
    for(int i=0;i<N;i++){
        cin >> prev >> next;
    }
    return 0;
}