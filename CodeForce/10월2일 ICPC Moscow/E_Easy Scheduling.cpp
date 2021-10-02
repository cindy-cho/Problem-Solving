#include<iostream>
#include<math.h>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,h,p;
    int height;
    int hh;
    ll answer;
    ll left,leftSum;
    cin >> t;
    for(int tc = 0 ; tc < t ; tc++){
        cin >> h >> p;
        height = floor(log2(p));
        h--;

        if( h <= height){
            
            cout << h + 1 << endl;
        }
        else{
            
            answer = height+1;
            hh = ll(pow(2,height+1) / p);
            left = pow(2,height+1) - (hh*p);
            leftSum = left;
            for(int i= height+1;i<=h;i++){
                answer += hh;
                if(leftSum >= p){
                    answer ++;
                    leftSum-=p;
                }
                if(i==h) break;
                hh *=2;
                left *= 2;
                if(left>=p){
                    left -= p;
                    hh++;
                }
                leftSum += left;
            }
            if (leftSum !=0) answer ++;
            cout << answer << endl;
        }
    }
    return 0;
}