#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

string text;
int cursor=0;

void command_L();
void command_D();
void command_B();
void command_P();

int main(void){

    getline(cin, text);

    int M,i;
    char command;

    scanf("%d",&M);

    for(i=0;i<M;i++){
        scanf("%c",&command);
        cursor = command.size();
        if(command=='L') command_L();
        else if(command=='D') command_D();
        else if(command=='B') command_B();
        else if(command=='P') command_P();
    }

    return 0;
}