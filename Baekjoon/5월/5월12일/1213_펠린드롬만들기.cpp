#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int alpha[26];
    int oneCount=0,idx;
    string name,eman="";
    char tmp;
    for(int i=0;i<26;i++) alpha[i] = 0;
    cin >> name;
    for(auto n : name){
        alpha[n-'A'] ++;
    }
    name = "";
    for(int i=0;i<26;i++){
        if(alpha[i]==1){
            oneCount++;
            idx = i;
        }
        else{
            while(alpha[i]-2>=0){
                if(alpha[i]==1) {
                    oneCount++;
                    idx = i;
                    break;
                }
                alpha[i]-=2;
                tmp = 'A' + i;
                name += tmp;
                eman = tmp + eman;
            }
            if(alpha[i]==1){
            oneCount++;
            idx = i;
        }
        }
    }
    if(oneCount>1) cout << "I'm Sorry Hansoo\n";
    else{
        if(oneCount==1){
            tmp = 'A' + idx;
            name = name + tmp + eman;
        }
        else name = name+eman;
        cout << name << "\n";
    }
    return 0;
}