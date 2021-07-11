#include<iostream>
#include<string>


using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string input;
    int sum=0,i,j,len;
    int count[10]={0,}; //0 1 2 3 4 5 6 7 8 9
    int flagTen=-1;
    cin >> input;
    len=input.length();
    for(i=0;i<len;i++){
        j = input[i]-'0';
        count[j]++;
        sum+=j;
        sum=sum%3;
    }
    if(count[0]!=0 && sum==0){
        for(i=9;i>=0;i--){
            for(j=0;j<count[i];j++){
                cout <<i;
            }
        }
    }
    else cout << "-1";
    cout<<"\n";

    return 0;
}