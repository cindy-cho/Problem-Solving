#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    
    cin.tie(0);

    int max=0;
    int N;
    string input;
    map <string,int> book;
    string maxAnswer="";
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        if(book.count(input)){
            book[input]++;
            if(book[input] > max) {
                maxAnswer = input;
                max = book[input];
            }
            else if(book[input]==max){
                
                if(maxAnswer > input) {
                    maxAnswer = input;
                    // cout << "chagne: " <<  input << "," << book[input] <<  endl;
                }
            }
        }
        else{
            book[input] = 1;
            if(max < 1){
                maxAnswer = input;
                max = 1;
            }
            else{
                if(max==1  && maxAnswer >input) maxAnswer =input;
            }
        }
    }
    
    cout << maxAnswer << "\n";
    return 0;
}