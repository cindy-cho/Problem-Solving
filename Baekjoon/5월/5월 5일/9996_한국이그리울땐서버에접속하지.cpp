#include<iostream>
#include<string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    string pattern, input;
    string pre="", post="";
    int iPre,iPost,iLen,len;
    cin >> N;
    cin >> pattern;
    len=pattern.length();
    int i;
    for(i=0;i<len;i++){
        if(pattern[i]!='*') pre += pattern[i];
        else break;
    }
    i++;
    for(;i<len;i++){
        post += pattern[i];
    }
    iPre = pre.length();
    iPost = post.length();
    
    for(int i=0;i<N;i++){
        cin >> input;
        iLen = input.length();
        if(iLen < len-1) cout<<"NE\n";
        // cout << input.substr(0,iPre) << ",,," << input.substr(iLen-iPost,iPost) << endl;
        else if(pre==input.substr(0,iPre) && post==input.substr(iLen-iPost,iPost)) cout << "DA\n";
        else cout<<"NE\n";
    }
    return 0;
}