#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double N,a,avg,freq1,freq2;
    int flag1=-1;
    int maxCnt=0;
    cin >> N;
    vector<double> arr(N);
    map <int , int > numCount;
    double sum=0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sum += arr[i];
        if(numCount.find(arr[i])!=numCount.end()){
            numCount[arr[i]] ++;
        }
        else{
            numCount.insert({arr[i],1});
        }
        if(numCount[arr[i]]>maxCnt) {
            maxCnt = numCount[arr[i]];
        }
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++){
        if(numCount[arr[i]]==maxCnt && flag1 == -1) {
            freq1 = arr[i];
            flag1 = 1;
        }
        else if(numCount[arr[i]]==maxCnt && arr[i]!=freq1 && flag1==1){
            freq2 = arr[i];
            flag1 = 2;
            break;
        }
    }
    avg = sum / N;
    cout << round(avg) << endl;
    cout << arr[N/2] << endl;
    if(flag1==1) cout << freq1 << endl;
    else cout << freq2 << endl;
    cout << arr[N-1] - arr[0] << endl;

    return 0;
}