#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int convertNum(char A){
    char arr[5]={'T','J','Q','K','A'};
    if(A>='2' && A<='9') return A-'0';
    
    for(int i=0;i<5;i++){
        if(A==arr[i]) return i+10;
    }
    return 0;
}
bool cmp(string A, string B){
    if(A[0]==B[0]) return A[1] < B[1];
    int aa, bb;
    aa = convertNum(A[0]);
    bb = convertNum(B[0]);
    return aa<bb;
}

bool comp(string A, string B){
    if(A[1]==B[1]){
        int aa, bb;
        aa = convertNum(A[0]);
        bb = convertNum(B[0]);
        return aa<bb;
    }
    return A[1] < B[1];
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int aa,bb;
    int numMax, suitMax;
    int order[2];
    cin >> n;
    vector<string> deck(13);
    for(int i=0;i<n;i++){
        for(int j=0;j<13;j++) cin >> deck[j];
        numMax=0;
        suitMax=0;
        order[0]=-1;
        order[1]=-1;
        sort(deck.begin(),deck.end(),cmp);
        // cout << "Number Order : ";
        // for(int j=0;j<13;j++) cout << deck[j] << " ";
        // cout << endl;
        for(int j=0;j<=7;j++){
            aa = convertNum(deck[j][0]);
            bb = convertNum(deck[j+4][0]);
            if(aa+4==bb && deck[j][1] == deck[j+4][1]){
                if(order[0]==-1) order[0]=j;
                else order[1] = j;
            }
        }
        sort(deck.begin(),deck.end(),comp);
        cout << "Suit Order : ";
        for(int j=0;j<13;j++) cout << deck[j] << " ";
        cout << endl;
    }
    return 0;
}