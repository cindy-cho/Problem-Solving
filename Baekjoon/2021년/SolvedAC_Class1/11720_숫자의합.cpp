#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string num;
    int ans=0;
    cin >> num;
    for(auto n : num){
        ans += (n-'0');
    }
    cout << ans << "\n";
    return 0;
}
