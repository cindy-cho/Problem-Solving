#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test ;
    if(test>=90 && test<=100)  cout << "A\n";
    else if(test>=80 && test<90)  cout << "B\n";
    else if(test>=70 && test<80)  cout << "C\n";
    else if(test>=60 && test<70)  cout << "D\n";
    else cout << "F\n";
    return 0;
}