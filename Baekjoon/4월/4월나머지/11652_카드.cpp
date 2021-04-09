#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector <long long int> card(N);
    int ans=-1,count=0,idx=0;
    for(int i=0;i<N;i++) cin >> card[i];
    if(N==1){
        cout << card[0] << endl;
        return 0;
    }
    sort(card.begin(),card.end());
    for(int i=0;i<N-1;i++){
        if(card[i]==card[i+1]){
            count++;
        }
        else{
            count++;
            if(count > ans){
                ans = count;
                idx = i;
            }
            count =0;
        }
    }

    if(card[N-2]==card[N-1]){
        count++;
        if(count>ans){
            idx = N-1;
        }
    }

    cout << card[idx] << endl;
    return 0;
}