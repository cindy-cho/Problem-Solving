#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long int N,i,len;
    string input;
    cin >> N;
    cin >> input;
    len = input.length();
    vector<long long int> dp(len,0);
    dp[0] = 1;
    if(input[1]=='1') dp[1] = 1;
    for(i=2;i<len;i++){
        if(input[i]=='0') continue;
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[len-1] << "\n";
    return 0;
}