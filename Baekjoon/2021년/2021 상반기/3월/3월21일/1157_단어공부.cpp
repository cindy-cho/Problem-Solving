#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    string input;
    int check[26];
    cin >> input;
    for (auto in : input){
        if(in>='A' && in<='Z') in = in - 'A' + 'a';

    }
}