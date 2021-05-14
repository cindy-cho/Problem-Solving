#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,a,b;
    cin >> N;
    vector<int> jump(N);
    vector<int> vst(N,0);
    for(int i=0;i<N;i++) cin >> jump[i];
    cin >> a >> b;
    a--;
    b--;
    vst[a] = 1;
    
    for(auto vs:vst) cout << vs << " ";
    cout << endl;
    
    return 0;
}