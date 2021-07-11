#include<iostream>
#include<string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A,B;
    string bigger, smaller;
    cin >> A >> B;
    if(A.length()>B.length()){
        bigger = A;
        smaller = B;
    }
    else{
        bigger =B;
        smaller = A;
    }
    int lenBig=bigger.length(),lenSmall=smaller.length();

    int maxLen=0, savedLen=0, currentLen=0;
    for(int i=0;i<lenSmall;i++){
        savedLen = 0;
        currentLen = 0;
        for(int j=0;j<=i;j++){
            if(bigger[j]==smaller[lenSmall-1-i+j]){
                currentLen++;
            }
            else{
                if(savedLen<currentLen) savedLen = currentLen;
                currentLen = 0;
            }
        }
        if(savedLen < currentLen) savedLen = currentLen;
        if(maxLen < savedLen) maxLen = savedLen;
    }
    for(int i=1;i<=lenBig;i++){
        savedLen = 0;
        currentLen = 0;
        for(int j= 0; j<lenSmall ; j++){
            if(i+j>=lenBig) break;
            if(bigger[i+j]==smaller[j]){
                currentLen++;
            }
            else{
                if(savedLen<currentLen) savedLen = currentLen;
                currentLen = 0;
            }
        }
        if(savedLen < currentLen) savedLen = currentLen;
        if(maxLen < savedLen) maxLen = savedLen;
    }   
    cout << maxLen << "\n";
    return 0;
}