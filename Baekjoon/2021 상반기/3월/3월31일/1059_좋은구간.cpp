#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int L,i,n;
    int min=1000,max=0;
    
    cin >> L;
    vector <int> S(L);
    for(i=0;i<L;i++){
        cin >> S[i];
    }
    sort(S.begin(),S.end());

    cin >> n;
    
    for(i=0;i<L-1;i++){
        if(n==S[i]) {
            cout << "0\n";
            return 0;
        }
        if(S[i]<n && S[i+1]>n)
        {   
            min = S[i];
            max= S[i+1];
        }

    }
    if(S[L-1]==n){
        cout << "0\n";
        return 0;
    }
    if(n<S[0]){
        min=0;
        max=S[0];
    }

    min++;
    max--;
    cout << (n-min+1) * (max-n+1) -1 << endl;
    
    return 0;
}


