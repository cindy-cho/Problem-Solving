#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,a;
    long long koong[70];
    cin >> t;
    koong[0] = 1; koong[1] = 1 ; koong[2] = 2; koong[3] = 4;
    for(int i=4;i<70;i++){
        koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
    }
    for(int i=0;i<t;i++){
        cin >> a;
        cout << koong[a] << "\n";
    }
    return 0;
}