#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,d,k,c;
    int max=0,cont=0,idx;
    int input;
    int i;
    cin >> N >> d >> k >> c;
    c--;
    vector <int> dish(N+k,0);
    vector <int> count(d,0);
    
    for(i=0;i<N;i++){
        cin >> dish[i];
        dish[i]--;
        if(i<k) dish[i+N] = dish[i];
    }
    for(i=0;i<k;i++){
        if(count[dish[i]]==0){
            cont++;
        }
        count[dish[i]]++;
    }

    for(;i<N+k;i++){
        if(max <= cont){
            max = cont;
            if(count[c]==0) max++;
        }
        count[dish[i-k]]--;
        if(count[dish[i-k]]==0) cont--;
        if(count[dish[i]]==0) cont++;
        count[dish[i]]++;
        
    }
    if(max <= cont){
        max = cont;
        if(count[c]==0) max++;
    }
    cout << max << "\n";
    return 0;
}