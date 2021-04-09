#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int count = 0;
    cin >> n ;
    int a = sqrt(n);
    int aleft,bleft,cleft;
    int saved[300];
    int b,c,d;
    //1인경우
    for(int i=1;i<=a;i++){
        saved[i] = i*i;
    }
    if(saved[a]==n){
        cout << "1\n";
        return 0;
    }

    //2일경우
    for(int i=a;i>=sqrt(n-saved[a-1]);i--){
        aleft = n-saved[i];
        for(int j=sqrt(aleft);j>=1;j--){
            if(saved[j]==aleft){
                cout << "2\n";
                return 0;
            }
        }
    }

    //3일 경우
    for(int i=a;i>=sqrt(n-saved[a-1]);i--){
        aleft = n-saved[i];
        int end = sqrt(aleft);
        for(int j=sqrt(aleft);j>=1;j--){
            bleft = aleft-saved[j];
            for(int m =sqrt(bleft);m>=1;m--){
                if(saved[m]==bleft){
                    cout << "3\n";
                    return 0;
                }
            }
        }
    }

    //4일 경우
    for(int i=a;i>=sqrt(n-saved[a-1]);i--){
        aleft = n-saved[i];
        int end = sqrt(aleft);
        for(int j=sqrt(aleft);j>=1;j--){
            bleft = aleft-saved[j];
            for(int m =sqrt(bleft);m>=1;m--){
                cleft = bleft -saved[m];
                for(int k=sqrt(cleft);k>=1;k--){
                    if(saved[k]==cleft){
                        cout << "4\n";
                        return 0;
                    }
                }
            }
        }
    }


    return 0;
}