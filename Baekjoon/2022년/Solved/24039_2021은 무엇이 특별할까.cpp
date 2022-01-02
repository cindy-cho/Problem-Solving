#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;
vector<int> prime;
void findPrime(){
    prime.push_back(2);
    int primeTotal = 1;
    for(int i=3;i<=1000;i+=2){
        bool flag = true;
        for(int j=0;j<primeTotal;j++){
            if(i%prime[j]==0){
                flag=false;
                break;
            }
        }
        if(flag==true){
            prime.push_back(i);
            primeTotal++;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    findPrime();
    int primeMax = prime.size();
    for(int i=0;i<primeMax-1;i++){
        if(prime[i]*prime[i+1] > N) {
            cout << prime[i] * prime[i+1];
            break;
        }
    }

    return 0;
}