#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;
int prime[10001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    
    int minPrime = 0 , sum = 0;
    prime[0]=1;
    prime[1]=1;
    cin >> M >> N;
    for(int i=2;i<=N;i++){
        if(prime[i]==0){
            for(int j=i+i;j<=N;j=j+i) prime[j]=1; 
        }
    }

    for(int i=M;i<=N;i++){
        if(prime[i]==0){
            sum+=i;
            if(minPrime==0) minPrime=i;
        }
    }
    if(sum==0) cout << "-1" << endl;
    else{
        cout << sum << endl << minPrime << endl;
    }
    
    return 0;
}