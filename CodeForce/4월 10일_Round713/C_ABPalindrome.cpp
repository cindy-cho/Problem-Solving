#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,a,b;
    int aC,bC;
    string input;
    int len;
    int ansFlag;
    int ans;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        cin >> input;
        len = input.length();
        ansFlag=1;
        aC=0;
        bC=0;
        if(a%2==1 && b%2==1) cout << "-1\n";
        else{
            for(int j=0;j<len;j++){
                if(input[j]=='0'){
                    if(input[len-j-1]=='1'){
                        ansFlag=-1;
                        break;
                    }
                    else if(input[len-j-1]=='?') input[len-j-1]='0';
                }
                else if(input[j]=='1'){
                    if(input[len-j-1]=='0'){
                        ansFlag=-1;
                        break;
                    }
                    else if(input[len-j-1]=='?') input[len-j-1]='1';
                }
            }
            if(ansFlag==-1){
                cout << "-1\n";
            }
            else{
                for(int j=0;j<len;j++){
                    if(input[j]=='0') aC++;
                    else if(input[j]=='1') bC++;
                }
                if(aC>a || bC>b){
                    cout << "-1\n";
                }
                else{
                    a -= aC;
                    b -= bC;
                    if(len%2==1 && input[len/2]=='?'){
                        if(a%2==1) {
                            input[len/2]='0';
                            a--;
                        }
                        else if(b%2==1){
                            input[len/2]='1';
                            b--;
                        }
                        else if(a%2==0 && b%2==0) ansFlag = -1;
                    }
                    if(a<0 || b<0 || ansFlag==-1){
                        cout<<"-1\n";
                    }
                    else{
                        for(int j=0;j<len/2;j++){
                            if(input[j]=='?'){
                                if(a>0){
                                    input[j]='0';
                                    input[len-j-1]='0';
                                    a-=2;
                                }
                                else if(b>0){
                                    input[j]='1';
                                    input[len-j-1]='1';
                                    b-=2;
                                }
                            }
                        }
                        if(a!=0 || b!=0){
                            cout << "-1\n";
                        }
                        else cout << input << "\n";
                    }
                }
            }
        }

    }
    return 0;
}