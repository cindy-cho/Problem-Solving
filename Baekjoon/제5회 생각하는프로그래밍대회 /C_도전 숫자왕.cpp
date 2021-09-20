// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #define endl '\n'
// typedef long long ll;

// using namespace std;

// vector<ll> num;
// map<ll,bool> isMake;
// ll canMake=0;
// int N;
// void combination(ll sum,int left,int depth){
//     if(left==0 || depth==N){
        
//         if(isMake.find(sum)==isMake.end() && sum!=0){
//             // cout << sum << endl;
//             isMake[sum] = true;
//             canMake++;
//         }
//         return;
//     }
//     else{
//         combination(sum,left,depth+1);
//         combination(sum+num[depth],left-1,depth+1);
//     }
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     ll M=0;
//     cin>>N;
//     num.resize(N,0);
//     for(int i=0;i<N;i++) {
//         cin >> num[i];
//         if(isMake.find(num[i])==isMake.end()){
//             isMake[num[i]] = true;
//             canMake++;
//         }
//         M+=num[i];
//     }
    

//     for(int i=0;i<N;i++){
//         combination(0,i+1,0);
//     }

//     cout << M-canMake << endl;
//     return 0;
// }


#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> num(N);
    for(int i=0;i<N;i++) cin >> num[i];
    sort(num.begin(),num.end());
    for(int i=1;i<N;i++){
        for(int j=1;j<=num[i];j++){
        }
    }
    return 0;
}