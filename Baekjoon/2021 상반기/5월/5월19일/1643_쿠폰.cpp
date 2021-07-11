#include<iostream>
#include<numeric>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N,iLcm,R,D;
    long long TOP;
    long long Rlen,Rcpy,iLcmLen,iLcmCpy;
    while(cin >> N){
        if(N==1) cout << 1 << " \n";
        else if(N==2) cout << 3 << "\n";
        else{
            iLcm = 1;
            TOP = 0;
            R = 1+N;
            for(int i=2;i<N;i++) iLcm = lcm(iLcm,i);
            for(int i=2;i<N;i++) TOP += N*(iLcm/i);
            D = gcd(iLcm,TOP);
            if(D!=1){
                iLcm/=D;
                TOP/=D;
            }
            R += TOP/iLcm;
            TOP = TOP%iLcm;
            Rlen = 0;
            Rcpy=R;
            while(Rcpy>0){
                Rcpy/=10;
                Rlen++;
            }
            iLcmLen=0;
            iLcmCpy=iLcm;
            while(iLcmCpy>0){
                iLcmCpy/=10;
                iLcmLen++;
            }
            // cout << "R : " << R << ", Rlen : " << Rlen << endl;
            if(TOP==0){
                cout << R << "\n";
            }
            else{
                for(int i=0;i<=Rlen;i++) cout <<" ";
                cout << TOP << "\n";
                cout << R << " ";
                for(int i=0;i<iLcmLen;i++) cout << "-";
                cout<<"\n";
                for(int i=0;i<=Rlen;i++) cout <<" ";
                cout << iLcm << "\n";
            }
        }
    }
    return 0;
}