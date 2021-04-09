#include<iostream>
#include<math.h>
#include<map>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int t,i,j,k,height,targetW,carry,jari;
    long long int n;
    long long int w,boxW,tmpW,leftW;
    long long int boxCount[31];
    long long int len;
    string Win2;
    map <long long int, int> twoDic;
    w=1;
    twoDic[1]=0;
    for(i=1;i<31;i++){
        w*=2;
        twoDic[w]=i;
    }
   
    cin >> t;
    long long int boxMax;
    long long int bigBreakFlag;
    for(i=0;i<t;i++){
        Win2="";
        boxMax=0;
        for(j=0;j<31;j++) boxCount[j]=0;
        cin >> n >> w;
        for(j=0;j<n;j++){
            cin >> boxW;
            if(twoDic[boxW]>boxMax) boxMax=twoDic[boxW];
            boxCount[twoDic[boxW]]++;
        }
        while(w>0){
            if(w%2==0) Win2 =   Win2 + '0';
            else Win2 =  Win2 + '1';
            w/=2;
        }
        len = Win2.length();
        carry=1;
        bigBreakFlag=-1;
        height=0;
        // cout << Win2 << endl;
        while(n>0){
            // cout << "n: " << n << endl;
            // cout << "height : " << height << endl;
            // cout << "carry : " << carry << endl;
            carry=0;
            height++;
            for(k=len-1;k>=0;k--){
                // cout << "현재 자리 ["<<k<< "]" << Win2[k] << endl;
                
                if(Win2[k]=='1')
                {
                    // cout << "jari : " << jari << endl;
                    // cout << "carry : " << carry << endl;
                    jari = k;
                    carry = carry + 1;
                    while(carry>0 && jari>=0){
                        // cout << "boxCount[" << jari << "]" << boxCount[jari] << endl;
                        if(boxCount[jari]>=carry){
                            boxCount[jari]-=carry;
                            
                            n -= carry;
                            carry = 0;
                            // cout << "n: " << n << endl;
                            if(n<=0) {
                                bigBreakFlag=1;
                                break;
                            }
                            break;
                        }
                        else{
                            carry -=boxCount[jari];
                            n -= boxCount[jari];
                             if(n<=0) {
                                bigBreakFlag=1;
                                break;
                            }
                            boxCount[jari]= 0;
                            jari--;
                            carry*=2;
                        }
                        if(bigBreakFlag==1) break;
                    }
                    if(bigBreakFlag==1) break;
                }
                if(bigBreakFlag==1) break;
                else carry*=2;
            }
            if(bigBreakFlag==1) break;
        }
        cout << height << "\n";
    }
    return 0;
}

// 10^9
// 1 2 4 8 16 32 64 128 256 1024 2

// 2^30ㅇㅣ 더큼

// 1000000000
// 1073741824