#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    
    cin >> s;
    if(s=="0" || s=="X" || s=="_"){
        cout << "1\n";
        return 0;
    }
    int l = s.length();
    int answer = 0;
    int start=1,end=1;
    
    for(int i=1;i<l;i++) start*=10;
    int mul=start;
    end = start*10-1;
    vector<int> digit(l);
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9') digit[i] = s[i]-'0';
        else if(s[i]=='X') digit[i] = -1;
        else if(s[i]=='_') digit[i] = -2;
    }
    bool flag;
    bool isX;
    int X;
    // for(int i=0;i<l;i++) cout << digit[i] << " " ;
    // cout << endl;

    while(start%25!=0) start++;
    // cout << "start : " << start << " , end : " << end << endl;
    // cout << "length : " << l << endl;
    int tmp;
    for(int i=start;i<=end;i+=25){
        tmp = i;
        // cout << i << endl;
        isX = false;
        if(digit[0]>=0 && digit[0]<=9 &&tmp/mul> digit[0]) break;
        if(tmp/mul==digit[0] || digit[0]==-1 || digit[0]==-2) {
            flag = true;
            if(digit[0]==-1){
                isX=true;
                X = tmp/mul;
            }
        }
        else continue;
        for(int j=l-1;j>=1;j--){
            if(digit[j]==-2) {
                tmp /= 10;
                continue;
            }
            if(digit[j]>=0 && digit[j]<=9 && digit[j] == tmp%10) {
                tmp /= 10;
                continue;
            }
            if(digit[j]==-1){
                if(isX==true && X == tmp%10) {
                    tmp/=10;
                    continue;
                }
                if(isX==false){
                    isX=true;
                    X = tmp%10;
                    tmp /=10;
                    continue;
                }
            }
            flag = false;
            break;
        }
        if(flag==true) answer ++;
    }
    cout << answer << endl;
    return 0;
}