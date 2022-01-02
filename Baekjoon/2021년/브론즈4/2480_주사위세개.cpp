#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int eye1,eye2,eye3;
    cin >> eye1 >> eye2 >> eye3;
    if(eye1==eye2 && eye2==eye3){
        cout << 10000+(eye1)*1000 << "\n";
        return 0;
    }
    else if(eye1==eye2 || eye2==eye3 || eye1==eye3){
        if(eye1==eye2){
            cout << 1000 + eye1*100 << "\n";
        }
        else if(eye2==eye3){
            cout << 1000 + eye2*100 << "\n";
        }
        else{
            cout << 1000 + eye1*100 << "\n";
        }
        return 0;
    }
    else{
        eye1=max(eye1,eye2);
        eye1=max(eye1,eye3);
        cout << eye1*100 << "\n";
    }
    return 0;
}