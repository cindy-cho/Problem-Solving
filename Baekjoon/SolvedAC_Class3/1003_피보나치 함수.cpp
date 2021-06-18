#include<iostream>
#define endl '\n'
typedef long long ll;

using namespace std;

// int fibonacci (int n) {
//     if (n==0) {
//         zero++;
//         return 0;
//     }
//     else if(n==1){
//         one++;
//         return 1;
//     }
//     else{
//         return fibonacci(n-1) + fibonacci(n-2);
//     }
// }

int main(void){
    ios_base::sync_with_stdio(0);
    long long zero[41]={1,0,1,1,2,3,5},one[41]={0,1,1,2,3,5,8};

    cin.tie(0);
    int T, N;
    cin >> T;
    for(int i=7;i<41;i++) {
        zero[i] = zero[i-1]+zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    for(int i=0;i<T;i++){
        cin >> N;
        cout << zero[N] << " " << one[N] << endl;
    }
    return 0;
}
