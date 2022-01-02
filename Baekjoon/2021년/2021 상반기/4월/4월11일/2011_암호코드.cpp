#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string passCode;
    int len;
    cin >> passCode;
    len = passCode.length();
    vector <int> arr1(len,0);
    vector <int> arr2(len,0);
    vector <long long int> ans(len,0);
    int tmp;
    for(int i=0;i<len;i++){
        if(passCode[i]>'0' && passCode[i]<='9') arr1[i]=1;
        if(i!=0){
            tmp = stoi(passCode.substr(i-1,2));
            if(tmp<=26 && tmp>=10) arr2[i]=1;
        }
    }
    for(int i=0;i<len;i++){
        if(i==0) ans[i]=arr1[i];
        else if(i==1){
            ans[i] = arr1[i]*ans[i-1] + arr2[i];
        }
        else{
            ans[i] = arr1[i]*ans[i-1] + arr2[i]*ans[i-2];
        }
        ans[i] %=1000000;
    }
    ans[len-1] %=1000000;
    cout << ans[len-1] << "\n";

    return 0;
}
