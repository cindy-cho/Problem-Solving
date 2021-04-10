#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,val,tar,ans;
    int input[3];
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> input[0] >> input[1] >> input[2];
        if(input[0]==input[1] && input[1]==input[2]) tar = input[0];
        else if(input[0]==input[1]){
            ans = 3;
            tar = input[0];
        }
        else if(input[0]==input[2]){
            ans = 2;
            tar = input[0];
        }
        else if(input[1]==input[2]){
            ans = 1;
            tar = input[1];
        }
        for(int j=4;j<=n;j++){
            cin >> val;
            if(val!=tar) ans=j;
        }
        cout << ans << "\n";
    }
    return 0;
}