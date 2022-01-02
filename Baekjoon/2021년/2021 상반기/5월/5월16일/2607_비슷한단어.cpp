#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string org,input,res;
    int n;
    int ans=-0,len,len2;
    int alpha[26],alp[26];
    int  flag,idx=0;
    cin >> n;
    cin >> org;
    len = org.length();
    for(int i=0;i<26;i++) alpha[i]=0;
    for(auto o:org) alpha[o-'A']++;
    for(int i=1;i<n;i++){
        cin >> input;
        len2 = input.length();
        if(abs(len2-len)>=2) continue;
        if(input == org){
            ans++;
            continue;
        }
        flag = 0;
        for(int j=0;j<26;j++) alp[j]=0;
        for(auto in:input) alp[in-'A']++;
        for(int j=0;j<26;j++){
            if(abs(alp[j]-alpha[j])>=2){
                flag = 3;
                break;
            }
            flag += abs(alp[j]-alpha[j]);
        }
        if(flag<=2) {
            
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}