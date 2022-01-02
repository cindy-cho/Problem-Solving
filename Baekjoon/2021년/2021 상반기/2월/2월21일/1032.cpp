#include<iostream>
#include<string>

using namespace std;

int main(void){
    int N,i,length,j;
    char input[55];
    string list;
    string ans;

    scanf("%d\n",&N);
    
    for(i=0;i<N;i++){
        getline(cin, list);
        if(i==0) ans = list;
        else{
            for(j=0;j<ans.length();j++){
                if(ans[j]!=list[j]) ans.replace(j,1,"?");
            }
        }
    }

    cout << ans ;
    return 0;
}