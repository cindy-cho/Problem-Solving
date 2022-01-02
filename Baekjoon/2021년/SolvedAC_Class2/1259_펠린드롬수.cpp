#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int len,flag;
    cin >> n;
    while(n!="0"){
        len = n.length();
        flag = 1;
        for(int i=0;i<len/2;i++)
        {
            if(n[i]!=n[len-i-1]){
                flag=-1;
                break;
            }
        }
        if(flag==-1) cout << "no\n";
        else cout << "yes\n";
        cin >> n;
    }
    return 0;
}