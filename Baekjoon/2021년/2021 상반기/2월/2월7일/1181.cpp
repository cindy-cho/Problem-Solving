#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int main(void){
    int N,i;
    vector<string> input;
    string name;

    scanf("%d",&N);

    for(i=0;i<N;i++){
        getline(cin, name);
        input.push_back(name);
        cout << name << endl;
    }

    return 0;
}