#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<int,int> arr;
    int n,a,homo=0,hetero=0;
    string command;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command >> a;
        if(arr.find(a)!=arr.end()){
            if(command=="insert"){
                arr[a]++;
                if(arr[a]==1) hetero++;
                else if(arr[a]==2) homo++;
                
            }
            else{
                if(arr[a]>0) {
                    arr[a]--;
                    if(arr[a]==1) homo--;
                    else if(arr[a]==0) hetero--;
                }
            }
        }
        else{
            if(command=="insert") {
                arr.insert({a,1});
                hetero++;
            }
        }
        if(i==0) cout << "neither\n";
        else if(homo>=1 && hetero>1) cout << "both\n";
        else if(hetero>1) cout << "hetero\n";
        else if(homo>=1) cout << "homo\n";
        else cout << "neither\n";
    }
    return 0;
}