#include<iostream>
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
    n*=2;
    int answer=200000;
    vector<int> stu(n);
    for(int i=0;i<n;i++) cin >> stu[i];
    sort(stu.begin(),stu.end());
    for(int i=0;i<n/2;i++){
        if((stu[i]+stu[n-i-1]) < answer) answer = stu[i]+stu[n-i-1];
    }
    cout << answer << endl;
    return 0;
}