#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

//같은 위치, 같은 숫자 - 스트라이크
//         같은 숫자 - 볼
int main(void){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int ans = 0;
    int nums[9][9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int k=0;k<9;k++){
                nums[i][j][k] = 0;
            }
        }
    }
    int N;
    int num, st, ba;
    int tmpSt, tmpBa;
    int a,b,c;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num >> st >> ba;
        a = num/100;
        b = (num%100)/10;
        c = num%10;
        for(int m=1;m<=9;m++){
            for(int l=1;l<=9;l++){
                for(int k=1;k<=9;k++){
                    if(m==l || l==k || k==m) nums[m-1][l-1][k-1]=0;
                    else{
                        tmpSt=0;
                        tmpBa=0;
                        if(m==a) tmpSt++;
                        else if(m==b || m==c) tmpBa++;
                        if()
                        if(tmpSt==st && tmpBa==ba){
                            nums[m-1][l-1][k-1]=1;
                        }
                        else nums[m-1][l-1][k-1]=0;
                    }
                }
            }
        }
    }

    for(int m=1;m<=9;m++){
        for(int l=1;l<=9;l++){
            for(int k=1;k<=9;k++){
                if(nums[m-1][l-1][k-1]==1) ans++;
            }
        }
    }

  
    cout << ans << endl;
    return 0;
}
