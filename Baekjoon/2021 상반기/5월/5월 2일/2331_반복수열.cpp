#include<iostream>
#include<map>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map <int ,int > numbers;
    int A,P,SUM,NOW,ADD,B;
    int ANS=0,ANS2;
    cin >> A >> P;
    while(1){
        if(numbers.find(A)==numbers.end()){
            numbers.insert({A,ANS});
            ANS++;
        }
        else{
            break;
        }
        SUM=0;
        while(A!=0){
            NOW=0;
            ADD=1;
            NOW = A%10;
            A /=10;
            for(int i=0;i<P;i++){
                ADD *=NOW;
            }
            SUM += ADD;
        }
        A = SUM;
    }
    B=A;
    ANS2=0;
    while(1){
        SUM=0;
        while(A!=0){
            NOW=0;
            ADD=1;
            NOW = A%10;
            A /=10;
            for(int i=0;i<P;i++){
                ADD *=NOW;
            }
            SUM += ADD;
        }
        A = SUM;
        ANS2++;
        if(A==B)break;
    }
    cout << ANS-ANS2<< "\n";
    return 0;
}