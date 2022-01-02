// ---------- TRY 1 ------------
// #include<iostream>

// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, arr[100000], dp[100000];
//     double maxSum=-(1<<20);
//     cin >> n;
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//         if(i==0) dp[i] = arr[i];
//         else{
//             if(dp[i-1]+arr[i] > arr[i]) dp[i] = dp[i-1]+arr[i];
//             else dp[i] = arr[i];
//         }
//         if(dp[i]>maxSum) maxSum = dp[i];
//     }

//     cout << maxSum << "\n";
    
//     return 0;
// }

// ---------- TRY 2 ------------
#include<iostream>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, inputX, dpX1, dpX2;
    double maxSum=-(1<<20);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> inputX;
        if(i==0) dpX2 = inputX;
        else{
            if(dpX1+inputX > inputX) dpX2 = dpX1+inputX;
            else dpX2 = inputX;
        }
        if(dpX2>maxSum) maxSum = dpX2;
        dpX1 = dpX2;
    }

    cout << maxSum << "\n";
    
    return 0;
}