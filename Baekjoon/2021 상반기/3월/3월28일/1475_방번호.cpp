#include<iostream>
#include<string>

#include<vector>
#include <algorithm>
using namespace std;

bool cmp(pair <int,int> a, pair <int,int> b){
    return a.second > b.second;
}
int main(void){
    string N;
    int i,max=0;
    int idx;
    vector <pair <int,int> > list(9);
    for(i=0;i<10;i++){
        list.push_back(make_pair(i,0));
    }
    cin >> N;
    for(i=0;i<N.length();i++){
        if(N[i]=='6')N[i]='9';
        idx = N[i]-'0';
        list[idx].second ++;
    }

    list[9].second = list[9].second /2 + list[9].second %2;
    
    sort(list.begin(),list.end(),cmp);
    cout << list[0].second << "\n";
   
    return 0;
}