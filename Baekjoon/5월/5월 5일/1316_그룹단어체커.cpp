#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string input;
    int check[26];
    int flag,ans=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        flag = 1;
        for(int i=0;i<26;i++) check[i]=0;
        for(int i=0;i<input.length();i++){
            if(check[input[i]-'a']==0){ //처음이면 1로 업데이트
                check[input[i]-'a']=1;
            }
            else if(input[i]!=input[i-1]){
                flag = -1;
                break;
            }
        }
        if(flag==1) ans++;
    }
    cout << ans << endl;
    return 0;
}