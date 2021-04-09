#include<iostream>

using namespace std;

int saved[51];

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<51;i++) saved[i]=0;
    saved[0]=1;
    saved[1]=1;
    int n;
    cin >> n ;
    if(n==0 || n==1) {
        cout << "1\n";
        return 0;
    }
    for(int i=2;i<n+1;i++){
        saved[i] = (saved[i-1] + saved[i-2]+1) % 1000000007;
    }

   
   cout << saved[n] << "\n";

    return 0;
}

//1 2 3 4 5 6 7
//1 1 2 3 5 8 13
//1 3 5 9 15 25 41f