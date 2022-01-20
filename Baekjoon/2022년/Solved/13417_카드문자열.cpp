#include<iostream>
#include<vector>
#include<string>


#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        char c;
        string ans="";
        for(int j=0;j<N;j++){
            cin >> c;
            if(j==0) ans +=c;
            else{
                if(c <= ans[0]) {
                    ans = c + ans;
                }
                else ans = ans + c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}