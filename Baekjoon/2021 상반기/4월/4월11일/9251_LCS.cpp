#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A,B;
    cin >> A >> B;
    int Aidx,Bidx;
    int i,j;
    int Alen=A.length(),Blen=B.length();
    int len = max(Alen,Blen);
    vector <vector <int> > DP (len+1, vector<int> (len+1,0));
    for(i=1;i<=Alen;i++){
        for(j=1;j<=Blen;j++){
            if(A[i-1]==B[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }

    cout << DP[Alen][Blen] << "\n";
    return 0;
} 