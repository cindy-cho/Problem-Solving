#include<iostream>
#include<string>
#include<list>
#include<iterator>

using namespace std;

int main(void){
    int N,i;
    char op[4]={'L','D','B','P'};
    list<char> data;
    list<char>::iterator cursor = data.end();
    
    string input,operand;
    
    getline(cin,input);

    for(i=0;i<input.length();i++) data.push_back(input[i]);

    scanf("%d\n",&N);
    for(i=0;i<N;i++){
       
        getline(cin,operand);
       
        if(operand[0] == op[0]) {
            if(cursor!=data.begin()) cursor --;
        }
        else if(operand[0] == op[1]) {
            if(cursor!=data.end()) cursor++;
        }
        else if(operand[0] == op[2]){
            if(cursor!=data.begin()){
                cursor = data.erase(--cursor);
            }
        }
        else if(operand[0] == op[3]){
            data.insert(cursor,operand[2]);
        }
    }

    for(cursor=data.begin();cursor!=data.end();cursor++) cout << *cursor;
    cout << endl;


    return 0;
}