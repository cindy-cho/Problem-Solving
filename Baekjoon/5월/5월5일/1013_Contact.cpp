#include<iostream>
#include<string>

using namespace std;

int flag;
void testString(string p){
    // cout << "input String : " << p << endl;
    if(flag==-1) return;
    int len=p.length();
    if(len==0) return;
    if(len==1){
        flag = -1;
        return;
    }
    if(len>=2){
        if(p.substr(0,2)=="01"){
            // cout << "01이어서 짤라줌\n";
            testString(p.substr(2,len-2));
            return;
        }
        else{
            if(len<4){
                // cout << "길이가 짧아서 잘라줌\n";
                flag=-1;
                return;
            }
            else if(p.substr(0,3)=="100"){
                // cout << "앞에 100 카운트함\n";
                int zeroFlag=0;
                for(int i=3;i<len;i++){
                    if(zeroFlag==0){ //아직 0000부분
                        if(p[i]=='0') continue;
                        else zeroFlag=1; //1한번 여기서 들어옴
                    }
                    else{ //zeroFlag==1이면 이제 111만 들어와야함
                        
                        if(p[i]=='1') {
                            // cout << "1에 들어옴\n";
                            // cout << i << "," << len << endl;
                            // cout << p.substr(i,3) << endl;
                            if(i+4<=len && p.substr(i,3)=="100"){
                                // cout << "dur\n";
                                testString(p.substr(i,len-i));
                                return;
                            }
                            else continue;
                        }
                        else{ //0들어오면 끊어줌
                            // cout << "0들어와서 끊어줌.\n";
                            testString(p.substr(i,len-i));
                            return;
                        }
                    }
                }
                if(zeroFlag==0){
                    flag = -1;
                    return;
                }
            }
            else{
                flag = -1;
                return;
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,len;
    cin >> T;
    string test;
    for(int i=0;i<T;i++){
        cin >> test;
        flag = 0;
        if(test.length()<2){
            cout << "NO\n";
        }
        else{
            testString(test);
            if(flag==-1) cout << "NO\n";
            else cout << "YES\n"; 
        }
    }
    return 0;
}

define 21억