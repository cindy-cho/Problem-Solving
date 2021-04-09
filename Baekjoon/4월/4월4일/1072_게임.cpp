// #include<iostream>

// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     double X,Y,Z,n;
//     long long int s,e,m;
//     long long int ans;
//     int iZ,count=0;
//     cin >> X >> Y;
//     Z= Y/X*100;
//     // if(Z>=99 || X==Y){
//     //     cout << "-1\n";
//     //     return 0;
//     // }
//     // n=Y;
//     // s=1; e=(((long long int)(1)<<60));
//     // cout << e << endl;
//     // while(s<e){
//     //     m=(s+e)/2;
//     //     if((Y+m)/(X+m)*100 < (Z+1)) s=m+1;
//     //     else e=m;
//     // }
//     // if((Y+e)/(X+e)*100 >= (Z+1)) cout << e << "\n";
//     // else cout << "-1\n";

//     cout << Z << endl;
//     if((iZ*X-100*Y)/(100-iZ) <=0) cout << "-1\n";
//     else{
//         ans = (iZ*X-100*Y)/(100-iZ);
//         if( ans < (iZ*X-100*Y)/(100-iZ)){
//             ans ++;
//         }
//         cout << ans << "\n";
//     }

//     return 0;
// }

#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int X,Y,Z,n;
    long long int ans;
    long long int iZ;
    cin >> X >> Y;
    Z= Y*100/X;
    if(Z>=99) {cout << "-1\n";
    return 0;}
    if(X==Y) {cout << "-1\n";
    return 0;}
    

    ans = X*X / (100*X - 100*Y -X);

    if( ((Y+ans)*100 / (X+ans) ) >= Y*100/X +1) cout << ans << "\n";
    else cout << ans+1 << "\n";
   

    
    return 0;
}
