#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool cmp(long long a, long long b){
    return a<b;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    int k;
    cin >> N >> k;
    vector <long long > a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    sort(a.begin(),a.end(),cmp);

    cout << a[k-1] << endl;
    return 0;
}