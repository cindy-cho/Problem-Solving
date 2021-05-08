#include<iostream>
#include <regex>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input;
    regex re("(100+1+|01)+");
    cin >> input;
    if(regex_match(input, re)==true) cout << "SUBMARINE\n";
    else cout << "NOISE\n";
    return 0;
}